| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> Aer provider is deprecated | qrn_ddbb-62494693f931623538052657 | Aer | `from qiskit_aer import AerSimulator` |
| 9 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Aer provider is deprecated | qrn_ddbb-62494693f931623538052657 | Aer.get_backend | `backend = AerSimulator()` |
| 11 | `from qiskit import execute` | Deprecation -> The `execute` function is deprecated and will be removed in a future release. | qrn_ddbb-62494693f931623538052659 | execute |  |
| 12 | `job = execute(qc, backend, shots=1000)` | Deprecation -> The `execute` function is deprecated and will be removed in a future release. | qrn_ddbb-62494693f931623538052659 | execute | `job = backend.run(qc, shots=1000).result()` |
| 14 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> Module `qiskit.tools.visualization` is deprecated | qrn_ddbb-62494693f931623538052661 | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 18 | `from qiskit import SPSA` | package migration -> Moved SPSA algorithm | qrn_ddbb-a0a9371c041a44e3b829ca4735f93712 | qiskit.spsa | `from qiskit.algorithms.optimizers import SPSA` |
| 19 | `vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())` | class constructor change -> the second argument of the VQE class constructor must be an Optimizer instance | qrn_ddbb-1206e151822c4d0ca2ca388851c3610a | VQE | `vqe = VQE(ansatz=TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), optimizer=SPSA())` |

```python
from qiskit import QuantumCircuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import AerSimulator
backend = AerSimulator()

job = backend.run(qc, shots=1000).result()

from qiskit.visualization import plot_histogram
plot_histogram(job.result().get_counts(qc))

from qiskit.algorithms import VQE
from qiskit.circuit.library import TwoLocal
from qiskit.algorithms.optimizers import SPSA
vqe = VQE(ansatz=TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), optimizer=SPSA())
```