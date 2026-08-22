| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 2 | `from qiskit import QuantumCircuit` | Updated -> importing quantum components must be done from `qiskit.quantum_circuit` instead of `qiskit` | qrn_notax_ddbb--98ed0e4a-c3d2-4c4f-93a7-42ebe62e7869 | qiskit.quantum_circuit | `from qiskit.quantum_circuit import QuantumCircuit` | 
| 3 | `from qiskit import Aer` | Deprecated -> the Aer module is now imported from `qiskit_aer`, not `qiskit` | qrn_notax_ddbb--4194776d-c578-4b79-8dc6-9c5e286bc808 | qiskit.Aer | `from qiskit_aer import Aer` | 
| 4 | `from qiskit import qasm` | Deprecated -> qiskit.qasm has been deprecated, no longer required | qrn_notax_ddbb--e6569a55-d255-4f0b-8b49-1e0efd89380a | qiskit.qasm |  | 

```python  
import os
from qiskit.quantum_circuit import QuantumCircuit
from qiskit_aer import Aer
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```