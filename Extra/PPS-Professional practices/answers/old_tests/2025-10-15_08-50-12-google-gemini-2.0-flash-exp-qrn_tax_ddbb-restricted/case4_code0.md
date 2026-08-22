| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from mylib import execute, getBackend` |  Module Renamed -> The `execute` function has been moved. | qrn_tax_ddbb-a94a1994-1c6f-4a69-b679-9345c7090680 | `execute` | `from qiskit.primitives import Sampler, Estimator` |
| 2 | `from mylib import execute, getBackend` |  Module Renamed -> The `execute` function has been moved. | qrn_tax_ddbb-a94a1994-1c6f-4a69-b679-9345c7090680 | `execute` | `from qiskit.providers import BackendV1 as Backend` |
| 3 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> `qiskit.tools.visualization` is deprecated. | qrn_tax_ddbb-effc4474-b194-43f3-a797-68584292788b | `qiskit.tools.visualization` | `from qiskit.visualization import plot_histogram` |
| 4 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> `qiskit.tools.monitor` is deprecated. | qrn_tax_ddbb-22924d1d-4e89-444c-8169-c25b7e193494 | `qiskit.tools.monitor` | `from qiskit.providers.basic_provider import BasicSimulator` |
| 15 | `simulator = getBackend.get_backend('statevector_simulator')` |  Class/module/function/attribute removed -> `get_backend` has been removed. | qrn_tax_ddbb-31743a8a-7a9a-499a-bb45-47b05086c9ef | `get_backend` | `simulator = BasicSimulator(method='statevector_simulator')` |
| 16 | `result = execute(qc, simulator).result()` |  Module Renamed -> The `execute` function has been moved. | qrn_tax_ddbb-a94a1994-1c6f-4a69-b679-9345c7090680 | `execute` | `sampler = Sampler(backend_options={'method': 'statevector_simulator'})` |
| 16 | `result = execute(qc, simulator).result()` |  Deprecated -> The class being used is deprecated. | qrn_tax_ddbb-13c3c942-435a-4210-8905-997c4e884668 | `SamplerResult` | `result = sampler.run(qc).result()` |
| 17 | `statevector = result.get_statevector()` | Class attribute/method return type change -> The return type of `get_statevector()` has changed. | qrn_tax_ddbb-df9b8734-c4c2-4201-bb21-4ff9305974a7 | `get_statevector()` | `statevector = result.quasi_dists[0]` |
| 19 | `backend = getBackend.get_backend('qasm_simulator')` |  Class/module/function/attribute removed -> `get_backend` has been removed. | qrn_tax_ddbb-31743a8a-7a9a-499a-bb45-47b05086c9ef | `get_backend` | `backend = BasicSimulator(method='qasm_simulator')` |
| 20 | `job = execute(qc, backend, shots=1000)` |  Module Renamed -> The `execute` function has been moved. | qrn_tax_ddbb-a94a1994-1c6f-4a69-b679-9345c7090680 | `execute` | `sampler = Sampler(backend_options={'method': 'qasm_simulator'}, options={'shots': 1000})` |
| 22 | `job_monitor(job)` | Deprecation -> `qiskit.tools.monitor` is deprecated. | qrn_tax_ddbb-22924d1d-4e89-444c-8169-c25b7e193494 | `qiskit.tools.monitor` |   |
| 23 | `counts = job.result().get_counts(qc)` | Class attribute/method return type change -> The return type of `get_counts()` has changed. | qrn_tax_ddbb-4b25a443-3c97-4543-9c74-3914b7871951 | `get_counts()` | `job = sampler.run(qc).result()` |
| 23 | `counts = job.result().get_counts(qc)` | Class attribute/method return type change -> The return type of `get_counts()` has changed. | qrn_tax_ddbb-4b25a443-3c97-4543-9c74-3914b7871951 | `get_counts()` | `counts = job.quasi_dists[0]` |

```python
from qiskit import QuantumCircuit
from qiskit.primitives import Sampler, Estimator
from qiskit.providers import BackendV1 as Backend
from qiskit.visualization import plot_histogram
from qiskit.providers.basic_provider import BasicSimulator
import matplotlib.pyplot as plt

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

print("Circuito cuántico:")
print(qc.draw(output='text'))

simulator = BasicSimulator(method='statevector_simulator')
sampler = Sampler(backend_options={'method': 'statevector_simulator'})
result = sampler.run(qc).result()
statevector = result.quasi_dists[0]

backend = BasicSimulator(method='qasm_simulator')
sampler = Sampler(backend_options={'method': 'qasm_simulator'}, options={'shots': 1000})
job = sampler.run(qc).result()

counts = job.quasi_dists[0]
plot_histogram(counts)
```