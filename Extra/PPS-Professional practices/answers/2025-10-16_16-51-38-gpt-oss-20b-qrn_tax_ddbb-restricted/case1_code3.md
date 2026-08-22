Line | Code | Scenario | Reference | Artifact | Refactoring
--- | --- | --- | --- | --- | ---
3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation → `execute()` function is deprecated | 48a35b67-b938-487b-aef2-7b4596ff4105 | `qiskit.execute` | Remove `execute` from the import list.
3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation → `qiskit.Aer` object is deprecated | 4e1a7f69-eeb4-4a93-9f27-322819438bf4 | `qiskit.Aer` | Replace `Aer` import with `from qiskit_aer import AerSimulator`.
12 | `backend = Aer.get_backend('aer_simulator')` | Deprecation → `Aer.get_backend` is deprecated; use `AerSimulator()` instead | 4e1a7f69-eeb4-4a93-9f27-322819438bf4 | `Aer.get_backend` | `backend = AerSimulator()`  

```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
import matplotlib.pyplot as plt
from utils import getJob

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = AerSimulator()
job = getJob(qc, backend, 1000)
result = job.result().get_counts(qc)
plt.show()
```