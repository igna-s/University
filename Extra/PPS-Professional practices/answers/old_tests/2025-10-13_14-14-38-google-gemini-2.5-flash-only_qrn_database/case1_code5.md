| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> `qiskit.Aer` module moved to `qiskit_aer` | 3 | Internal Knowledge | Aer | `from qiskit_aer import AerSimulator` |
| 9 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> `Aer.get_backend()` replaced by direct backend instantiation | 3 | Internal Knowledge | Aer.get_backend | `backend = AerSimulator()` |
| 11 | `from qiskit import execute` | Deprecation -> Global `execute()` function | 5 | Internal Knowledge | execute | |
| 12 | `job = execute(qc, backend, shots=1000)` | Deprecation -> Global `execute()` function replaced by `backend.run()` | 5 | Internal Knowledge | execute | `job = backend.run(qc, shots=1000)` |
| 17 | `from qiskit.algorithms import VQE` | Deprecation -> `qiskit.algorithms` module structure changed, `VQE` moved to `qiskit.algorithms.minimum_eigensolvers` | 10 | Internal Knowledge | VQE | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 19 | `from qiskit import SPSA` | Deprecation -> `SPSA` optimizer moved to `qiskit.algorithms.optimizers` | 12 | Internal Knowledge | SPSA | `from qiskit.algorithms.optimizers import SPSA` |


```python
from qiskit import QuantumCircuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import AerSimulator
backend = AerSimulator()

job = backend.run(qc, shots=1000)

from qiskit.tools.visualization import plot_histogram
plot_histogram(job.result().get_counts(qc))

from qiskit.algorithms.minimum_eigensolvers import VQE
from qiskit.circuit.library import TwoLocal
from qiskit.algorithms.optimizers import SPSA
vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())
```