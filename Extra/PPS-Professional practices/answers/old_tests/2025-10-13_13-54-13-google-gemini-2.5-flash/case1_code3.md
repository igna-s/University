| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |  
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |  
| 3 | from qiskit import QuantumCircuit, execute, Aer, qasm | Deprecation -> Aer import from qiskit deprecated | * | Internal Knowledge | Aer | from qiskit import QuantumCircuit, execute |  
| 3 | from qiskit import QuantumCircuit, execute, Aer, qasm | Deprecation -> qasm import is deprecated | * | Internal Knowledge | qasm |  |  

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit, execute
from qiskit.providers.aer import Aer
import matplotlib.pyplot as plt
from utils import getJob

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = Aer.get_backend('aer_simulator')
job = getJob(qc, backend, 1000)
result = job.result().get_counts(qc)
plt.show()
```