| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from mylib import execute, getBackend` | Deprecation -> Custom simulator interface `mylib` is assumed to wrap deprecated `qiskit.Aer` or `qiskit.BasicAer`. | qrn_notax_ddbb-4194776d-c578-4b79-8dc6-9c5e286bc808 | mylib.execute, mylib.getBackend | `from qiskit_aer import AerSimulator` |
| 3 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> The `qiskit.tools.visualization` module is deprecated. | qrn_notax_ddbb-b8601747-ed0a-4488-b998-af8f180f99be | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 4 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> The `qiskit.tools.monitor` module is deprecated. | qrn_notax_ddbb-d88871b4-b5fd-45b3-b435-712e13d39ff9 | qiskit.tools.monitor.job_monitor | |
| 13 | `simulator = getBackend.get_backend('statevector_simulator')` | Deprecation -> `BasicAer.get_backend('statevector_simulator')` is deprecated, replace with `AerSimulator` or `Statevector`. | qrn_notax_ddbb-4194776d-c578-4b79-8dc6-9c5e286bc808 | getBackend.get_backend | `simulator = AerSimulator(method='statevector')` |
| 14 | `result = execute(qc, simulator).result()` | Deprecation -> The `execute` function is deprecated. Simulators now have a `.run()` method. | qrn_notax_ddbb-2125b2ad-3e2e-494b-b0de-816d0703f19c | execute | `result = simulator.run(qc).result()` |
| 17 | `backend = getBackend.get_backend('qasm_simulator')` | Deprecation -> `BasicAer.get_backend('qasm_simulator')` is deprecated, replace with `AerSimulator` or `BasicSimulator`. | qrn_notax_ddbb-4194776d-c578-4b79-8dc6-9c5e286bc808 | getBackend.get_backend | `backend = AerSimulator(method='qasm_simulator')` |
| 18 | `job = execute(qc, backend, shots=1000)` | Deprecation -> The `execute` function is deprecated. Simulators now have a `.run()` method. | qrn_notax_ddbb-2125b2ad-3e2e-494b-b0de-816d0703f19c | execute | `job = backend.run(qc, shots=1000)` |
| 20 | `job_monitor(job)` | Deprecation -> The `job_monitor` function is deprecated. | qrn_notax_ddbb-d88871b4-b5fd-45b3-b435-712e13d39ff9 | job_monitor | |
| 21 | `counts = job.result().get_counts(qc)` | (optional) Changed -> The `get_counts()` method usually does not require the circuit argument. | IK | get_counts | `counts = job.result().get_counts()` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
from qiskit.visualization import plot_histogram
import matplotlib.pyplot as plt

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

print("Circuito cuántico:")
print(qc.draw(output='text'))

simulator = AerSimulator(method='statevector')
result = simulator.run(qc).result()
statevector = result.get_statevector()

backend = AerSimulator(method='qasm_simulator')
job = backend.run(qc, shots=1000)

counts = job.result().get_counts()
plot_histogram(counts)
```