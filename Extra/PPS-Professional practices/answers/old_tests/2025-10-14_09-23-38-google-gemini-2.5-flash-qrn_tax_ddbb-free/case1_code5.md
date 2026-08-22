| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> `Aer.get_backend()` has moved to `qiskit_aer.AerSimulator()` and should be imported from the `qiskit_aer` package. | Internal Knowledge | `qiskit.Aer` | `from qiskit_aer import AerSimulator` |
| 9 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> `Aer.get_backend()` has moved to `qiskit_aer.AerSimulator()` and should be imported from the `qiskit_aer` package. | Internal Knowledge | `Aer.get_backend` | `backend = AerSimulator()` |
| 11 | `from qiskit import execute` | Deprecation -> The `execute()` function is deprecated. `qiskit.execute` should be replaced by `qiskit.primitives.BackendSampler` for sampling or `qiskit.primitives.BackendEstimator` for expectation values. | Internal Knowledge | `qiskit.execute` | `from qiskit.primitives import BackendSampler` |
| 12 | `job = execute(qc, backend, shots=1000)` | Deprecation -> The `execute()` function is deprecated. `qiskit.execute` should be replaced by `qiskit.primitives.BackendSampler` for sampling or `qiskit.primitives.BackendEstimator` for expectation values. | Internal Knowledge | `execute` | `sampler = BackendSampler()`<br/>`job = sampler.run(qc, shots=1000)` |
| 14 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> `qiskit.tools.visualization` has been deprecated. `plot_histogram` should now be imported from `qiskit.visualization`. | Internal Knowledge | `qiskit.tools.visualization.plot_histogram` | `from qiskit.visualization import plot_histogram` |
| 17 | `from qiskit.algorithms import VQE` | Deprecation -> `qiskit.algorithms.VQE` has been deprecated and moved to `qiskit.algorithms.minimum_eigensolvers.VQE`. | Internal Knowledge | `qiskit.algorithms.VQE` | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 19 | `from qiskit import SPSA` | Deprecation -> `qiskit.SPSA` has been deprecated. Optimizers have been moved to `qiskit.algorithms.optimizers`. | Internal Knowledge | `qiskit.SPSA` | `from qiskit.algorithms.optimizers import SPSA` |
| 20 | `vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())` | Deprecation -> `qiskit.algorithms.VQE` and `qiskit.SPSA` have been deprecated. | Internal Knowledge | `VQE`, `SPSA` | `vqe = VQE(sampler=sampler, ansatz=TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), optimizer=SPSA())` |


```python
from qiskit import QuantumCircuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import AerSimulator
backend = AerSimulator()

from qiskit.primitives import BackendSampler
sampler = BackendSampler()
job = sampler.run(qc, shots=1000)

from qiskit.visualization import plot_histogram
plot_histogram(job.result().get_counts(qc))

from qiskit.algorithms.minimum_eigensolvers import VQE
from qiskit.circuit.library import TwoLocal
from qiskit.algorithms.optimizers import SPSA
vqe = VQE(sampler=sampler, ansatz=TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), optimizer=SPSA())
```