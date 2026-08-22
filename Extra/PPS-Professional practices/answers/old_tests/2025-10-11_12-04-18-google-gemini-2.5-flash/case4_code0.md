| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> Deprecation of qiskit.tools.visualization module | b34548a9-18c8-4147-aa93-ab0183c684f1 | 018bdc08-df40-4266-b4b6-504968ba0f8d | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 4 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> Deprecation of qiskit.tools.monitor module | b34548a9-18c8-4147-aa93-ab0183c684f1 | b34548a9-18c8-4147-aa93-ab0183c684f1 | qiskit.tools.monitor | |
| 14 | `simulator = getBackend.get_backend('statevector_simulator')` | Structural change -> Migration: Statevector simulator Use `Statevector` from `qiskit.quantum_info` instead of BasicAer | 514aa795-3e1d-4687-bdf6-647cb9fe1773 | 514aa795-3e1d-4687-bdf6-647cb9fe1773 | BasicAer `statevector_simulator` | `from qiskit.quantum_info import Statevector` |
| 15 | `result = execute(qc, simulator).result()` | Deprecation -> Qiskit’s execute() function is deprecated. | cc6d2843-80cd-4947-9bb4-a8bf5bc7b9f6 | cc6d2843-80cd-4947-9bb4-a8bf5bc7b9f6 | execute() | `job = backend.run(new_circuit)` |
| 18 | `backend = getBackend.get_backend('qasm_simulator')` | Structural change -> Migration: basicaer simulators to basic_provider Statevector, Unitary, QASM simulators replaced by new classes | 33dac8f4-ca5c-480e-a912-f6a4984fc562 | 33dac8f4-ca5c-480e-a912-f6a4984fc562 | BasicAerProvider `QasmSimulatorPy` | `from qiskit.providers.basic_provider import BasicProvider` |
| 19 | `job = execute(qc, backend, shots=1000)` | Deprecation -> Qiskit’s execute() function is deprecated. | cc6d2843-80cd-4947-9bb4-a8bf5bc7b9f6 | cc6d2843-80cd-4947-9bb4-a8bf5bc7b9f6 | execute() | `job = backend.run(new_circuit)` |
| 21 | `job_monitor(job)` | Deprecation -> Deprecation of qiskit.tools.monitor module | b34548a9-18c8-4147-aa93-ab0183c684f1 | b34548a9-18c8-4147-aa93-ab0183c684f1 | job_monitor | |


```python
from qiskit import QuantumCircuit
from mylib import execute, getBackend 
from qiskit.visualization import plot_histogram
import matplotlib.pyplot as plt
from qiskit.quantum_info import Statevector
from qiskit.providers.basic_provider import BasicProvider
from qiskit import transpile


qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

print("Circuito cuántico:")
print(qc.draw(output='text'))

simulator = Statevector(qc)

backend = BasicProvider().get_backend('basic_simulator')
new_qc = transpile(qc, backend)
job = backend.run(new_qc, shots=1000)

counts = job.result().get_counts(new_qc)
plot_histogram(counts)
```