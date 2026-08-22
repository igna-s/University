| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | from qiskit import QuantumCircuit |  | IK | QuantumCircuit |  |
| 2 | qc = QuantumCircuit(2, 2) |  | IK | QuantumCircuit |  |
| 3 | qc.h(0) |  | IK | QuantumCircuit |  |
| 4 | qc.cx(0, 1) |  | IK | QuantumCircuit |  |
| 5 | qc.measure(0, 0) |  | IK | QuantumCircuit |  |
| 6 | qc.measure(1, 1) |  | IK | QuantumCircuit |  |
| 7 | from qiskit import Aer | Deprecation -> import from qiskit_aer | IK | qiskit.providers.aer | from qiskit_aer import Aer |
| 8 | backend = Aer.get_backend('aer_simulator') |  | IK | Aer |  |
| 9 | from qiskit import execute | Deprecation -> execute moved to qiskit.compiler | IK | qiskit.compiler.execute | from qiskit.compiler import execute |
| 10 | job = execute(qc, backend, shots=1000) |  | IK | execute |  |
| 11 | from qiskit.tools.visualization import plot_histogram | Deprecation -> use qiskit.visualization | IK | qiskit.tools.visualization | from qiskit.visualization import plot_histogram |
| 12 | plot_histogram(job.result().get_counts(qc)) |  | IK | plot_histogram |  |
| 13 | from qiskit.algorithms import VQE |  | IK | VQE |  |
| 14 | from qiskit.circuit.library import TwoLocal |  | IK | TwoLocal |  |
| 15 | from qiskit import SPSA | Deprecation -> optimizer moved to qiskit.algorithms.optimizers | IK | qiskit.algorithms.optimizers.SPSA | from qiskit.algorithms.optimizers import SPSA |
| 16 | vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA()) |  | IK | VQE |  |

```python
from qiskit import QuantumCircuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import Aer
backend = Aer.get_backend('aer_simulator')

from qiskit.compiler import execute
job = execute(qc, backend, shots=1000)

from qiskit.visualization import plot_histogram
plot_histogram(job.result().get_counts(qc))

from qiskit.algorithms import VQE
from qiskit.circuit.library import TwoLocal
from qiskit.algorithms.optimizers import SPSA
vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())
```

