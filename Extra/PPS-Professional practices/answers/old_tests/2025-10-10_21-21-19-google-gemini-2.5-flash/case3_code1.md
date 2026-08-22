| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :------- | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, execute, Aer` | Deprecation -> `execute` function is deprecated. `Aer.get_backend` is deprecated, leading to changes in `Aer` import. | internal | `execute`, `Aer` | `from qiskit import QuantumCircuit`<br/>`from qiskit_aer import AerSimulator` |
| 3 | `from qiskit.utils import algorithm_globals` | Deprecation -> `qiskit.utils.algorithm_globals` module is deprecated. | internal | `qiskit.utils.algorithm_globals` | `from qiskit.primitives.utils import init_algorithm_globals` |
| 6 | `algorithm_globals.random_seed = 12345` | Deprecation -> `algorithm_globals.random_seed` is deprecated. | internal | `algorithm_globals.random_seed` | `init_algorithm_globals(seed=12345)` |
| 15 | `backend = Aer.get_backend('qasm_simulator')` | Deprecation -> `Aer.get_backend` is deprecated. | internal | `Aer.get_backend` | `backend = AerSimulator()` |
| 16 | `job = execute(qc, backend, shots=1024)` | Deprecation -> `qiskit.execute` function is deprecated. | internal | `execute` | `job = backend.run(qc, shots=1024)` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
from qiskit.visualization import plot_histogram
from qiskit.primitives.utils import init_algorithm_globals

init_algorithm_globals(seed=12345)

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

backend = AerSimulator()
job = backend.run(qc, shots=1024)
result = job.result()
counts = result.get_counts(qc)

plot_histogram(counts)
```