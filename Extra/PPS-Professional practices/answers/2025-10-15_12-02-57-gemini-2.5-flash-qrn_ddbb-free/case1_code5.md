| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> Importing from `qiskit.Aer` is deprecated | qrn_notax_ddbb--4194776d-c578-4b79-8dc6-9c5e286bc808 | qiskit.Aer | `from qiskit_aer import AerSimulator` |
| 9 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> `Aer.get_backend()` is deprecated. Direct instantiation of `AerSimulator()` should be used. | qrn_notax_ddbb--4194776d-c578-4b79-8dc6-9c5e286bc808 | Aer.get_backend | `backend = AerSimulator()` |
| 11 | `from qiskit import execute` | Deprecation -> `qiskit.execute` is deprecated | qrn_notax_ddbb--548acfe8-db26-45b7-ab5c-c637c63ee4b0 | qiskit.execute | |
| 12 | `job = execute(qc, backend, shots=1000)` | Deprecation -> The `execute` function is deprecated. Backend's `run` method should be used. | qrn_notax_ddbb--2125b2ad-3e2e-494b-b0de-816d0703f19c | execute | `job = backend.run(qc, shots=1000)` |
| 14 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> The `qiskit.tools.visualization` module is deprecated | qrn_notax_ddbb--b8601747-ed0a-4488-b998-af8f180f99be | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 17 | `from qiskit.algorithms import VQE` | Deprecation -> `qiskit.algorithms` module has been restructured. | IK | qiskit.algorithms.VQE | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 19 | `from qiskit import SPSA` | Deprecation -> `qiskit.SPSA` has moved to optimizers. | IK | qiskit.SPSA | `from qiskit.algorithms.optimizers import SPSA` |


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