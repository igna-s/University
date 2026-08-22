| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 7 | from qiskit import Aer | Deprecation -> Deprecation of qiskit.Aer object | qrn_tax_ddbb-c02fdd64-b33a-477c-a00d-105424346f39 | qiskit.Aer | from qiskit_aer import Aer |
| 13 | from qiskit import execute | Deprecation -> execute() function deprecated | IK | execute |  |
| 17 | from qiskit.tools.visualization import plot_histogram | Deprecation -> The qiskit.tools.visualization module has been deprecated and will be removed in Qiskit 1.0.0 | qrn_tax_ddbb-55d90aa5-cb5e-4195-9423-24996e3d9943 | qiskit.tools.visualization | from qiskit.visualization import plot_histogram |
| 22 | from qiskit import SPSA | Removal -> SPSA algorithm removed from qiskit root namespace | IK | SPSA | from qiskit.algorithms.optimizers import SPSA |

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