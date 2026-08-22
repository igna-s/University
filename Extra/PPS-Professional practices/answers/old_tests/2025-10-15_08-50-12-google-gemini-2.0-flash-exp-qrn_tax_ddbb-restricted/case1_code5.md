| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Aer.get_backend is deprecated | qrn_tax_ddbb-79582c73-655e-425a-8456-22916a491976 | Aer.get_backend | Use AerSimulator() directly. |
| 11 | `from qiskit import execute` | Deprecation -> `execute` is deprecated | qrn_tax_ddbb-39b99432-670f-4493-b66c-47125f868332 | execute | Use `backend.run` instead. |
| 12 | `job = execute(qc, backend, shots=1000)` | Deprecation -> `execute` is deprecated | qrn_tax_ddbb-39b99432-670f-4493-b66c-47125f868332 | execute | Use `backend.run` instead. |
| 14 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> `plot_histogram` is deprecated. | qrn_tax_ddbb-29509695-ebf0-4eb7-95f9-21c455f45994 | qiskit.tools.visualization.plot_histogram | Use `qiskit.visualization.plot_histogram` instead. |
| 15 | `plot_histogram(job.result().get_counts(qc))` | Parameter name change -> `plot_histogram` parameter name `counts` to `data` | qrn_tax_ddbb-29509695-ebf0-4eb7-95f9-21c455f45994 | qiskit.visualization.plot_histogram | `plot_histogram(job.result().get_counts(qc), data=data)` |
| 17 | `from qiskit.algorithms import VQE` | Deprecation -> Class VQE is deprecated | qrn_tax_ddbb-11571b2a-9f41-4805-9491-e94599471ba5 | VQE | Use `qiskit_algorithms.minimum_eigensolvers.VQE` instead. |
| 17 | `from qiskit.algorithms import VQE` | package migration -> the `qiskit.algorithms` package has been migrated to the qiskit-algorithms package. | qrn_tax_ddbb-d80b7119-a99f-4ca0-96fd-45ca1964767a | qiskit.algorithms | Replace `from qiskit.algorithms import...` with `from qiskit_algorithms import ...` |
| 19 | `from qiskit import SPSA` | package migration -> the `qiskit.algorithms` package has been migrated to the qiskit-algorithms package. | qrn_tax_ddbb-d80b7119-a99f-4ca0-96fd-45ca1964767a | qiskit.algorithms | Replace `from qiskit.algorithms import...` with `from qiskit_algorithms import ...` |

```python
from qiskit import QuantumCircuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import AerSimulator
backend = AerSimulator()

from qiskit import transpile, assemble
job = backend.run(transpile(qc, backend), shots=1000)

from qiskit.visualization import plot_histogram
plot_histogram(job.result().get_counts(qc))

from qiskit_algorithms import VQE
from qiskit.circuit.library import TwoLocal
from qiskit.algorithms.optimizers import SPSA
vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())
```