| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 11 | `from qiskit import Aer` |  Deprecation -> Aer provider is deprecated | qrn_tax_ddbb-0c9e619e883ffef48491298923624839 | Aer |  `from qiskit_aer import AerSimulator` |
| 12 | `backend = Aer.get_backend('aer_simulator')` |  Deprecation -> Aer provider is deprecated | qrn_tax_ddbb-0c9e619e883ffef48491298923624839 | Aer | `backend = AerSimulator()` |
| 14 | `from qiskit import execute` | Deprecation -> `execute` is deprecated, use `Sampler` or `Estimator` for stateless execution. | qrn_tax_ddbb-b7ae37805ff7a2242ca8845995f42b17 | execute | `from qiskit.primitives import Sampler, Estimator` |
| 15 | `job = execute(qc, backend, shots=1000)` | Deprecation -> `execute` is deprecated, use `Sampler` or `Estimator` for stateless execution. | qrn_tax_ddbb-b7ae37805ff7a2242ca8845995f42b17 | execute | `sampler = Sampler(backend=backend)`<br>`job = sampler.run(qc, shots=1000)` |
| 17 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> Module moved to `qiskit.visualization` | qrn_tax_ddbb-1f8c3a9f33c4b3012a7934f54f0929ae | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 20 | `from qiskit.algorithms import VQE` | Deprecation -> Class has been deprecated | qrn_tax_ddbb-d3f84f1985b41ca9c9aa6c8759286895 | VQE | `from qiskit_algorithms import VQE` |
| 22 | `from qiskit import SPSA` | Deprecation -> Moved to qiskit_algorithms.optimizers | qrn_tax_ddbb-4e05492531d3c9351aa895195a044685 | SPSA | `from qiskit_algorithms.optimizers import SPSA` |
```python
from qiskit import QuantumCircuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import AerSimulator
backend = AerSimulator()

from qiskit.primitives import Sampler, Estimator
sampler = Sampler(backend=backend)
job = sampler.run(qc, shots=1000)

from qiskit.visualization import plot_histogram
plot_histogram(job.result().get_counts(qc))

from qiskit_algorithms import VQE
from qiskit.circuit.library import TwoLocal
from qiskit_algorithms.optimizers import SPSA
vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())
```