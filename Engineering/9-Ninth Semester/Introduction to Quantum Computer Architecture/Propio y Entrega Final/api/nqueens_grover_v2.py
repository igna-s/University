"""
N-reinas cuántico vía Grover — V2: Arquitectura con Acumulador Aritmético.

Mejora sobre V1:
    - En vez de 1 flag-qubit por cada par de reinas (C(N,2) qubits),
      usa UN SOLO qubit scratch + un acumulador binario de ceil(log2(max_conflicts+1)) bits.
    - Ahorro masivo de qubits: 88% menos para N=100 (714 vs 5750).
    - La detección de conflictos sigue siendo enumerativa (match_pattern),
      así que la profundidad del circuito es comparable a V1.

Codificación: idéntica a V1.
    - Reina i en fila i (elimina restricciones de fila).
    - Columna codificada en k = ceil(log2(N)) qubits binarios.

Generalizado para cualquier N >= 2.
"""

import sys, io
if sys.stdout.encoding and sys.stdout.encoding.lower() != 'utf-8':
    sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')

import numpy as np
from itertools import combinations, permutations
from math import pi, ceil, log2, asin, sqrt

from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister, transpile
from qiskit_aer import AerSimulator


# ---------------------------------------------------------------------------
# Utilidades
# ---------------------------------------------------------------------------

def classical_solutions(N):
    sols = []
    for perm in permutations(range(N)):
        ok = True
        for i, j in combinations(range(N), 2):
            if abs(perm[i] - perm[j]) == j - i:
                ok = False
                break
        if ok:
            sols.append(list(perm))
    return sols


def decode(bitstring, N, k):
    bits = bitstring[::-1]
    queens = []
    for i in range(N):
        col = 0
        for b in range(k):
            if bits[i * k + b] == "1":
                col |= 1 << b
        queens.append(col)
    return queens


def is_valid(queens, N):
    if any(c < 0 or c >= N for c in queens):
        return False
    for i, j in combinations(range(N), 2):
        if queens[i] == queens[j] or abs(queens[i] - queens[j]) == j - i:
            return False
    return True


def print_board(queens, N):
    for i in range(N):
        line = "    "
        for c in range(N):
            line += "Q " if queens[i] == c else ". "
        print(line)


# ---------------------------------------------------------------------------
# Detección de conflictos (generalizada a cualquier k)
# ---------------------------------------------------------------------------

def add_conflict_detection(qc, q_i, q_j, k, d, scratch, N):
    """Voltea scratch si (col_i, col_j) están en conflicto (misma col o diagonal).
    Solo itera sobre columnas válidas [0, N)."""
    valid_cols = min(2**k, N)
    for ci in range(valid_cols):
        for cj in range(valid_cols):
            if ci == cj or abs(ci - cj) == d:
                x_flips = []
                for b in range(k):
                    if (ci >> b) & 1 == 0:
                        x_flips.append(q_i[b])
                    if (cj >> b) & 1 == 0:
                        x_flips.append(q_j[b])
                if x_flips:
                    qc.x(x_flips)
                qc.mcx(q_i + q_j, scratch)
                if x_flips:
                    qc.x(x_flips)


def add_range_conflict(qc, q_col, k, N, scratch):
    """Voltea scratch si el registro de columna codifica un valor >= N."""
    for bad in range(N, 2**k):
        x_flips = []
        for b in range(k):
            if (bad >> b) & 1 == 0:
                x_flips.append(q_col[b])
        if x_flips:
            qc.x(x_flips)
        qc.mcx(list(q_col), scratch)
        if x_flips:
            qc.x(x_flips)


# ---------------------------------------------------------------------------
# Acumulador aritmético (generalizado a cualquier k_acc)
# ---------------------------------------------------------------------------

def add_1_controlled(qc, flag, acc):
    """Incrementa el acumulador en 1, controlado por flag.
    Implementa un ripple-carry increment de MSB a LSB."""
    k_acc = len(acc)
    for i in range(k_acc - 1, -1, -1):
        controls = [flag] + [acc[j] for j in range(i)]
        if len(controls) == 1:
            qc.cx(flag, acc[0])
        elif len(controls) == 2:
            qc.ccx(controls[0], controls[1], acc[i])
        else:
            qc.mcx(controls, acc[i])


def uncompute_add_1_controlled(qc, flag, acc):
    """Deshace el incremento controlado (orden inverso)."""
    k_acc = len(acc)
    for i in range(k_acc):
        controls = [flag] + [acc[j] for j in range(i)]
        if len(controls) == 1:
            qc.cx(flag, acc[0])
        elif len(controls) == 2:
            qc.ccx(controls[0], controls[1], acc[i])
        else:
            qc.mcx(controls, acc[i])


# ---------------------------------------------------------------------------
# Oráculo con acumulador
# ---------------------------------------------------------------------------

def build_arithmetic_oracle(N):
    """Oráculo Grover V2: usa acumulador en vez de flags individuales."""
    k = max(1, ceil(log2(N)))
    n_state = N * k
    needs_range = (2**k) > N

    # Máximo de conflictos posibles: C(N,2) pares + N reinas fuera de rango
    max_conflicts = N * (N - 1) // 2 + (N if needs_range else 0)
    k_acc = max(1, ceil(log2(max_conflicts + 1)))

    state_reg = QuantumRegister(n_state, "q")
    acc_reg = QuantumRegister(k_acc, "acc")
    scratch = QuantumRegister(1, "scratch")

    qc = QuantumCircuit(state_reg, acc_reg, scratch, name="Arithmetic_Oracle")

    # --- COMPUTE: detectar conflictos de pares y sumar al acumulador ---
    for i, j in combinations(range(N), 2):
        d = j - i
        q_i = [state_reg[i * k + b] for b in range(k)]
        q_j = [state_reg[j * k + b] for b in range(k)]
        add_conflict_detection(qc, q_i, q_j, k, d, scratch[0], N)
        add_1_controlled(qc, scratch[0], acc_reg)
        add_conflict_detection(qc, q_i, q_j, k, d, scratch[0], N)  # uncompute scratch

    # --- COMPUTE: detectar columnas fuera de rango ---
    if needs_range:
        for i in range(N):
            q_col = [state_reg[i * k + b] for b in range(k)]
            add_range_conflict(qc, q_col, k, N, scratch[0])
            add_1_controlled(qc, scratch[0], acc_reg)
            add_range_conflict(qc, q_col, k, N, scratch[0])  # uncompute scratch

    # --- PHASE FLIP: fase -1 si acumulador == 0 (todos los flags sin conflicto) ---
    all_acc = list(acc_reg)
    qc.x(all_acc)
    qc.h(all_acc[-1])
    qc.mcx(all_acc[:-1], all_acc[-1])
    qc.h(all_acc[-1])
    qc.x(all_acc)

    # --- UNCOMPUTE: deshacer acumulador en orden inverso ---
    if needs_range:
        for i in reversed(range(N)):
            q_col = [state_reg[i * k + b] for b in range(k)]
            add_range_conflict(qc, q_col, k, N, scratch[0])
            uncompute_add_1_controlled(qc, scratch[0], acc_reg)
            add_range_conflict(qc, q_col, k, N, scratch[0])

    for i, j in reversed(list(combinations(range(N), 2))):
        d = j - i
        q_i = [state_reg[i * k + b] for b in range(k)]
        q_j = [state_reg[j * k + b] for b in range(k)]
        add_conflict_detection(qc, q_i, q_j, k, d, scratch[0], N)
        uncompute_add_1_controlled(qc, scratch[0], acc_reg)
        add_conflict_detection(qc, q_i, q_j, k, d, scratch[0], N)

    return qc, state_reg, acc_reg, scratch, k, k_acc, needs_range


# ---------------------------------------------------------------------------
# Difusor
# ---------------------------------------------------------------------------

def diffuser(n_state):
    qc = QuantumCircuit(n_state, name="Diff")
    qc.h(range(n_state))
    qc.x(range(n_state))
    qc.h(n_state - 1)
    qc.mcx(list(range(n_state - 1)), n_state - 1)
    qc.h(n_state - 1)
    qc.x(range(n_state))
    qc.h(range(n_state))
    return qc


# ---------------------------------------------------------------------------
# Validación del oráculo (sin Grover completo)
# ---------------------------------------------------------------------------

def validate_oracle_v2(N, columns):
    """Prepara |columns>, aplica solo compute, mide acumulador.
    Retorna 0 si es válida (acumulador = 0)."""
    k = max(1, ceil(log2(N)))
    n_state = N * k
    needs_range = (2**k) > N
    max_conflicts = N * (N - 1) // 2 + (N if needs_range else 0)
    k_acc = max(1, ceil(log2(max_conflicts + 1)))

    state_reg = QuantumRegister(n_state, "q")
    acc_reg = QuantumRegister(k_acc, "acc")
    scratch = QuantumRegister(1, "scratch")
    creg = ClassicalRegister(k_acc + 1, "c")  # acc + scratch

    qc = QuantumCircuit(state_reg, acc_reg, scratch, creg)

    # Preparar |columns>
    for i, col in enumerate(columns):
        for b in range(k):
            if (col >> b) & 1:
                qc.x(state_reg[i * k + b])

    # Compute (sin phase flip, sin uncompute)
    for i, j in combinations(range(N), 2):
        d = j - i
        q_i = [state_reg[i * k + b] for b in range(k)]
        q_j = [state_reg[j * k + b] for b in range(k)]
        add_conflict_detection(qc, q_i, q_j, k, d, scratch[0], N)
        add_1_controlled(qc, scratch[0], acc_reg)
        add_conflict_detection(qc, q_i, q_j, k, d, scratch[0], N)

    if needs_range:
        for i in range(N):
            q_col = [state_reg[i * k + b] for b in range(k)]
            add_range_conflict(qc, q_col, k, N, scratch[0])
            add_1_controlled(qc, scratch[0], acc_reg)
            add_range_conflict(qc, q_col, k, N, scratch[0])

    # Medir acumulador y scratch
    qc.measure(list(acc_reg) + [scratch[0]], creg)

    sim = AerSimulator(method="matrix_product_state")
    qc_t = transpile(qc, basis_gates=["u", "cx", "h", "x", "ccx"], optimization_level=1)
    result = sim.run(qc_t, shots=1).result()
    bitstring = list(result.get_counts().keys())[0]
    return bitstring.count("1"), bitstring


# ---------------------------------------------------------------------------
# Pipeline completo
# ---------------------------------------------------------------------------

def run_grover_v2(N, shots=4096, iters_override=None):
    k = max(1, ceil(log2(N)))
    n_state = N * k
    total_states = 2 ** n_state
    n_sols = len(classical_solutions(N))

    if iters_override is not None:
        iters = iters_override
    else:
        theta = 2 * asin(sqrt(n_sols / total_states))
        iters = max(1, int(round(pi / (2 * theta) - 0.5)))

    oracle, state_reg, acc_reg, scratch, k, k_acc, needs_range = build_arithmetic_oracle(N)
    creg = ClassicalRegister(n_state, "c")
    qc = QuantumCircuit(state_reg, acc_reg, scratch, creg)

    qc.h(state_reg)
    diff = diffuser(n_state)
    for _ in range(iters):
        qc.compose(oracle, inplace=True)
        qc.compose(diff, qubits=state_reg, inplace=True)
    qc.measure(state_reg, creg)

    method = "matrix_product_state" if N >= 5 else "statevector"
    sim = AerSimulator(method=method)
    qc_t = transpile(qc, basis_gates=["u", "cx", "h", "x", "ccx"], optimization_level=1)

    info = {
        "N": N,
        "k": k,
        "k_acc": k_acc,
        "needs_range": needs_range,
        "n_state_qubits": n_state,
        "n_acc_qubits": k_acc,
        "n_scratch_qubits": 1,
        "total_states": total_states,
        "n_solutions": n_sols,
        "iterations": iters,
        "circuit_depth": qc_t.depth(),
        "total_qubits": qc.num_qubits,
    }

    result = sim.run(qc_t, shots=shots).result()
    counts = result.get_counts()
    return counts, info, k


def pretty_report_v2(N, counts, info, k, top=15):
    print(f"\n{'='*60}")
    print(f"  N = {N} (Arquitectura V2 - Acumulador Aritmético)")
    print(f"{'='*60}")
    print(f"  qubits estado  : {info['n_state_qubits']}  ({info['k']} bits/columna)")
    print(f"  qubits contador: {info['n_acc_qubits']} (Acumulador)")
    print(f"  qubits scratch : {info['n_scratch_qubits']}")
    print(f"  qubits totales : {info['total_qubits']}")
    print(f"  flags rango    : {'Sí' if info['needs_range'] else 'No'}")
    print(f"  espacio        : {info['total_states']}")
    print(f"  soluciones     : {info['n_solutions']}")
    print(f"  iteraciones    : {info['iterations']}")
    print(f"  profundidad    : {info['circuit_depth']}")

    sorted_counts = sorted(counts.items(), key=lambda x: -x[1])
    total = sum(counts.values())
    valid_count = 0
    unique_sols = set()

    print(f"\n  Top {top} mediciones:")
    for bs, c in sorted_counts[:top]:
        queens = decode(bs, N, k)
        ok = is_valid(queens, N)
        mark = "OK " if ok else "X  "
        print(f"    {mark} cols={queens}  count={c}  p={c/total:.3f}")

    for bs, c in counts.items():
        q = decode(bs, N, k)
        if is_valid(q, N):
            valid_count += c
            unique_sols.add(tuple(q))

    print(f"\n  P(medir solución válida) = {valid_count/total:.1%}")
    print(f"  Soluciones únicas medidas: {len(unique_sols)} / {info['n_solutions']}")

    print("\n  Tableros (de mayor a menor frecuencia):")
    sol_freq = {}
    for bs, c in counts.items():
        q = tuple(decode(bs, N, k))
        if is_valid(list(q), N):
            sol_freq[q] = sol_freq.get(q, 0) + c
    for sol, c in sorted(sol_freq.items(), key=lambda x: -x[1]):
        print(f"\n    cols={list(sol)}  count={c}")
        print_board(list(sol), N)


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

if __name__ == "__main__":
    # --- N = 4: Grover completo ---
    counts, info, k = run_grover_v2(4, shots=4096)
    pretty_report_v2(4, counts, info, k)

    # --- N = 5: validación del oráculo ---
    print(f"\n{'='*60}")
    print(f"  N = 5  |  validación del oráculo (V2)")
    print(f"{'='*60}")
    sols = classical_solutions(5)
    print(f"\n  Soluciones clásicas: {len(sols)} en total.")
    print(f"  Probamos que el oráculo da acumulador=0 en TODAS ellas:\n")
    n_ok = 0
    for s in sols:
        n_conflicts, bs = validate_oracle_v2(5, s)
        ok = n_conflicts == 0
        n_ok += ok
        mark = "OK " if ok else "FAIL"
        print(f"    {mark}  cols={s}  bits='{bs}'")
    print(f"\n  -> {n_ok}/{len(sols)} soluciones aceptadas correctamente")

    print(f"\n  Casos negativos (deben dar acumulador > 0):\n")
    bads = [
        ([0, 0, 0, 0, 0], "todas misma columna"),
        ([0, 1, 2, 3, 4], "diagonal principal"),
        ([0, 2, 4, 1, 7], "col 7 fuera de rango"),
        ([1, 3, 5, 0, 2], "col 5 fuera de rango"),
    ]
    for s, desc in bads:
        n_conflicts, bs = validate_oracle_v2(5, s)
        ok = n_conflicts > 0
        mark = "OK " if ok else "FAIL"
        print(f"    {mark}  cols={s}  ({desc})  -> {n_conflicts} bits activos")

    # --- Comparación de recursos ---
    print(f"\n{'='*60}")
    print(f"  Comparación de recursos V1 vs V2")
    print(f"{'='*60}")
    for n in [4, 5, 6, 8]:
        k = max(1, ceil(log2(n)))
        n_state = n * k
        n_pairs = n * (n-1) // 2
        needs_range = (2**k) > n
        # V1
        v1_q = n_state + n_pairs + (n if needs_range else 0)
        # V2
        max_c = n_pairs + (n if needs_range else 0)
        k_acc = max(1, ceil(log2(max_c + 1)))
        v2_q = n_state + k_acc + 1
        savings = 100 * (v1_q - v2_q) / v1_q
        print(f"  N={n}: V1={v1_q} qubits, V2={v2_q} qubits (ahorro {savings:.0f}%)")
