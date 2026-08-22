| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> The qiskit.tools.visualization module is deprecated | qrn_tax_ddbb-4bc2d33a-666a-48ed-96d1-b12d38ea3acf | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 3 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> The qiskit.tools.monitor module is deprecated | qrn_tax_ddbb-7b51c58e-5407-41cc-abe7-25ad46ab40e0 | qiskit.tools.monitor |  |
| 10 | `result = execute(qc, simulator).result()` | Deprecation -> The execute() function is deprecated | qrn_tax_ddbb-48a35b67-b938-487b-aef2-7b4596ff4105 | execute | `new_circuit = transpile(qc, simulator)\nresult = simulator.run(new_circuit)` |
| 14 | `result = execute(qc, backend, shots=1000)` | Deprecation -> The execute() function is deprecated | qrn_tax_ddbb-48a35b67-b938-487b-aef2-7b4596ff4105 | execute | `new_circuit = transpile(qc, backend)\njob = backend.run(new_circuit, shots=1000)` |
| 16 | `job_monitor(job)` | Deprecation -> The qiskit.tools.monitor module is deprecated | qrn_tax_ddbb-7b51c58e-5407-41cc-abe7-25ad46ab40e0 | qiskit.tools.monitor |  |
| 20 | `backend = getBackend.get_backend('statevector_simulator')` | Deprecated -> Use Statevector from qiskit.quantum_info instead of BasicAer | qrn_tax_ddbb-09db4543-63a6-47dd-9cd7-097a6f9fe1a8 | getBackend | `from qiskit.quantum_info import Statevector\nbackend = Statevector(qc)` |
| 23 | `backend = getBackend.get_backend('qasm_simulator')` | Deprecated -> Use BasicProvider instead of BasicAer | qrn_tax_ddbb-dd54f269-d2e3-4a45-a285-a01443c4ccef | getBackend | `from qiskit.providers.basic_provider import BasicProvider\nbackend = BasicProvider().get_backend('basic_simulator')` |
| 25 | `counts = job.result().get_counts(qc)` | Deprecated -> plot_histogram() changes | qrn_tax_ddbb-8340cefb-6745-41c9-94f1-e220d76e7ab5 | plot_histogram | `plot_distribution(counts)` |

```python
from qiskit import QuantumCircuit
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

backend = BasicProvider().get_backend('basic_simulator')
new_circuit = transpile(qc, backend)
job = backend.run(new_circuit, shots=1000)

counts = job.result().get_counts(qc)
plot_histogram(counts)
```