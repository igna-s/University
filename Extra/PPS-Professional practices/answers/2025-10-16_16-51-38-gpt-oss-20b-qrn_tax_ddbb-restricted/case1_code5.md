| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> Importing qiskit.Aer changed to qiskit_aer | qrn_tax_ddbb-0771d384-706f-40c0-818d-20a4b728e9a2 | Aer | `from qiskit_aer import Aer` |
| 14 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> qiskit.tools.visualization module moved to qiskit.visualization | qrn_tax_ddbb-f4566a3d-6928-46a7-a2cb-31cd69741944 | plot_histogram | `from qiskit.visualization import plot_histogram` |
| 19 | `from qiskit import SPSA` | Deprecation -> SPSA moved to qiskit.algorithms.optimizers | IK | SPSA | `from qiskit.algorithms.optimizers import SPSA` |

```python
from qiskit import QuantumCircuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import Aer
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