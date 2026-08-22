| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> Use of the qiskit.Aer object is deprecated and will be removed in Qiskit 1.0. You should instead use the same object from the qiskit_aer namespace, which is a drop-in replacement. | * | f9660e82-508c-4d89-81e3-c97a551ef265 | Aer | `from qiskit_aer import Aer` |
| 9 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Use of the qiskit.Aer object is deprecated and will be removed in Qiskit 1.0. You should instead use the same object from the qiskit_aer namespace, which is a drop-in replacement. | * | f9660e82-508c-4d89-81e3-c97a551ef265 | Aer.get_backend | `backend = Aer.get_backend('aer_simulator')` |
| 11 | `from qiskit import execute` | Deprecation -> `qiskit.execute` is deprecated. `QuantumCircuit.run` should be used instead. | * | Internal Knowledge | execute | |
| 12 | `job = execute(qc, backend, shots=1000)` | Deprecation -> `qiskit.execute` is deprecated. `QuantumCircuit.run` should be used instead. | * | Internal Knowledge | execute | `job = backend.run(qc, shots=1000)` |
| 14 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> The qiskit.tools.visualization module has been deprecated and will be removed in Qiskit 1.0.0. This module was a legacy redirect from the original location of Qiskit’s visualization module and was moved to qiskit.visualization in Qiskit 0.8.0. If you’re still using this path you can just update your imports from qiskit.tools.visualization to qiskit.visualization. | 9 | 7bc0146e-0c67-4a09-ac91-4e96adaf69a6 | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 15 | `plot_histogram(job.result().get_counts(qc))` | Deprecation -> Passing a QuasiDistribution, ProbDistribution, or a distribution dictionary in for the data argument of the plot_histogram() visualization function is now deprecated. Support for doing this will be removed in the Qiskit 1.0 release. If you would like to plot a histogram from a QuasiDistribution, ProbDistribution, or a distribution dictionary you should use the plot_distribution() function instead. | 2 | 06cac5bf-df90-453e-9026-f0f5f83b015c | plot_histogram | `plot_histogram(job.result().get_counts(qc))` |
| 17 | `from qiskit.algorithms import VQE` | Deprecation -> `qiskit.algorithms` module is deprecated. Algorithms have been moved to `qiskit.algorithms.minimum_eigensolvers` | * | Internal Knowledge | VQE | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 19 | `from qiskit import SPSA` | Deprecation -> `qiskit.SPSA` is deprecated. Optimizers have been moved to `qiskit.algorithms.optimizers` | * | Internal Knowledge | SPSA | `from qiskit.algorithms.optimizers import SPSA` |
| 20 | `vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())` | Deprecation -> `qiskit.algorithms` module is deprecated. Algorithms have been moved to `qiskit.algorithms.minimum_eigensolvers` | * | Internal Knowledge | VQE | `vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())` |


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