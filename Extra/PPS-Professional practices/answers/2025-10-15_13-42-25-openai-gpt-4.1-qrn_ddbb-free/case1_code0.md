| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 4 | from qiskit.qasm import Qasm | Removal -> The Qasm class is removed from qiskit.qasm in Qiskit 1.0.0 | qrn_notax_ddbb--acf735c2-a56e-4b40-84fb-6168b4aef68f | qiskit.qasm.Qasm |  | 
| 6 | from qiskit import qasm2 as qasm | Removal -> qasm2 module has been removed in Qiskit 1.0.0 | qrn_notax_ddbb--57d0c7d8-8553-44dc-b109-6d5375336bca | qiskit.qasm2 |  | 

```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit.algorithms import VQE

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```