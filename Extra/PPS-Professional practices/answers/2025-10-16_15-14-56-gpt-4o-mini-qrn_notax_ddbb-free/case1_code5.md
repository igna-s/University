| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 5 | `from qiskit import Aer` | Deprecation -> The `Aer` module is deprecated. | qrn_notax_ddbb--4194776d-c578-4b79-8dc6-9c5e286bc808 | qiskit.providers.aer | `from qiskit_aer import Aer` |
| 8 | `backend = Aer.get_backend('aer_simulator')` | Updated -> The `get_backend` method is updated to work with `qiskit_aer`. | IK | qiskit.providers.aer | `backend = Aer.get_backend('aer_simulator')` |
| 12 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> The `tools.visualization` module is deprecated. | qrn_notax_ddbb--b8601747-ed0a-4488-b998-af8f180f99be | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 13 | `plot_histogram(job.result().get_counts(qc))` | Deprecation -> `plot_histogram` now requires a different data format. | qrn_notax_ddbb--4194776d-c578-4b79-8dc6-9c5e286bc808 | qiskit.visualization | `plot_distribution(job.result().get_counts(qc))` |

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

from qiskit.visualization import plot_distribution
plot_distribution(job.result().get_counts(qc))

from qiskit.algorithms import VQE
from qiskit.circuit.library import TwoLocal
from qiskit import SPSA
vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())
```