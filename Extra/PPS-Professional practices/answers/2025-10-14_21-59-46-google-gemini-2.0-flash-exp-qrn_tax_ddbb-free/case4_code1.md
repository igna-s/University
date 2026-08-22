| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from utils import createBackendAndrunJob` | Removal -> Module `qiskit.tools` has been removed | IK | qiskit.tools | Remove this line |
| 6 | `job = createBackendAndrunJob()` | Removal -> Module `qiskit.tools` has been removed | IK | qiskit.tools |  Replace with appropriate backend and job execution |
| 8 | `from qiskit.tools.events import TextProgressBar` | Removal -> Module `qiskit.tools` has been removed | IK | qiskit.tools | Remove this line |
| 10 | `TextProgressBar().update(job)` | Removal -> Module `qiskit.tools` has been removed | IK | qiskit.tools | Remove this line |

```python
from qiskit import QuantumCircuit
from qiskit import Aer, execute

qc = QuantumCircuit(2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

backend = Aer.get_backend('qasm_simulator')
job = execute(qc, backend, shots=1024)

result = job.result()
counts = result.get_counts()
```