**Table of changes**

| Line | Code | Scenario | Reference | Artifact | Refactoring |
|------|------|----------|-----------|----------|-------------|
| 7 | `from qiskit import Aer` | Deprecation → Aer import is deprecated | IK | Aer | `from qiskit_aer import AerSimulator` |
| 8 | `backend = Aer.get_backend('aer_simulator')` | Deprecation → Aer backend retrieval is deprecated | IK | Aer | `backend = AerSimulator()` |
| 11 | `from qiskit.tools.visualization import plot_histogram` | Deprecation → qiskit.tools.visualization is deprecated | IK | plot_histogram | `from qiskit.visualization import plot_histogram` |
| 15 | `from qiskit import SPSA` | Deprecation → SPSA import path changed | IK | SPSA | `from qiskit.algorithms.optimizers import SPSA` |

---

**Refactored code**

```python
from qiskit import QuantumCircuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import AerSimulator
backend = AerSimulator()

from qiskit import execute
job = execute(qc, backend, shots=1000)

from qiskit.visualization import plot_histogram
plot_histogram(job.result().get_counts(qc))

from qiskit.algorithms import VQE
from qiskit.circuit.library import TwoLocal
from qiskit.algorithms.optimizers import SPSA
vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())
```
