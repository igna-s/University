| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> Use Aer from qiskit_aer | qrn_tax_ddbb--0771d384-706f-40c0-818d-20a4b728e9a2 | qiskit.Aer | `from qiskit_aer import Aer` |
| 11 | `from qiskit import execute` | Deprecation -> The `execute` function is deprecated. Use `backend.run()` instead. | IK | qiskit.execute | |
| 12 | `job = execute(qc, backend, shots=1000)` | Deprecation -> The `execute` function is deprecated. Use `backend.run()` instead. | IK | execute | `job = backend.run(qc, shots=1000)` |
| 14 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> The `qiskit.tools.visualization` module is deprecated. | qrn_tax_ddbb--f4566a3d-6928-46a7-a2cb-31cd69741944 | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 17 | `from qiskit.algorithms import VQE` | Deprecation -> `qiskit.algorithms` has been moved. Use `qiskit.algorithms.minimum_eigensolvers.VQE` instead. | IK | qiskit.algorithms.VQE | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 19 | `from qiskit import SPSA` | Deprecation -> `SPSA` optimizer has been moved. Use `qiskit.algorithms.optimizers.SPSA` instead. | IK | qiskit.SPSA | `from qiskit.algorithms.optimizers import SPSA` |


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