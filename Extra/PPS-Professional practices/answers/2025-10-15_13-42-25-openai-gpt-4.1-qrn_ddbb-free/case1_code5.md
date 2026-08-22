| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 7 | from qiskit import Aer | Deprecation -> Aer module is deprecated, use qiskit_aer package instead | qrn_notax_ddbb--4194776d-c578-4b79-8dc6-9c5e286bc808 | qiskit.Aer | from qiskit_aer import Aer |
| 12 | from qiskit import execute | Deprecation -> execute() function is deprecated | IK | qiskit.execute | backend.run(qc, shots=1000) |
| 16 | from qiskit.tools.visualization import plot_histogram | Deprecation -> qiskit.tools.visualization path is deprecated, use qiskit.visualization instead | qrn_notax_ddbb--b8601747-ed0a-4488-b998-af8f180f99be | qiskit.tools.visualization.plot_histogram | from qiskit.visualization import plot_histogram |
| 19 | from qiskit.algorithms import VQE | Migration -> VQE interface has changed in Qiskit 1.0.0 | IK | qiskit.algorithms.VQE | VQE(ansatz=TwoLocal(...), optimizer=SPSA()) |
| 21 | from qiskit import SPSA | Migration -> Optimizers like SPSA are now found in qiskit.algorithms.optimizers | IK | qiskit.SPSA | from qiskit.algorithms.optimizers import SPSA |
| 22 | vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA()) | Migration -> VQE interface and SPSA optimizer import changed | IK | VQE, SPSA | vqe = VQE(ansatz=TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), optimizer=SPSA()) |

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

from qiskit.algorithms import VQE
from qiskit.circuit.library import TwoLocal
from qiskit.algorithms.optimizers import SPSA
vqe = VQE(ansatz=TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), optimizer=SPSA())
```