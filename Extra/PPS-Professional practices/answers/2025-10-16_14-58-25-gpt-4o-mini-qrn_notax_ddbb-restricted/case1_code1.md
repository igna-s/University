| Line | Code | Scenario | Reference | Artifact | Refactoring |  
| :--: | :--- | :------- | :-------: | :------- | :---------- |  
| 2 | `from qiskit import Aer` | Deprecation -> Importing from qiskit.providers.aer is deprecated | qrn_notax_ddbb-4194776d-c578-4b79-8dc6-9c5e286bc808 | qiskit.providers.aer | `from qiskit_aer import Aer` |  

```python  
import os
from qiskit import QuantumCircuit
from qiskit_aer import Aer
from qiskit import qasm
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```