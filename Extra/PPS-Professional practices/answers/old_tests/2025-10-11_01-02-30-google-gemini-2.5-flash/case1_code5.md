| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> Importing from qiskit.providers.aer is deprecated and will stop working in Qiskit 1.0. You should instead import from qiskit_aer, which is a drop-in replacement. | d632081c-97e1-4fa4-b5aa-e11204bcd570 | qiskit.Aer | `from qiskit_aer import AerSimulator` |
| 9 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Use of the qiskit.Aer object is deprecated and will be removed in Qiskit 1.0. You should instead use the same object from the qiskit_aer namespace, which is a drop-in replacement. | d0282943-2571-4dc2-8039-7d6e97e0d38a | Aer.get_backend | `backend = AerSimulator()` |
| 11 | `from qiskit import execute` | Deprecation -> Qiskit’s execute() function is deprecated. This function served as a high-level wrapper around transpiling a circuit with some transpile options and running it on a backend with some run options. | 0b78d58d-ae5a-415b-aabc-02e0532a0c9e | qiskit.execute | `from qiskit import transpile` |
| 12 | `job = execute(qc, backend, shots=1000)` | Deprecation -> Qiskit’s execute() function is deprecated. To do the same thing, you can explicitly use the transpile() function (with appropriate transpile options) followed by backend.run() (with appropriate run options). | 0b78d58d-ae5a-415b-aabc-02e0532a0c9e | execute | `transpiled_qc = transpile(qc, backend)`<br>`job = backend.run(transpiled_qc, shots=1000)` |
| 14 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> The qiskit.tools.visualization module has been deprecated and will be removed in Qiskit 1.0.0. This module was a legacy redirect from the original location of Qiskit’s visualization module and was moved to qiskit.visualization in Qiskit 0.8.0. | 8f039439-6b74-4203-9559-e21f717e31c3 | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 17 | `from qiskit.algorithms import VQE` | Deprecation -> Functions in qiskit.algorithms will be removed following the removals of qiskit.algorithms and qiskit.opflow in Qiskit 1.0. | d7538a7d-ba0b-421e-b071-75f53af32e7f | qiskit.algorithms.VQE | `from qiskit_algorithms import VQE` |
| 19 | `from qiskit import SPSA` | Deprecation -> Functions in qiskit.algorithms will be removed following the removals of qiskit.algorithms and qiskit.opflow in Qiskit 1.0. | d7538a7d-ba0b-421e-b071-75f53af32e7f | qiskit.SPSA | `from qiskit_algorithms.optimizers import SPSA` |


```python
from qiskit import QuantumCircuit, transpile
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import AerSimulator
backend = AerSimulator()

transpiled_qc = transpile(qc, backend)
job = backend.run(transpiled_qc, shots=1000)

from qiskit.visualization import plot_histogram
plot_histogram(job.result().get_counts(qc))

from qiskit_algorithms import VQE
from qiskit.circuit.library import TwoLocal
from qiskit_algorithms.optimizers import SPSA
vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())
```