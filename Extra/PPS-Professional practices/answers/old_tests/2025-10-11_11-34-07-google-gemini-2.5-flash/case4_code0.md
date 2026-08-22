| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> The qiskit.tools module has been deprecated and will be removed in Qiskit 1.0.0. | ffefd8a9-6b59-421f-82e6-98595536086e | 77 | qiskit.tools | `from qiskit.visualization import plot_histogram` |
| 4 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> The qiskit.tools module has been deprecated and will be removed in Qiskit 1.0.0. | ffefd8a9-6b59-421f-82e6-98595536086e | 77 | qiskit.tools | `from qiskit.providers.jobstatus import job_monitor` |
| 15 | `simulator = getBackend.get_backend('statevector_simulator')` | Structural change -> Migration: Statevector simulator. Use `Statevector` from `qiskit.quantum_info` instead of BasicAer | 514aa795-3e1d-4687-bdf6-647cb9fe1773 | 37 | statevector_simulator | `from qiskit.quantum_info import Statevector` |
| 16 | `result = execute(qc, simulator).result()` | Structural change -> Migration: Statevector simulator. Use `Statevector` from `qiskit.quantum_info` instead of BasicAer | 514aa795-3e1d-4687-bdf6-647cb9fe1773 | 37 | execute | `statevector = Statevector(qc)` |
| 17 | `statevector = result.get_statevector()` | Structural change -> Migration: Statevector simulator. Use `Statevector` from `qiskit.quantum_info` instead of BasicAer | 514aa795-3e1d-4687-bdf6-647cb9fe1773 | 37 | get_statevector | `statevector = Statevector(qc)` |
| 19 | `backend = getBackend.get_backend('qasm_simulator')` | Structural change -> Migration: basicaer simulators to basic_provider. Statevector, Unitary, QASM simulators replaced by new classes | 33dac8f4-ca5c-480e-a912-f6a4984fc562 | 36 | qasm_simulator | `from qiskit.providers.basic_provider import BasicProvider` |
| 20 | `job = execute(qc, backend, shots=1000)` | Deprecation -> Deprecation of qiskit.Aer object. `qiskit.Aer` is deprecated and will be replaced by `qiskit_aer.Aer`. | f4629adb-1cfe-4469-9df9-d8d0172ab667 | 6 | execute | `from qiskit_aer import AerSimulator` |
| 22 | `job_monitor(job)` | Deprecation -> The qiskit.tools module has been deprecated and will be removed in Qiskit 1.0.0. | ffefd8a9-6b59-421f-82e6-98595536086e | 77 | job_monitor | `from qiskit.providers.jobstatus import job_monitor` |
| 24 | `plot_histogram(counts)` | Deprecation -> The qiskit.tools module has been deprecated and will be removed in Qiskit 1.0.0. | ffefd8a9-6b59-421f-82e6-98595536086e | 77 | plot_histogram | `from qiskit.visualization import plot_histogram` |


```python
from qiskit import QuantumCircuit
from mylib import execute, getBackend 
import matplotlib.pyplot as plt
from qiskit.visualization import plot_histogram
from qiskit.providers.jobstatus import job_monitor
from qiskit.quantum_info import Statevector
from qiskit.providers.basic_provider import BasicProvider
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

print("Circuito cuántico:")
print(qc.draw(output='text'))

statevector = Statevector(qc)

backend = BasicProvider().get_backend('basic_simulator')
aer_simulator = AerSimulator()
job = aer_simulator.run(qc, shots=1000)

job_monitor(job)
counts = job.result().get_counts(qc)
plot_histogram(counts)
```