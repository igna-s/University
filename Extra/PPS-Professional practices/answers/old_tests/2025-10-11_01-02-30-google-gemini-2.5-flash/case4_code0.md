| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> The `qiskit.tools.visualization` module is deprecated. | 8f039439-6b74-4203-9559-e21f717e31c3 | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 4 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> The `qiskit.tools.monitor` module is deprecated. | bec370dc-b93d-44d0-b220-5314dd5cbda8 | qiskit.tools.monitor | Removed as functionality is tied to legacy provider, replaced by `job.wait_for_final_state()` |
| 15 | `simulator = getBackend.get_backend('statevector_simulator')` | API Change -> `qiskit.providers.basicaer` module is deprecated; simulator instantiation updated. | 803fc199-294f-486b-88d5-bcbc0044f2cd | getBackend / StatevectorSimulatorPy | `from qiskit_aer import AerSimulator`<br>`simulator = AerSimulator(method='statevector')` |
| 16 | `result = execute(qc, simulator).result()` | API Change -> `execute` function from external `mylib` replaced by standard `backend.run()` method. | internal | execute | `result = simulator.run(qc).result()` |
| 19 | `backend = getBackend.get_backend('qasm_simulator')` | API Change -> `qiskit.providers.basicaer` module is deprecated; simulator instantiation updated. | 803fc199-294f-486b-88d5-bcbc0044f2cd | getBackend / QasmSimulatorPy | `backend = AerSimulator(method='qasm')` |
| 20 | `job = execute(qc, backend, shots=1000)` | API Change -> `execute` function from external `mylib` replaced by standard `backend.run()` method. | internal | execute | `job = backend.run(qc, shots=1000)` |
| 22 | `job_monitor(job)` | Deprecation -> The `job_monitor` function is deprecated and replaced by the job object's `wait_for_final_state()` method. | bec370dc-b93d-44d0-b220-5314dd5cbda8 | job_monitor | `job.wait_for_final_state()` |


```python
from qiskit import QuantumCircuit
from qiskit.visualization import plot_histogram
import matplotlib.pyplot as plt
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

print("Circuito cuántico:")
print(qc.draw(output='text'))

simulator = AerSimulator(method='statevector')
result = simulator.run(qc).result()
statevector = result.get_statevector()

backend = AerSimulator(method='qasm')
job = backend.run(qc, shots=1000)

job.wait_for_final_state()
counts = job.result().get_counts(qc)
plot_histogram(counts)
```