| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 9 | `from qiskit import Aer` | Deprecation -> Deprecation of qiskit.Aer object | f4629adb-1cfe-4469-9df9-d8d0172ab667 | 6 | qiskit.Aer | `from qiskit_aer import Aer` |
| 12 | `from qiskit import execute` | Deprecation -> The `qiskit.execute()` function is deprecated | * | internal | qiskit.execute | `from qiskit.primitives import Sampler` |
| 15 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> The qiskit.tools.visualization module has been deprecated | 018bdc08-df40-4266-b4b6-504968ba0f8d | 75 | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 18 | `from qiskit.algorithms import VQE` | Deprecation -> The `qiskit.algorithms` module is deprecated | * | internal | qiskit.algorithms | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 20 | `from qiskit import SPSA` | Deprecation -> The `qiskit.SPSA` optimizer is deprecated | * | internal | qiskit.SPSA | `from qiskit.algorithms.optimizers import SPSA` |


```python
from qiskit import QuantumCircuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import Aer
backend = Aer.get_backend('aer_simulator')

from qiskit.primitives import Sampler
sampler = Sampler()
job = sampler.run(qc, shots=1000)

from qiskit.visualization import plot_histogram
plot_histogram(job.result().get_counts(qc))

from qiskit.algorithms.minimum_eigensolvers import VQE
from qiskit.circuit.library import TwoLocal
from qiskit.algorithms.optimizers import SPSA
vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())
```