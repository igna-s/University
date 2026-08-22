| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 12 | from qiskit import execute | Deprecation -> The execute() function is deprecated | qrn_tax_ddbb--7bf4d761-c839-4955-8231-1a42d8ebb451 | qiskit.execute | Use backend.run() instead of execute() |
| 13 | job = execute(qc, backend, shots=1000) | Deprecation -> The execute() function is deprecated | qrn_tax_ddbb--7bf4d761-c839-4955-8231-1a42d8ebb451 | qiskit.execute | job = backend.run(qc, shots=1000) |
| 16 | from qiskit.tools.visualization import plot_histogram | Deprecation -> The qiskit.tools.visualization module is deprecated | qrn_tax_ddbb--287e4440-17ef-4074-bc41-4ca986fe3114 | qiskit.tools.visualization | from qiskit.visualization import plot_histogram |
| 20 | from qiskit import SPSA | Deprecation -> The qiskit.SPSA optimizer is deprecated and removed | qrn_tax_ddbb--2e5beb11-dc57-475a-837e-9198bbb1fff7 | qiskit.SPSA | from qiskit.algorithms.optimizers import SPSA |
| 21 | vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA()) | API change -> VQE optimizer must be a subclass of qiskit.algorithms.optimizers.Optimizer | qrn_tax_ddbb--2e5beb11-dc57-475a-837e-9198bbb1fff7 | VQE, SPSA | vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), optimizer=SPSA()) |

```python
from qiskit import QuantumCircuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit import Aer
backend = Aer.get_backend('aer_simulator')

job = backend.run(qc, shots=1000)

from qiskit.visualization import plot_histogram
plot_histogram(job.result().get_counts(qc))

from qiskit.algorithms import VQE
from qiskit.circuit.library import TwoLocal
from qiskit.algorithms.optimizers import SPSA
vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), optimizer=SPSA())
```