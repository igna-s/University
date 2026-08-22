"""
Ejecución de nqueens_grover en Azure Quantum vía Azure CLI.

Pasos previos (una sola vez):
  1. Instalar Azure CLI:  https://aka.ms/installazurecli
  2. En terminal: az login
  3. pip install azure-quantum azure-identity

Configuración: completar las 4 variables de CONFIGURACION abajo.
"""

import sys, io
if sys.stdout.encoding and sys.stdout.encoding.lower() != 'utf-8':
    sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')

# ─── CONFIGURACION ──────────────────────────────────────────────────────────
# Encontrar estos valores en: Azure Portal > tu workspace > Overview

SUBSCRIPTION_ID = "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx"   # az account show --query id
RESOURCE_GROUP  = "mi-resource-group"
WORKSPACE_NAME  = "mi-workspace-quantum"
LOCATION        = "eastus"          # region del workspace

# Backend a usar. Opciones comunes (depende de lo que tengas habilitado):
#   "ionq.simulator"        <- gratis, simulador IonQ cloud
#   "ionq.qpu"              <- hardware IonQ (cuesta creditos)
#   "quantinuum.sim.h1-1sc" <- simulador Quantinuum (gratis con cuenta free)
#   "quantinuum.qpu.h1-1"   <- hardware Quantinuum
#   "rigetti.sim.qvm"       <- simulador Rigetti
BACKEND_NAME = "ionq.simulator"

# ────────────────────────────────────────────────────────────────────────────

from math import ceil, log2, sqrt, asin, pi
from itertools import combinations, permutations

from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister, transpile
from qiskit_aer import AerSimulator   # para verificacion local previa


# ── Importar Azure Quantum ───────────────────────────────────────────────────
try:
    from azure.quantum import Workspace
    from azure.identity import AzureCliCredential
    from azure.quantum.qiskit import AzureQuantumProvider
except ImportError:
    print("[ERROR] Falta instalar: pip install azure-quantum azure-identity")
    sys.exit(1)


# ── Reutilizamos las funciones de nqueens_grover.py ──────────────────────────

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
    state_reg = QuantumRegister(n_state, "q")
    pair_flags = QuantumRegister(pair_count, "pf")
    regs = [state_reg, pair_flags]
    range_flags = None
    if needs_range:
        range_flags = QuantumRegister(N, "rf")
        regs.append(range_flags)
    qc = QuantumCircuit(*regs, name="Oracle")
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
    qc = QuantumCircuit(n_state, name="Diff")
    qc.h(range(n_state))
    qc.x(range(n_state))
    qc.h(n_state - 1)
    qc.mcx(list(range(n_state - 1)), n_state - 1)
    qc.h(n_state - 1)
    qc.x(range(n_state))
    qc.h(range(n_state))
    return qc

def classical_solutions(N):
    sols = []
    for perm in permutations(range(N)):
        ok = all(abs(perm[i] - perm[j]) != j - i
                 for i, j in combinations(range(N), 2))
        if ok:
            sols.append(list(perm))
    return sols

def decode(bitstring, N, k):
    bits = bitstring[::-1]
    queens = []
    for i in range(N):
        col = sum(int(bits[i*k+b]) << b for b in range(k))
        queens.append(col)
    return queens

def is_valid(queens, N):
    if any(c < 0 or c >= N for c in queens):
        return False
    for i, j in combinations(range(N), 2):
        if queens[i] == queens[j] or abs(queens[i] - queens[j]) == j - i:
            return False
    return True

def build_grover_circuit(N=4):
    """Construye el circuito de Grover transpilado para N-reinas."""
    k = max(1, ceil(log2(N)))
    n_state = N * k
    n_sols = len(classical_solutions(N))
    total_states = 2 ** n_state
    theta = 2 * asin(sqrt(n_sols / total_states))
    iters = max(1, int(round(pi / (2 * theta) - 0.5)))

    oracle, state_reg, pair_flags, range_flags = build_oracle(N)
    full_regs = [state_reg, pair_flags] + ([range_flags] if range_flags else [])
    creg = ClassicalRegister(n_state, "c")
    qc = QuantumCircuit(*full_regs, creg)
    qc.h(state_reg)
    diff = diffuser(n_state)
    for _ in range(iters):
        qc.compose(oracle, inplace=True)
        qc.compose(diff, qubits=state_reg, inplace=True)
    qc.measure(state_reg, creg)

    print(f"  Circuito: N={N}, k={k}, {n_state} qubits estado, {iters} iteraciones")
    print(f"  Transpilando a basis gates...")

    qc_t = transpile(qc, basis_gates=["u", "cx", "h", "x", "ccx"], optimization_level=1)
    print(f"  Profundidad transpilada: {qc_t.depth()}")
    return qc_t, state_reg, k


# ── MAIN ─────────────────────────────────────────────────────────────────────

if __name__ == "__main__":

    print("=" * 60)
    print("  Grover N=4 en Azure Quantum")
    print("=" * 60)

    # 1. Autenticar vía Azure CLI (requiere haber hecho 'az login' antes)
    print("\n[1] Autenticando con Azure CLI...")
    try:
        credential = AzureCliCredential()
        workspace = Workspace(
            subscription_id=SUBSCRIPTION_ID,
            resource_group=RESOURCE_GROUP,
            name=WORKSPACE_NAME,
            location=LOCATION,
            credential=credential,
        )
        provider = AzureQuantumProvider(workspace)
        print("    OK - Conectado al workspace:", WORKSPACE_NAME)
    except Exception as e:
        print(f"    ERROR: {e}")
        print("    -> Asegurate de haber corrido: az login")
        print("    -> Y que SUBSCRIPTION_ID, RESOURCE_GROUP, WORKSPACE_NAME sean correctos.")
        sys.exit(1)

    # 2. Listar backends disponibles
    print("\n[2] Backends disponibles en tu workspace:")
    backends = provider.backends()
    for b in backends:
        print(f"    - {b.name()}")

    # 3. Seleccionar backend
    print(f"\n[3] Usando backend: {BACKEND_NAME}")
    try:
        backend = provider.get_backend(BACKEND_NAME)
        print(f"    OK - {backend.name()}")
        config = backend.configuration()
        print(f"    Qubits disponibles: {config.n_qubits}")
    except Exception as e:
        print(f"    ERROR al obtener backend: {e}")
        sys.exit(1)

    # 4. Verificacion local rapida (Aer) antes de mandar a la nube
    print("\n[4] Verificacion local con AerSimulator (1 shot)...")
    qc_t, state_reg, k = build_grover_circuit(N=4)
    local_sim = AerSimulator(method="statevector")
    r = local_sim.run(qc_t, shots=1).result()
    bs = list(r.get_counts().keys())[0]
    queens = decode(bs, 4, k)
    print(f"    Muestra local: cols={queens}  valida={is_valid(queens, 4)}")

    # 5. Enviar a Azure Quantum
    SHOTS = 1024
    print(f"\n[5] Enviando a Azure Quantum ({BACKEND_NAME}) con {SHOTS} shots...")
    print("    NOTA: el trabajo queda en cola. El tiempo varia de minutos a horas.")

    try:
        # Re-transpilar para el backend especifico
        qc_azure = transpile(qc_t, backend=backend, optimization_level=1)
        print(f"    Profundidad para {BACKEND_NAME}: {qc_azure.depth()}")

        job = backend.run(qc_azure, shots=SHOTS)
        job_id = job.id()
        print(f"    Job enviado! ID: {job_id}")
        print(f"\n    Para ver el estado:")
        print(f"      az quantum job show --job-id {job_id} \\")
        print(f"        --workspace-name {WORKSPACE_NAME} \\")
        print(f"        --resource-group {RESOURCE_GROUP} \\")
        print(f"        --location {LOCATION}")

        # Esperar resultado (puede tardar mucho en QPU real)
        print(f"\n    Esperando resultado (Ctrl+C para cancelar y recuperar luego)...")
        result = job.result()
        counts = result.get_counts()

        print(f"\n[6] Resultados de Azure Quantum:")
        total = sum(counts.values())
        valid_count = 0
        for bs, c in sorted(counts.items(), key=lambda x: -x[1])[:10]:
            q = decode(bs, 4, k)
            ok = is_valid(q, 4)
            if ok:
                valid_count += c
            print(f"    {'OK' if ok else 'X '} cols={q}  count={c}  p={c/total:.3f}")
        print(f"\n    P(solucion valida) = {valid_count/total:.1%}")

    except KeyboardInterrupt:
        print(f"\n    Job en cola con ID: {job_id}")
        print(f"    Recuperar resultado despues con:")
        print(f"      from azure.quantum.qiskit import AzureQuantumProvider")
        print(f"      job = provider.get_backend('{BACKEND_NAME}').retrieve_job('{job_id}')")
        print(f"      result = job.result()")
