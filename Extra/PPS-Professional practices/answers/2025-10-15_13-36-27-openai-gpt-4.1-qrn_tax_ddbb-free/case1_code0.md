| Line | Code | Scenario | Reference | Artifact | Refactoring | 
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 5 | `from qiskit.qasm import Qasm` | Removal -> Qiskit.qasm.Qasm class removed in 1.0.0 | qrn_tax_ddbb--441e2a2b-34b7-4b6e-992c-4acae314d5c8 | qiskit.qasm.Qasm |  |
| 6 | `from qiskit.algorithms import VQE` | Migration -> algorithms module moved to qiskit.algorithms.minimum_eigensolvers | qrn_tax_ddbb--4992f00d-3b9c-41b7-8bcf-a48e7574baa7 | qiskit.algorithms.VQE | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 7 | `from qiskit import qasm2 as qasm` | Migration -> qasm2 moved in Qiskit 1.0 | qrn_tax_ddbb--3a5eb881-2215-47c6-bbde-cd6d0e768938 | qiskit.qasm2 |  |


```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit.algorithms.minimum_eigensolvers import VQE

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```