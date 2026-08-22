| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 7 | `from qiskit import Aer` | Deprecation -> `qiskit.Aer` module is deprecated | Internal Knowledge | `qiskit.Aer` | `from qiskit_aer import AerSimulator` |
| 8 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> `Aer.get_backend()` is deprecated | Internal Knowledge | `Aer.get_backend` | `backend = AerSimulator()` |
| 10 | `from qiskit import execute` | Deprecation -> `qiskit.execute` function is deprecated | Internal Knowledge | `execute` | |
| 11 | `job = execute(qc, backend, shots=1000)` | Deprecation -> `execute` function is deprecated | Internal Knowledge | `execute` | `job = backend.run(qc, shots=1000)` |
| 14 | `from qiskit.algorithms import VQE` | Relocation -> `VQE` has moved from `qiskit.algorithms` | Internal Knowledge | `qiskit.algorithms.VQE` | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 16 | `from qiskit import SPSA` | Relocation -> `SPSA` has moved from `qiskit` | Internal Knowledge | `qiskit.SPSA` | `from qiskit.algorithms.optimizers import SPSA` |


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