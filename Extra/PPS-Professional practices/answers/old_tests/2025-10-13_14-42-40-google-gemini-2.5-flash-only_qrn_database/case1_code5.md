| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> `qiskit.Aer` is deprecated, use `qiskit_aer.Aer` instead | * | ce25a304-5b28-43b2-8a0d-9b31e0b13fb7 | qiskit.Aer | `from qiskit_aer import Aer` |
| 11 | `from qiskit import execute` | Deprecation -> `qiskit.execute` function is deprecated, use `backend.run()` | * | Internal Knowledge | qiskit.execute | |
| 12 | `job = execute(qc, backend, shots=1000)` | Deprecation -> `execute` function call is deprecated, use `backend.run()` | * | Internal Knowledge | execute | `job = backend.run(qc, shots=1000)` |
| 14 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> `qiskit.tools.visualization` module is deprecated, use `qiskit.visualization` | * | b3740733-db29-41f9-831a-0c2f81007982 | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 17 | `from qiskit.algorithms import VQE` | Deprecation -> `qiskit.algorithms` module moved to `qiskit_algorithms` | * | Internal Knowledge | qiskit.algorithms | `from qiskit_algorithms import VQE` |
| 19 | `from qiskit import SPSA` | Deprecation -> `SPSA` optimizer moved to `qiskit.algorithms.optimizers` | * | Internal Knowledge | qiskit.SPSA | `from qiskit.algorithms.optimizers import SPSA` |


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

from qiskit_algorithms import VQE
from qiskit.circuit.library import TwoLocal
from qiskit.algorithms.optimizers import SPSA
vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())
```