| Line | Code                                                                                      | Scenario                                                              | Reference                                               | Artifact                                            | Refactoring                                                                                                                                                      |
| :--: | :---------------------------------------------------------------------------------------- | :-------------------------------------------------------------------- | :----------------------------------------------------- | :-------------------------------------------------- | :--------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1    | `from qiskit import QuantumCircuit`                                                     | Deprecation -> qiskit.Aer module in qiskit.providers has been deprecated                   | qrn_notax_ddbb-9c5ff30f-89b3-477d-8e94-7d231d6ab6bd | qiskit                                             | `from qiskit import QuantumCircuit`                                                                                                                          |
| 7    | `from qiskit import Aer`                                                                 | Import change -> Aer has been moved to qiskit_aer                     | qrn_notax_ddbb-bd1ba6c7-3850-405b-8f3c-1c2d0a9e773f | qiskit                                             | `from qiskit_aer import Aer`                                                                                                                                 |
| 9    | `job = execute(qc, backend, shots=1000)`                                               | Deprecation -> execute() function has been deprecated                   | qrn_notax_ddbb-7dcaf104-d552-4d87-994a-c7691846d9a9 | qiskit                                             | `new_circuit = transpile(qc, backend); job = backend.run(new_circuit, shots=1000)`                                                                          |
| 12   | `from qiskit.tools.visualization import plot_histogram`                                  | Deprecation -> qiskit.tools.visualization module deprecated               | qrn_notax_ddbb-4194776d-c578-4b79-8dc6-9c5e286bc808 | qiskit.tools                                      | `from qiskit.visualization import plot_histogram`                                                                                                           |
| 16   | `from qiskit.algorithms import VQE`                                                     | Moving module -> qiskit.algorithms has migrated to qiskit.circuit      | qrn_notax_ddbb-8fa78c41-fe65-4855-a211-6812b683b158 | qiskit.algorithms                                  | `from qiskit.circuit import VQE`                                                                                                                              |
| 17   | `from qiskit.circuit.library import TwoLocal`                                           | Moving module -> qiskit.circuit.library has been restructured            | qrn_notax_ddbb-8fa78c41-fe65-4855-a211-6812b683b158 | qiskit.circuit.library                             | `from qiskit.circuit.library import TwoLocal`                                                                                                              |
| 18   | `from qiskit import SPSA`                                                                 | Deprecation -> SPSA module in qiskit has been deprecated                  | qrn_notax_ddbb-505b7b12-e076-47fe-9c06-0f458d519f1a | qiskit                                             | `from qiskit.primitives import SPSA`                                                                                                                       |

```python
from qiskit import QuantumCircuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import Aer
backend = Aer.get_backend('aer_simulator')

from qiskit import transpile
new_circuit = transpile(qc, backend)
job = backend.run(new_circuit, shots=1000)

from qiskit.visualization import plot_histogram
plot_histogram(job.result().get_counts(qc))

from qiskit.circuit import VQE
from qiskit.circuit.library import TwoLocal
from qiskit.primitives import SPSA
vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())
```