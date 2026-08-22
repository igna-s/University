| Line | Code | Scenario | Reference | Artifact | Refactoring |
|------|------|----------|-----------|----------|------------|
| 3 | from qiskit.tools.visualization import plot_histogram | Deprecation -> qiskit.tools.visualization module is deprecated and will be removed in Qiskit 1.0.0 | 8340cefb-6745-41c9-94f1-e220d76e7ab5 | qiskit.tools.visualization | from qiskit.visualization import plot_histogram |
| 4 | from qiskit.tools.monitor import job_monitor | Deprecation -> qiskit.tools.monitor module is deprecated and will be removed in Qiskit 1.0.0 | f4566a3d-6928-46a7-a2cb-31cd69741944 | qiskit.tools.monitor | from qiskit.providers.jobmonitor import job_monitor |
| 15 | simulator = getBackend.get_backend('statevector_simulator') | Structural change -> Migration: Statevector simulator Use `Statevector` from `qiskit.quantum_info` instead of BasicAer | 09db4543-63a6-47dd-9cd7-097a6f9fe1a8 | BasicAer statevector_simulator | from qiskit.quantum_info import Statevector; statevector = Statevector.from_instruction(qc) |
| 16 | result = execute(qc, simulator).result() | Structural change -> Migration: Statevector simulator Use `Statevector` from `qiskit.quantum_info` instead of BasicAer | 09db4543-63a6-47dd-9cd7-097a6f9fe1a8 | execute | removed |
| 17 | statevector = result.get_statevector() | Structural change -> Migration: Statevector simulator Use `Statevector` from `qiskit.quantum_info` instead of BasicAer | 09db4543-63a6-47dd-9cd7-097a6f9fe1a8 | Statevector extraction | removed |

```python
from qiskit import QuantumCircuit
from mylib import execute, getBackend
from qiskit.visualization import plot_histogram
from qiskit.providers.jobmonitor import job_monitor
from qiskit.quantum_info import Statevector
import matplotlib.pyplot as plt

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

print("Circuito cuántico:")
print(qc.draw(output='text'))

# Statevector simulation
statevector = Statevector.from_instruction(qc)

backend = getBackend.get_backend('qasm_simulator')
job = execute(qc, backend, shots=1000)

job_monitor(job)
counts = job.result().get_counts(qc)
plot_histogram(counts)
```
