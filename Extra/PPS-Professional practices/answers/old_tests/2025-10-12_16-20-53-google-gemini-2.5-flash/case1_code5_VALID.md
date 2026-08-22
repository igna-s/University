| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> Deprecation of qiskit.Aer object | 4 | bb13d578-c8e9-44dd-8431-861cea75d5de | qiskit.Aer | `from qiskit_aer import Aer` |
| 12 | `from qiskit import execute` | Deprecation -> The `qiskit.execute` function is deprecated | * | 35324c6d-04f1-419a-8cec-24cf2fc6c21c | qiskit.execute | |
| 13 | `job = execute(qc, backend, shots=1000)` | Deprecation -> The `qiskit.execute` function is deprecated. Use `backend.run()` instead. | * | 35324c6d-04f1-419a-8cec-24cf2fc6c21c | execute | `job = backend.run(qc, shots=1000)` |
| 15 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> The qiskit.tools module is deprecated. Visualization functions moved to `qiskit.visualization`. | 11 | 5499d167-51d1-4e3f-bac2-58f69b9e9f89 | qiskit.tools | `from qiskit.visualization import plot_histogram` |
| 18 | `from qiskit.algorithms import VQE` | Deprecation -> `qiskit.algorithms` moved to `qiskit_algorithms` (optional) | * | Internal Knowledge | qiskit.algorithms.VQE | `from qiskit_algorithms.minimum_eigensolvers import VQE` |
| 20 | `from qiskit import SPSA` | Deprecation -> `SPSA` optimizer moved to `qiskit_algorithms.optimizers` (optional) | * | Internal Knowledge | qiskit.SPSA | `from qiskit_algorithms.optimizers import SPSA` |


```python
from qiskit import QuantumCircuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import Aer
backend = Aer.get_backend('aer_simulator')

job = backend.run(qc, shots=1000)

from qiskit.visualization import plot_histogram
plot_histogram(job.result().get_counts(qc))

from qiskit_algorithms.minimum_eigensolvers import VQE
from qiskit.circuit.library import TwoLocal
from qiskit_algorithms.optimizers import SPSA
vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())
```