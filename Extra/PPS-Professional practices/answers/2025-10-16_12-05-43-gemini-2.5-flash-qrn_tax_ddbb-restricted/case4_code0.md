| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from mylib import execute, getBackend` | Deprecation -> execute() function deprecated | qrn_tax_ddbb-d7e68a47-8d01-4433-a93c-1aebfca5d9f4 | execute() | `from qiskit import transpile` |
| 3 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> qiskit.tools.visualization module has been deprecated | qrn_tax_ddbb-4bc2d33a-666a-48ed-96d1-b12d38ea3acf | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 4 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> qiskit.tools.monitor module has been deprecated | qrn_tax_ddbb-4bc2d33a-666a-48ed-96d1-b12d38ea3acf | qiskit.tools.monitor | |
| 13 | `simulator = getBackend.get_backend('statevector_simulator')` | Structural change<br>qiskit.providers.basic_provider -> Migration: Statevector simulator<br>Use `Statevector` from `qiskit.quantum_info` instead of BasicAer | qrn_tax_ddbb-09db4543-63a6-47dd-9cd7-097a6f9fe1a8 | BasicAer<br>statevector_simulator | `from qiskit.quantum_info import Statevector` |
| 14 | `result = execute(qc, simulator).result()` | Deprecation -> execute() function deprecated | qrn_tax_ddbb-48a35b67-b938-487b-aef2-7b4596ff4105 | execute() | `result = simulator.run(qc).result()` |
| 16 | `backend = getBackend.get_backend('qasm_simulator')` | Structural change<br>qiskit.providers.basic_provider -> Migration: basicaer simulators to basic_provider<br>Statevector, Unitary, QASM simulators replaced by new classes | qrn_tax_ddbb-dd54f269-d2e3-4a45-a285-a01443c4ccef | BasicAerProvider<br>QasmSimulatorPy<br>UnitarySimulatorPy<br>StatevectorSimulatorPy | `from qiskit_aer import AerSimulator` |
| 17 | `job = execute(qc, backend, shots=1000)` | Deprecation -> execute() function deprecated | qrn_tax_ddbb-48a35b67-b938-487b-aef2-7b4596ff4105 | execute() | `job = backend.run(qc, shots=1000)` |
| 19 | `job_monitor(job)` | Deprecation -> qiskit.tools.monitor module has been deprecated | qrn_tax_ddbb-4bc2d33a-666a-48ed-96d1-b12d38ea3acf | job_monitor() | |


```python
from qiskit import QuantumCircuit, transpile
from qiskit.visualization import plot_histogram
from qiskit.quantum_info import Statevector
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
statevector = Statevector(qc)

backend = AerSimulator(method='qasm')
job = backend.run(qc, shots=1000)

counts = job.result().get_counts(qc)
plot_histogram(counts)
```