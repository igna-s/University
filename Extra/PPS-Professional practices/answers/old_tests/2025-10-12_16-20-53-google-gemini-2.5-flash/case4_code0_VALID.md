| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> qiskit.tools.visualization module has been deprecated | 9 | ffd665c6-fea0-4850-aefa-2e7302e527f2 | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 4 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> qiskit.tools.monitor module has been deprecated | 8 | ffd665c6-fea0-4850-aefa-2e7302e527f2 | qiskit.tools.monitor | |
| 14 | `simulator = getBackend.get_backend('statevector_simulator')` | Deprecation -> Aer.get_backend has been deprecated | 29 | 51fe4914-d6c2-4a55-b7af-3257eb6c9457 | get_backend | `from qiskit.quantum_info import Statevector` |
| 15 | `result = execute(qc, simulator).result()` | Deprecation -> execute() function has been deprecated | 25 | 3fe9c4ed-0515-48f3-b692-bbc5a124f8e6 | execute() | `result = simulator.run(qc).result()` |
| 16 | `statevector = result.get_statevector()` | Deprecation -> StatevectorSimulatorPy is deprecated | * | 782500c9-ed6f-4c83-a824-f8146e05d616 | get_statevector | `statevector = Statevector(qc)` |
| 18 | `backend = getBackend.get_backend('qasm_simulator')` | Deprecation -> Aer.get_backend has been deprecated | 29 | 51fe4914-d6c2-4a55-b7af-3257eb6c9457 | get_backend | `from qiskit_aer import AerSimulator` |
| 19 | `job = execute(qc, backend, shots=1000)` | Deprecation -> execute() function has been deprecated | 25 | 3fe9c4ed-0515-48f3-b692-bbc5a124f8e6 | execute() | `job = backend.run(qc, shots=1000)` |
| 21 | `job_monitor(job)` | Deprecation -> job_monitor function has been deprecated | 8 | a2a0fcf9-a917-4479-87fa-2659bf6f1090 | job_monitor | |
| 23 | `plot_histogram(counts)` | Deprecation -> plot_histogram() function for certain data types | 2 | 49091cfd-4926-4eca-a981-e07367d565e1 | plot_histogram() | `plot_histogram(counts)` |


```python
from qiskit import QuantumCircuit
from mylib import execute, getBackend 
from qiskit.visualization import plot_histogram
import matplotlib.pyplot as plt
from qiskit.quantum_info import Statevector
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

print("Circuito cuántico:")
print(qc.draw(output='text'))

simulator = AerSimulator(method='statevector')
result = simulator.run(qc).result()
statevector = Statevector(qc)

backend = AerSimulator(method='qasm_simulator')
job = backend.run(qc, shots=1000)

counts = job.result().get_counts(qc)
plot_histogram(counts)
```