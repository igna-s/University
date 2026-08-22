| Line | Code                                                   | Scenario                                 | Reference                                     | Artifact                 | Refactoring                                |
| :--: | :---------------------------------------------------- | :--------------------------------------- | :------------------------------------------- | :----------------------- | :----------------------------------------- |
| 2    | `from qiskit.tools.events import TextProgressBar`    | Deprecation -> qiskit.tools.events     | b8601747-ed0a-4488-b998-af8f180f99be        | qiskit.tools.events      |                                           |
| 3    | `qc = QuantumCircuit(2)`                             |                                           | IK                                           | QuantumCircuit           |                                           |
| 4    | `qc.h(0)`                                            |                                           | IK                                           | QuantumCircuit           |                                           |
| 5    | `qc.cx(0, 1)`                                       |                                           | IK                                           | QuantumCircuit           |                                           |
| 6    | `qc.measure_all()`                                   |                                           | IK                                           | QuantumCircuit           |                                           |
| 8    | `job = createBackendAndrunJob()`                     |                                           | IK                                           | createBackendAndrunJob  |                                           |
| 10   | `result = job.result()`                              |                                           | IK                                           | job.result               |                                           |
| 11   | `counts = result.get_counts()`                       |                                           | IK                                           | result.get_counts        |                                           |

```python
from qiskit import QuantumCircuit
from utils import createBackendAndrunJob

qc = QuantumCircuit(2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

job = createBackendAndrunJob()

result = job.result()
counts = result.get_counts()
```