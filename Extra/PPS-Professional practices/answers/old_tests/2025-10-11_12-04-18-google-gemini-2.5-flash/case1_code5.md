| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> Deprecation of qiskit.Aer object | f4629adb-1cfe-4469-9df9-d8d0172ab667 | f4629adb-1cfe-4469-9df9-d8d0172ab667 | `Aer` | `from qiskit_aer import Aer` |
| 12 | `from qiskit import execute` | Deprecation -> The `execute` function is deprecated. | * | internal | `execute` | |
| 13 | `job = execute(qc, backend, shots=1000)` | Deprecation -> The `execute` function is deprecated in favor of `backend.run()`. | * | internal | `execute` | `job = backend.run(qc, shots=1000)` |
| 15 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> Deprecation of qiskit.tools module. The `plot_histogram` function has moved. | 32b94c5d-d773-416e-b435-6fcfb69c925e | 32b94c5d-d773-416e-b435-6fcfb69c925e | `qiskit.tools.visualization` | `from qiskit.visualization import plot_histogram` |
| 18 | `from qiskit.algorithms import VQE` | Deprecation -> `VQE` has moved from `qiskit.algorithms` to `qiskit.algorithms.minimum_eigensolvers`. | * | internal | `VQE` | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 20 | `from qiskit import SPSA` | Deprecation -> `SPSA` has moved from `qiskit` to `qiskit.algorithms.optimizers`. | * | internal | `SPSA` | `from qiskit.algorithms.optimizers import SPSA` |


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

from qiskit.algorithms.minimum_eigensolvers import VQE
from qiskit.circuit.library import TwoLocal
from qiskit.algorithms.optimizers import SPSA
vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())
```