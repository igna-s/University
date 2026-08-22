| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from mylib import execute, getBackend` | Deprecation -> `qiskit.execute` function and `qiskit.Aer.get_backend` method patterns deprecated | IK | `mylib.execute`, `mylib.getBackend` | `from qiskit_aer import AerSimulator` |
| 3 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> The `qiskit.tools.visualization` module is deprecated | qrn_tax_ddbb--4bc2d33a-666a-48ed-96d1-b12d38ea3acf | `qiskit.tools.visualization` | `from qiskit.visualization import plot_histogram` |
| 4 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> The `qiskit.tools.monitor` module is deprecated | qrn_tax_ddbb--f4566a3d-6928-46a7-a2cb-31cd69741944 | `qiskit.tools.monitor` | |
| 14 | `simulator = getBackend.get_backend('statevector_simulator')` | Deprecation -> `qiskit.Aer.get_backend` method is deprecated, replace with `AerSimulator` from `qiskit_aer` | qrn_tax_ddbb--4e1a7f69-eeb4-4a93-9f27-322819438bf4 | `getBackend.get_backend` | `simulator = AerSimulator(method='statevector')` |
| 15 | `result = execute(qc, simulator).result()` | Deprecation -> The global `execute` function is deprecated, use the backend's `.run()` method | IK | `execute` | `result = simulator.run(qc).result()` |
| 17 | `backend = getBackend.get_backend('qasm_simulator')` | Deprecation -> `qiskit.Aer.get_backend` method is deprecated, replace with `AerSimulator` from `qiskit_aer` | qrn_tax_ddbb--4e1a7f69-eeb4-4a93-9f27-322819438bf4 | `getBackend.get_backend` | `backend = AerSimulator()` |
| 18 | `job = execute(qc, backend, shots=1000)` | Deprecation -> The global `execute` function is deprecated, use the backend's `.run()` method | IK | `execute` | `job = backend.run(qc, shots=1000)` |
| 20 | `job_monitor(job)` | Deprecation -> The `job_monitor` function is deprecated as its module is removed | qrn_tax_ddbb--7b51c58e-5407-41cc-abe7-25ad46ab40e0 | `job_monitor` | |


```python
from qiskit import QuantumCircuit
from qiskit.visualization import plot_histogram
from qiskit_aer import AerSimulator
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

backend = AerSimulator()
job = backend.run(qc, shots=1000)

counts = job.result().get_counts(qc)
plot_histogram(counts)
```