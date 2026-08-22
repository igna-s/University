| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit` | New library -> qiskit.providers.basic_provider module introduced | qrn_notax_ddbb-bdfc0899-dad8-4479-af86-e874c42ed8f4 | qiskit.providers.basicaer | `from qiskit import QuantumCircuit` |
| 2 | `from mylib import execute, getBackend` | Deprecation -> execute() function is deprecated | qrn_notax_ddbb-7dcaf104-d552-4d87-994a-c7691846d9a9 | mylib | `from qiskit import transpile` |
| 3 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> qiskit.tools.visualization module deprecated | qrn_notax_ddbb-b8601747-ed0a-4488-b998-af8f180f99be | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 4 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> qiskit.tools.monitor module deprecated | qrn_notax_ddbb-d88871b4-b5fd-45b3-b435-712e13d39ff9 | qiskit.tools.monitor | `job_monitor(job)` should be removed or replaced with appropriate job monitoring from new modules |
| 19 | `simulator = getBackend.get_backend('statevector_simulator')` | Update -> BasicAer removed | qrn_notax_ddbb-98ed0e4a-c3d2-4c4f-93a7-42ebe62e7869 | mylib.getBackend | `from qiskit.providers.basic_provider import BasicProvider\nprovider = BasicProvider()\nsimulator = provider.get_backend('basic_simulator')` |
| 20 | `result = execute(qc, simulator).result()` | Update -> execute() is deprecated | qrn_notax_ddbb-7dcaf104-d552-4d87-994a-c7691846d9a9 | mylib | `new_circuit = transpile(qc, simulator)\nresult = simulator.run(new_circuit).result()` |
| 24 | `backend = getBackend.get_backend('qasm_simulator')` | Update -> BasicAer removed | qrn_notax_ddbb-98ed0e4a-c3d2-4c4f-93a7-42ebe62e7869 | mylib.getBackend | `backend = provider.get_backend("basic_simulator")` |
| 27 | `job = execute(qc, backend, shots=1000)` | Update -> execute() is deprecated | qrn_notax_ddbb-7dcaf104-d552-4d87-994a-c7691846d9a9 | mylib | `transpiled_circuit = transpile(qc, backend)\njob = backend.run(transpiled_circuit, shots=1000)` |
| 30 | `plot_histogram(counts)` | Update -> Using distribution dictionary is deprecated | qrn_notax_ddbb-4194776d-c578-4b79-8dc6-9c5e286bc808 | matplotlib | `from qiskit.visualization import plot_distribution\nplot_distribution(counts)` |

```python
from qiskit import QuantumCircuit, transpile
from qiskit.providers.basic_provider import BasicProvider
from qiskit.visualization import plot_histogram
import matplotlib.pyplot as plt

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

print("Circuito cuántico:")
print(qc.draw(output='text'))

provider = BasicProvider()
simulator = provider.get_backend('basic_simulator')
new_circuit = transpile(qc, simulator)
result = simulator.run(new_circuit).result()
statevector = result.get_statevector()

backend = provider.get_backend('basic_simulator')
transpiled_circuit = transpile(qc, backend)
job = backend.run(transpiled_circuit, shots=1000)

counts = job.result().get_counts(qc)
plot_histogram(counts)
```