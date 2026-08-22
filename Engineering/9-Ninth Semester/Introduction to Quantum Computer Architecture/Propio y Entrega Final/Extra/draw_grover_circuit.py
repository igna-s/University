"""
Dibuja el circuito de Grover N=4 como imagen:
  - Circuito completo (nivel lógico): H + (Oracle + Diffuser) x iters + Measure
  - Se guarda en grover_circuit.png
"""

import sys, io
if sys.stdout.encoding and sys.stdout.encoding.lower() != 'utf-8':
    sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')

import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

from math import ceil, log2, sqrt, asin, pi
from itertools import combinations

from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister
from qiskit_aer import AerSimulator

# ── Reproducir la misma lógica que nqueens_grover.py ──────────────────────────

def queen_qubits(state_reg, i, k):
    return [state_reg[i * k + b] for b in range(k)]

def apply_match_pattern(qc, qubits, value, k):
    for b in range(k):
        if (value >> b) & 1 == 0:
            qc.x(qubits[b])

def mark_pair_conflict(qc, q_i, q_j, k, d_rows, flag, N):
    valid_cols = min(2**k, N)
    for ci in range(valid_cols):
        for cj in range(valid_cols):
            if ci == cj or abs(ci - cj) == d_rows:
                apply_match_pattern(qc, q_i, ci, k)
                apply_match_pattern(qc, q_j, cj, k)
                qc.mcx(q_i + q_j, flag)
                apply_match_pattern(qc, q_i, ci, k)
                apply_match_pattern(qc, q_j, cj, k)

def mark_out_of_range(qc, q_col, k, N, flag):
    for bad in range(N, 2**k):
        apply_match_pattern(qc, q_col, bad, k)
        qc.mcx(q_col, flag)
        apply_match_pattern(qc, q_col, bad, k)

def build_oracle(N):
    k = max(1, ceil(log2(N)))
    n_state = N * k
    pair_count = N * (N - 1) // 2
    needs_range = (2**k) > N

    state_reg  = QuantumRegister(n_state,    "q")
    pair_flags = QuantumRegister(pair_count, "pf")
    regs = [state_reg, pair_flags]
    range_flags = None
    if needs_range:
        range_flags = QuantumRegister(N, "rf")
        regs.append(range_flags)

    qc = QuantumCircuit(*regs, name="Oráculo")

    for idx, (i, j) in enumerate(combinations(range(N), 2)):
        mark_pair_conflict(qc, queen_qubits(state_reg, i, k),
                           queen_qubits(state_reg, j, k),
                           k, j - i, pair_flags[idx], N)
    if needs_range:
        for i in range(N):
            mark_out_of_range(qc, queen_qubits(state_reg, i, k), k, N, range_flags[i])

    all_flags = list(pair_flags) + (list(range_flags) if needs_range else [])
    qc.x(all_flags)
    qc.h(all_flags[-1])
    qc.mcx(all_flags[:-1], all_flags[-1])
    qc.h(all_flags[-1])
    qc.x(all_flags)

    if needs_range:
        for i in reversed(range(N)):
            mark_out_of_range(qc, queen_qubits(state_reg, i, k), k, N, range_flags[i])
    for idx, (i, j) in reversed(list(enumerate(combinations(range(N), 2)))):
        mark_pair_conflict(qc, queen_qubits(state_reg, i, k),
                           queen_qubits(state_reg, j, k),
                           k, j - i, pair_flags[idx], N)

    return qc, state_reg, pair_flags, range_flags

def diffuser(n_state):
    qc = QuantumCircuit(n_state, name="Difusor")
    qc.h(range(n_state))
    qc.x(range(n_state))
    qc.h(n_state - 1)
    qc.mcx(list(range(n_state - 1)), n_state - 1)
    qc.h(n_state - 1)
    qc.x(range(n_state))
    qc.h(range(n_state))
    return qc

def classical_solutions(N):
    from itertools import permutations
    sols = []
    for perm in permutations(range(N)):
        ok = all(abs(perm[i] - perm[j]) != j - i
                 for i, j in combinations(range(N), 2))
        if ok:
            sols.append(list(perm))
    return sols

# ── Construir el circuito lógico ───────────────────────────────────────────────

N = 4
k = max(1, ceil(log2(N)))
n_state = N * k
n_sols  = len(classical_solutions(N))
total   = 2 ** n_state
theta   = 2 * asin(sqrt(n_sols / total))
iters   = max(1, int(round(pi / (2 * theta) - 0.5)))

oracle, state_reg, pair_flags, range_flags = build_oracle(N)
full_regs = [state_reg, pair_flags]
if range_flags is not None:
    full_regs.append(range_flags)

creg = ClassicalRegister(n_state, "c")
qc   = QuantumCircuit(*full_regs, creg)

# Superposición inicial
qc.h(state_reg)
qc.barrier(label="inicio")

# Convertir oráculo y difusor a instrucciones (cajas cerradas en el dibujo)
oracle_inst  = oracle.to_instruction()
diff_circ    = diffuser(n_state)
diff_inst    = diff_circ.to_instruction()

for it in range(iters):
    qc.append(oracle_inst, list(state_reg) + list(pair_flags) +
              (list(range_flags) if range_flags else []))
    qc.append(diff_inst, list(state_reg))
    if it < iters - 1:
        qc.barrier()

qc.barrier(label="medir")
qc.measure(state_reg, creg)

# ── Dibujar ───────────────────────────────────────────────────────────────────

print(f"Circuito: N={N}, k={k}, n_state={n_state} qubits, {iters} iteraciones")
print(f"Profundidad lógica (sin transpilar): {qc.depth()}")

fig = qc.draw(
    output='mpl',
    style='clifford',
    fold=-1,            # sin fold → una sola línea horizontal
    scale=0.55,
    plot_barriers=True,
)

fig.set_size_inches(max(24, iters * 5), 8)
fig.tight_layout()
fig.savefig("grover_circuit.png", dpi=120, bbox_inches='tight',
            facecolor='#1e1e2e', edgecolor='none')
print("Guardado: grover_circuit.png")
plt.close(fig)
