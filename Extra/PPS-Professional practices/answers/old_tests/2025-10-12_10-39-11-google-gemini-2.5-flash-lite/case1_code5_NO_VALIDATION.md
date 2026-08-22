| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `from qiskit import Aer` | Removed -> `Aer` from `qiskit` | * | Internal Knowledge | Aer |  |
| 5 | `backend = Aer.get_backend('aer_simulator')` | Removed -> `Aer.get_backend` | * | Internal Knowledge | Aer |  |
| 7 | `from qiskit import execute` | Removed -> `execute` from `qiskit` | * | Internal Knowledge | execute |  |
| 8 | `job = execute(qc, backend, shots=1000)` | Removed -> `execute` function | * | Internal Knowledge | execute |  |
| 10 | `from qiskit.tools.visualization import plot_histogram` | Removed -> `plot_histogram` from `qiskit.tools.visualization` | * | Internal Knowledge | plot_histogram |  |
| 11 | `plot_histogram(job.result().get_counts(qc))` | Removed -> `plot_histogram` function | * | Internal Knowledge | plot_histogram |  |
| 13 | `from qiskit.algorithms import VQE` | Updated -> `VQE` class is moved to `qiskit.algorithms.minimum_eigensolver` | 6 | 7a02300a-3281-407a-9736-3b2d522493a2 | VQE | `from qiskit.algorithms.minimum_eigensolver import VQE` |
| 14 | `from qiskit.circuit.library import TwoLocal` | Updated -> `TwoLocal` is moved to `qiskit.circuit.library.ansatzes` | 18 | 2c7e9e07-a533-4b90-8a7c-949e9723050d | TwoLocal | `from qiskit.circuit.library.ansatzes import TwoLocal` |
| 15 | `from qiskit import SPSA` | Updated -> `SPSA` is moved to `qiskit.algorithms.optimizers` | 6 | 7a02300a-3281-407a-9736-3b2d522493a2 | SPSA | `from qiskit.algorithms.optimizers import SPSA` |
| 16 | `vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())` | Updated -> `VQE` constructor parameters changed | 6 | 7a02300a-3281-407a-9736-3b2d522493a2 | VQE | `vqe = VQE(ansatz=TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), optimizer=SPSA())` |

```
```
python
from qiskit import QuantumCircuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit.providers.basic_provider import BasicProvider
backend = BasicProvider().get_backend('sim_stabilizer')

from qiskit import transpile, assemble
transpiled_qc = transpile(qc, backend)
qobj = assemble(transpiled_qc)
job = backend.run(qobj)

from qiskit.visualization import plot_histogram
plot_histogram(job.result().get_counts(qc))

from qiskit.algorithms.minimum_eigensolver import VQE
from qiskit.circuit.library.ansatzes import TwoLocal
from qiskit.algorithms.optimizers import SPSA
vqe = VQE(ansatz=TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), optimizer=SPSA())

```