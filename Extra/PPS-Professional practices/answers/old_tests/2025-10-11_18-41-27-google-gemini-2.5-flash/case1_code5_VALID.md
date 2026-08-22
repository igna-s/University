| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> Importing Aer from qiskit is deprecated | * | internal | Aer | `from qiskit_aer import Aer` |
| 14 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> Importing plot_histogram from qiskit.tools.visualization is deprecated | * | internal | plot_histogram | `from qiskit.visualization import plot_histogram` |
| 19 | `from qiskit import SPSA` | Deprecation -> Importing SPSA from qiskit is deprecated | * | internal | SPSA | `from qiskit.algorithms.optimizers import SPSA` |

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