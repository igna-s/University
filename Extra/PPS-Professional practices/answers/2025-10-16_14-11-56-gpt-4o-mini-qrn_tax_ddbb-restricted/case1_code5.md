| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 1 | `from qiskit import QuantumCircuit` | Deprecation -> Importing from qiskit.providers.aer is deprecated | IK | qiskit | `from qiskit_aer import Aer` |
| 2 | `qc = QuantumCircuit(2, 2)` |  |  | QuantumCircuit |  |
| 3 | `qc.h(0)` |  |  |  |  |
| 4 | `qc.cx(0, 1)` |  |  |  |  |
| 5 | `qc.measure(0, 0)` |  |  |  |  |
| 6 | `qc.measure(1, 1)` |  |  |  |  |
| 7 | `from qiskit import Aer` | Deprecation -> Importing from qiskit.providers.aer is deprecated | IK | Aer | `from qiskit_aer import Aer` | 
| 8 | `backend = Aer.get_backend('aer_simulator')` | Structural change -> Migration: basicaer simulators to basic_provider | qrn_tax_ddbb-34e7c598-21fa-400c-a31f-d5bdb28397b4 | basic_provider | `backend = BasicProvider().get_backend('basic_simulator')` |
| 9 | `from qiskit import execute` | Deprecation -> The `execute()` function is deprecated | IK | execute | `from qiskit import transpile` |
| 10 | `job = execute(qc, backend, shots=1000)` | Structural change -> Migration: basicaer simulators to basic_provider | qrn_tax_ddbb-34e7c598-21fa-400c-a31f-d5bdb28397b4 | execute | `new_circuit = transpile(qc, backend)`<br>`job = backend.run(new_circuit)` |
| 11 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> The module qiskit.tools.visualization.module is deprecated | IK | plot_histogram | `from qiskit.visualization import plot_histogram` |
| 12 | `plot_histogram(job.result().get_counts(qc))` | Deprecation -> Passing a QuasiDistribution, ProbDistribution | IK | plot_histogram | `plot_distribution(job.result().get_counts(qc))` |
| 14 | `from qiskit.algorithms import VQE` |  |  | VQE |  |
| 15 | `from qiskit.circuit.library import TwoLocal` |  |  | TwoLocal |  |
| 16 | `from qiskit import SPSA` |  |  | SPSA |  |
| 17 | `vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())` |  |  | VQE |  | 

```python
from qiskit_aer import Aer
from qiskit import QuantumCircuit, transpile
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = Aer.get_backend('basic_simulator')

new_circuit = transpile(qc, backend)
job = backend.run(new_circuit)

from qiskit.visualization import plot_histogram
plot_histogram(job.result().get_counts(qc))

from qiskit.algorithms import VQE
from qiskit.circuit.library import TwoLocal
from qiskit import SPSA
vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())
```