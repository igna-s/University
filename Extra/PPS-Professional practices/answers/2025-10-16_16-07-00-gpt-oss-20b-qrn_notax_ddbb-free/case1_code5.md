| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> Aer module is deprecated (optional) | IK | Aer | `from qiskit.providers.aer import AerSimulator` |
| 9 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Aer.get_backend is deprecated (optional) | IK | Aer.get_backend | `backend = AerSimulator()` |
| 14 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> qiskit.tools.visualization is deprecated (optional) | IK | plot_histogram | `from qiskit.visualization import plot_histogram` |
| 19 | `from qiskit import SPSA` | Deprecation -> SPSA import path changed (optional) | IK | SPSA | `from qiskit.algorithms.optimizers import SPSA` |
from qiskit import QuantumCircuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit.providers.aer import AerSimulator
backend = AerSimulator()

from qiskit import execute
job = execute(qc, backend, shots=1000)

from qiskit.visualization import plot_histogram
plot_histogram(job.result().get_counts(qc))

from qiskit.algorithms import VQE
from qiskit.circuit.library import TwoLocal
from qiskit.algorithms.optimizers import SPSA
vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())