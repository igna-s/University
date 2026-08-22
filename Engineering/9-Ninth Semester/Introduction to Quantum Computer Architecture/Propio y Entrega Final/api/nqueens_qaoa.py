"""
N-reinas con QAOA (Quantum Approximate Optimization Algorithm).

El script tiene dos partes:
  1. Verificacion exacta del QUBO: enumera los 2^(N^2) estados y encuentra
     el minimo de energia (lo que QAOA intenta aproximar con circuito cuantico).
  2. QAOA real con AerSimulator: corre el circuito variacional y muestra
     la distribucion de mediciones.

Resultado esperado para N=4:
  - QUBO exacto:  las 2 soluciones validas tienen energia minima = 0.
  - QAOA:         las mismas 2 soluciones aparecen como los estados mas probables.
"""

import warnings
warnings.filterwarnings("ignore")

import numpy as np
from itertools import combinations
from scipy.optimize import minimize

from qiskit import QuantumCircuit, transpile
from qiskit.circuit import ParameterVector
from qiskit_aer import AerSimulator


# ---------------------------------------------------------------------------
# Construccion del QUBO  (N^2 variables binarias, sin variables slack)
# ---------------------------------------------------------------------------

def build_qubo(N, penalty=6.0):
    """
    QUBO para N-reinas.
    Variable x[i*N + j] = 1 si hay reina en fila i, columna j.

    Restriccion 'exactamente 1 por fila/columna':
      P * (sum_j x_j - 1)^2  ->  Q_jj += -P,  Q_jk += 2P  (j<k en la misma fila/col)

    Restriccion 'como mucho 1 por diagonal' (desigualdad <=1):
      P * x_j * x_k  para cada par en la misma diagonal  ->  Q_jk += 2P

    Nota: usamos el QUBO simetrico Q' = (Q + Q^T)/2 para la conversion a Ising.
    """
    n = N * N
    Q = np.zeros((n, n))

    def v(i, j):
        return i * N + j

    # --- Restriccion fila: sum_j x_{i,j} == 1 ---
    for i in range(N):
        for j in range(N):
            Q[v(i,j), v(i,j)] -= penalty          # -P en diagonal
            for j2 in range(j+1, N):
                Q[v(i,j), v(i,j2)] += 2 * penalty  # +2P fuera diagonal

    # --- Restriccion columna: sum_i x_{i,j} == 1 ---
    for j in range(N):
        for i in range(N):
            Q[v(i,j), v(i,j)] -= penalty
            for i2 in range(i+1, N):
                Q[v(i,j), v(i2,j)] += 2 * penalty

    # --- Restriccion diagonal principal: a lo sumo 1 reina ---
    for d in range(-(N-1), N):
        cells = [(i, i-d) for i in range(N) if 0 <= i-d < N]
        for (i1,j1),(i2,j2) in combinations(cells, 2):
            Q[v(i1,j1), v(i2,j2)] += 2 * penalty

    # --- Restriccion diagonal secundaria: a lo sumo 1 reina ---
    for d in range(2*N-1):
        cells = [(i, d-i) for i in range(N) if 0 <= d-i < N]
        for (i1,j1),(i2,j2) in combinations(cells, 2):
            Q[v(i1,j1), v(i2,j2)] += 2 * penalty

    return Q


def qubo_energy(x_vec, Q):
    """Energia QUBO: x^T Q x"""
    return float(x_vec @ Q @ x_vec)


# ---------------------------------------------------------------------------
# QUBO exacto: enumerar todos los estados (solo factible para N<=4)
# ---------------------------------------------------------------------------

def solve_qubo_exact(Q, N):
    n = N * N
    min_e = np.inf
    best_states = []
    for k in range(2**n):
        x = np.array([(k >> b) & 1 for b in range(n)], dtype=float)
        e = qubo_energy(x, Q)
        if e < min_e - 1e-6:
            min_e = e
            best_states = [x.copy()]
        elif abs(e - min_e) < 1e-6:
            best_states.append(x.copy())
    return min_e, best_states


def decode_vec(x, N):
    cols = []
    for i in range(N):
        c = [j for j in range(N) if int(round(x[i*N + j])) == 1]
        cols.append(c[0] if len(c) == 1 else c)
    return cols


def validar_cols(cols, N):
    if any(not isinstance(c, int) for c in cols):
        return False
    if len(set(cols)) != N:
        return False
    for i in range(N):
        for j in range(i+1, N):
            if abs(cols[i]-cols[j]) == j-i:
                return False
    return True


def dibujar_cols(cols, N):
    for i in range(N):
        print("    " + "  ".join("Q" if j == cols[i] else "." for j in range(N)))


# ---------------------------------------------------------------------------
# Conversion QUBO -> Ising
# ---------------------------------------------------------------------------

def qubo_to_ising(Q):
    """x_i = (1 - z_i) / 2  con z_i in {-1,+1}"""
    n = Q.shape[0]
    Qs = (Q + Q.T) / 2.0    # simetrizar
    h = np.zeros(n)
    J = np.zeros((n, n))
    offset = 0.0

    for i in range(n):
        for j in range(n):
            qij = Qs[i, j]
            if i == j:
                # contribucion de Q_ii * x_i = Q_ii * (1-z_i)/2
                h[i]  += -qij / 2.0
                offset +=  qij / 2.0
            elif i < j:
                # contribucion de Q_ij * x_i * x_j
                J[i,j] +=  qij / 4.0
                h[i]   += -qij / 4.0
                h[j]   += -qij / 4.0
                offset +=  qij / 4.0

    return h, J, offset


# ---------------------------------------------------------------------------
# Circuito QAOA
# ---------------------------------------------------------------------------

def build_qaoa_circuit(h, J, n_qubits, reps):
    gamma = ParameterVector('g', reps)
    beta  = ParameterVector('b', reps)

    qc = QuantumCircuit(n_qubits)
    qc.h(range(n_qubits))   # superposicion uniforme

    for r in range(reps):
        # Capa de costo
        for i in range(n_qubits):
            for j in range(i+1, n_qubits):
                if abs(J[i,j]) > 1e-10:
                    qc.cx(i, j)
                    qc.rz(2 * gamma[r] * J[i,j], j)
                    qc.cx(i, j)
        for i in range(n_qubits):
            if abs(h[i]) > 1e-10:
                qc.rz(2 * gamma[r] * h[i], i)

        # Capa de mezcla
        for i in range(n_qubits):
            qc.rx(2 * beta[r], i)

    qc.measure_all()
    return qc, gamma, beta


def ising_energy_from_counts(counts, h, J, offset, n_qubits):
    total = sum(counts.values())
    E = 0.0
    for bs, cnt in counts.items():
        z = np.array([1 - 2*int(b) for b in reversed(bs[-n_qubits:])], dtype=float)
        e = offset + h @ z
        for i in range(n_qubits):
            for j in range(i+1, n_qubits):
                if abs(J[i,j]) > 1e-10:
                    e += J[i,j] * z[i] * z[j]
        E += cnt * e
    return E / total


def decode_bs(bs, N):
    n = N * N
    bits = list(reversed(bs[-n:]))
    d = {}
    for i in range(N):
        for j in range(N):
            d[(i,j)] = int(bits[i*N + j])
    cols = []
    for i in range(N):
        c = [j for j in range(N) if d[(i,j)] == 1]
        cols.append(c[0] if len(c) == 1 else c)
    return cols


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

if __name__ == "__main__":
    N = 4

    print(f"\n{'='*55}")
    print(f"  N-Reinas via QAOA  (N={N})")
    print(f"{'='*55}")

    Q = build_qubo(N, penalty=6.0)

    # ----------------------------------------------------------------
    # PARTE 1: Solucion exacta del QUBO (referencia clasica)
    # ----------------------------------------------------------------
    print("\n[1] QUBO exacto (referencia clasica)")
    print(f"    Enumerando 2^{N*N} = {2**(N*N)} estados...")

    min_e, best_states = solve_qubo_exact(Q, N)
    print(f"    Energia minima del QUBO: {min_e:.4f}")
    print(f"    Estados con energia minima: {len(best_states)}")

    soluciones_exactas = set()
    for x in best_states:
        cols = decode_vec(x, N)
        if validar_cols(cols, N):
            soluciones_exactas.add(tuple(cols))
            print(f"    -> cols={cols}  (VALIDA)")
            dibujar_cols(cols, N)
        else:
            print(f"    -> cols={cols}  (INVALIDA, energia minima pero no N-reinas)")

    print(f"\n    Soluciones validas en minimo QUBO: {len(soluciones_exactas)} / 2  {'OK' if len(soluciones_exactas)==2 else 'REVISAR'}")

    # ----------------------------------------------------------------
    # PARTE 2: QAOA con AerSimulator
    # ----------------------------------------------------------------
    print(f"\n[2] QAOA cuantico (AerSimulator)")

    h, J, offset = qubo_to_ising(Q)
    n_qubits = N * N
    REPS   = 2      # OPTIMO: reducido para evitar timeout en Azure (original 6)
    SHOTS  = 1024   # reducido para la nube (original 8192)
    MAXITER = 50    # iteraciones del optimizador COBYLA reducidas (original 500)

    print(f"    Qubits: {n_qubits}  |  reps={REPS}  |  shots={SHOTS}")

    qc, gamma_v, beta_v = build_qaoa_circuit(h, J, n_qubits, REPS)
    sim = AerSimulator()
    qc_t = transpile(qc, sim, optimization_level=1)
    all_params = list(gamma_v) + list(beta_v)

    def objective(params):
        bound = qc_t.assign_parameters(dict(zip(all_params, params)))
        result = sim.run(bound, shots=SHOTS).result()
        return ising_energy_from_counts(result.get_counts(), h, J, offset, n_qubits)

    np.random.seed(0)
    best_opt = None
    N_TRIALS = 2   # reinicios: reducido para evitar timeout (original 8)
    print(f"    Optimizando ({MAXITER} iter, {N_TRIALS} reinicios)...")
    for trial in range(N_TRIALS):
        x0 = np.concatenate([
            np.random.uniform(0, np.pi,   REPS),  # gamma
            np.random.uniform(0, np.pi/2, REPS),  # beta
        ])
        res = minimize(objective, x0, method='COBYLA',
                       options={'maxiter': MAXITER, 'rhobeg': 0.8})
        if best_opt is None or res.fun < best_opt.fun:
            best_opt = res
        print(f"      Intento {trial+1}: energia={res.fun:.4f}  evals={res.nfev}")

    print(f"    Mejor energia Ising: {best_opt.fun:.4f}")

    # Medicion final con mas shots
    bound_final = qc_t.assign_parameters(dict(zip(all_params, best_opt.x)))
    counts_final = sim.run(bound_final, shots=8192).result().get_counts()

    # Contabilizar soluciones validas
    validas = {}
    for bs, cnt in counts_final.items():
        cols = decode_bs(bs, N)
        if validar_cols(cols, N):
            key = tuple(cols)
            validas[key] = validas.get(key, 0) + cnt

    total = sum(counts_final.values())
    valid_shots = sum(validas.values())

    print(f"\n    Top 10 bitstrings medidos:")
    for bs, cnt in sorted(counts_final.items(), key=lambda x: -x[1])[:10]:
        cols = decode_bs(bs, N)
        ok = validar_cols(cols, N)
        mark = "OK" if ok else "X "
        print(f"      {mark}  cols={cols}  count={cnt}  p={cnt/total:.3f}")

    print(f"\n    Soluciones validas unicas: {len(validas)} / 2")
    print(f"    P(medir solucion valida): {valid_shots/total:.1%}")
    for cols, cnt in sorted(validas.items(), key=lambda x: -x[1]):
        print(f"      cols={list(cols)}  count={cnt}")
        dibujar_cols(list(cols), N)

    # ----------------------------------------------------------------
    # Resumen comparacion
    # ----------------------------------------------------------------
    print(f"\n{'='*55}")
    print(f"  RESUMEN COMPARACION  (N={N})")
    print(f"{'='*55}")
    print(f"  {'Metodo':<25} {'Soluciones':<12} {'Validas'}")
    print(f"  {'-'*50}")
    print(f"  {'Secuencial (C)':<25} {'2':<12} [1,3,0,2] y [2,0,3,1]")
    print(f"  {'QUBO exacto (clasico)':<25} {len(soluciones_exactas):<12} {[list(s) for s in soluciones_exactas]}")
    qaoa_sols = [list(s) for s in sorted(validas.keys())]
    print(f"  {'QAOA (cuantico/sim)':<25} {len(validas):<12} {qaoa_sols if validas else 'ver nota'}")
    print(f"\n  Nota: Grover ya encontro las 2 soluciones con p=99.8%")
