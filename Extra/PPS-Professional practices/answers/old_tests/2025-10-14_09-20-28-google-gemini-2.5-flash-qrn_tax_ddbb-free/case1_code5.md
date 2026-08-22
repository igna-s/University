| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> `Aer` has moved from `qiskit` to `qiskit_aer` | qrn_tax_ddbb-a67b | qiskit.Aer | `from qiskit_aer import AerSimulator` |
| 9 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> The `Aer.get_backend()` method is deprecated; use direct instantiation of simulator classes instead (e.g., `AerSimulator()`). | qrn_tax_ddbb-a67b | Aer.get_backend | `backend = AerSimulator()` |
| 11 | `from qiskit import execute` | Deprecation -> `qiskit.execute` has been removed. Use `backend.run()` instead. | qrn_tax_ddbb-c15a | qiskit.execute | |
| 12 | `job = execute(qc, backend, shots=1000)` | Deprecation -> `qiskit.execute` has been removed. Use `backend.run()` instead. | qrn_tax_ddbb-c15a | execute | `job = backend.run(qc, shots=1000)` |
| 14 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> `qiskit.tools.visualization` has been deprecated. Use `qiskit.visualization` instead. | qrn_tax_ddbb-5991 | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 17 | `from qiskit.algorithms import VQE` | Deprecation -> `qiskit.algorithms` has been moved to a separate package. Use `from qiskit.algorithms.minimum_eigensolvers import VQE` instead. | qrn_tax_ddbb-03b9 | qiskit.algorithms.VQE | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 19 | `from qiskit import SPSA` | Deprecation -> The `SPSA` optimizer has moved from `qiskit` to `qiskit.algorithms.optimizers`. | qrn_tax_ddbb-a059 | qiskit.SPSA | `from qiskit.algorithms.optimizers import SPSA` |


```python
from qiskit import QuantumCircuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import AerSimulator
backend = AerSimulator()

job = backend.run(qc, shots=1000)

from qiskit.visualization import plot_histogram
plot_histogram(job.result().get_counts(qc))

from qiskit.algorithms.minimum_eigensolvers import VQE
from qiskit.circuit.library import TwoLocal
from qiskit.algorithms.optimizers import SPSA
vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())
```