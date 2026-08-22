| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 3 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> qiskit.tools.events module is deprecated | IK | qiskit.tools.events |  |  
| 2 | `from qiskit import QuantumCircuit` |  | IK | qiskit |  |  
| 4 | `qc = QuantumCircuit(2)` |  | IK | QuantumCircuit |  |  
| 5 | `qc.h(0)` |  | IK | qc.h |  |  
| 6 | `qc.cx(0, 1)` |  | IK | qc.cx |  |  
| 7 | `qc.measure_all()` |  | IK | qc.measure_all |  |  
| 9 | `job = createBackendAndrunJob()` |  | IK | createBackendAndrunJob |  |  
| 10 | `TextProgressBar().update(job)` | Deprecation -> TextProgressBar functionality should be replaced | IK | TextProgressBar |  |  
| 11 | `result = job.result()` |  | IK | job.result |  |  
| 12 | `counts = result.get_counts()` |  | IK | result.get_counts |  |  

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