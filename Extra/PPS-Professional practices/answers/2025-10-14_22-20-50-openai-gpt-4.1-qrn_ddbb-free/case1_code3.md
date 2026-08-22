| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Removal -> qasm import is removed from main qiskit namespace | qrn_ddbb-6f908222edd54b1fa54b1113da0c0243 | qiskit.qasm | (remove `qasm` import) | 
| 7 | `backend = Aer.get_backend('aer_simulator')` | Change -> 'aer_simulator' not available as backend, use AerSimulator | qrn_ddbb-34caf7e338de4fb38e6b3524d8bb219c | Aer | `from qiskit_aer import AerSimulator`<br>`backend = AerSimulator()` | 

```python  
import os
from datetime import datetime
from qiskit import QuantumCircuit, execute, Aer
import matplotlib.pyplot as plt
from utils import getJob
from qiskit_aer import AerSimulator

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