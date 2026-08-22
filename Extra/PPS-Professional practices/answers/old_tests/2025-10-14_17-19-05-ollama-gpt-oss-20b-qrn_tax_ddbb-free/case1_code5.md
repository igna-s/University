| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> qiskit.Aer object is deprecated | c02fdd64-b33a-477c-a00d-105424346f39 | qiskit.Aer | `from qiskit_aer import Aer` |
| 11 | `from qiskit import execute` | Deprecation -> execute function moved to qiskit.execute | IK | qiskit.execute | `from qiskit.execute import execute` |
| 14 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> qiskit.tools.visualization is deprecated | 155c8cbc-e03b-4da7-affb-2e5390f0c487 | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 19 | `from qiskit import SPSA` | Deprecation -> SPSA import path moved to qiskit.algorithms.optimizers | IK | qiskit.SPSA | `from qiskit.algorithms.optimizers import SPSA` |

```python
from qiskit import QuantumCircuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import Aer
backend = Aer.get_backend('aer_simulator')

from qiskit.execute import execute
job = execute(qc, backend, shots=1000)

from qiskit.visualization import plot_histogram
plot_histogram(job.result().get_counts(qc))

from qiskit.algorithms import VQE
from qiskit.circuit.library import TwoLocal
from qiskit.algorithms.optimizers import SPSA
vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())
```
