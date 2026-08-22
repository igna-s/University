| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 13 | from qiskit.tools.visualization import plot_histogram | Deprecation -> plot_histogram moved to qiskit.visualization | qrn_ddbb-d9996c87cd4b498eaa58dcb3a2ee6cfd | qiskit.tools.visualization.plot_histogram | from qiskit.visualization import plot_histogram |
| 18 | from qiskit import SPSA | Deprecation -> SPSA optimizer moved to qiskit.algorithms.optimizers | qrn_ddbb-363ab4e35d374dbb91e6d2e81c5a4069 | SPSA | from qiskit.algorithms.optimizers import SPSA |

```python
from qiskit import QuantumCircuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit import Aer
backend = Aer.get_backend('aer_simulator')

from qiskit import execute
job = execute(qc, backend, shots=1000)

from qiskit.visualization import plot_histogram
plot_histogram(job.result().get_counts(qc))

from qiskit.algorithms import VQE
from qiskit.circuit.library import TwoLocal
from qiskit.algorithms.optimizers import SPSA
vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())
```