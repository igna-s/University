| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> Deprecation of qiskit.Aer object | qrn_tax_ddbb-0771d384-706f-40c0-818d-20a4b728e9a2 | qiskit.Aer | `from qiskit_aer import Aer` |
| 11 | `from qiskit import execute` | Deprecation -> The `execute` function is deprecated. Use backend's `run` method instead. | qrn_tax_ddbb-c5bbb596-c36f-40b7-9984-82136eb9c656 | execute | |
| 13 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> The `qiskit.tools.visualization` module is deprecated. | qrn_tax_ddbb-f4566a3d-6928-46a7-a2cb-31cd69741944 | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 16 | `from qiskit.algorithms import VQE` | Structural change -> `VQE` class moved to `qiskit.algorithms.minimum_eigensolvers`. | IK | qiskit.algorithms.VQE | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 18 | `from qiskit import SPSA` | Structural change -> `SPSA` class moved to `qiskit.algorithms.optimizers`. | IK | qiskit.SPSA | `from qiskit.algorithms.optimizers import SPSA` |


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