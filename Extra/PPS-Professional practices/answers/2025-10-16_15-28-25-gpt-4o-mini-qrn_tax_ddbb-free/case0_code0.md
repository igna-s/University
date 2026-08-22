| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 9 | `from qiskit import QuantumCircuit` | Deprecation -> The qiskit.tools module is deprecated | qrn_tax_ddbb--4bc2d33a-666a-48ed-96d1-b12d38ea3acf | qiskit.tools | `from qiskit.utils import QuantumCircuit` | 
| 19 | `qc = QuantumCircuit(2, 2)` | Updated -> Constructor for QuantumCircuit | IK | QuantumCircuit | `qc = QuantumCircuit(2, 2)` | 
| 21 | `qc.h(0)` | Updated -> Apply Hadamard gate | IK | QuantumCircuit | `qc.h(0)` | 
| 22 | `qc.cx(0, 1)` | Updated -> Apply CNOT gate | IK | QuantumCircuit | `qc.cx(0, 1)` | 
| 23 | `qc.measure(0, 0)` | Updated -> Measure qubit 0 | IK | QuantumCircuit | `qc.measure(0, 0)` | 
| 24 | `qc.measure(1, 1)` | Updated -> Measure qubit 1 | IK | QuantumCircuit | `qc.measure(1, 1)` | 

```python
'''
Test code for importing and 
using libraries that are not related to Qiskit.
'''

# requeriments imports

# import os funcionalidades
import os

# import QuantumCircuit funcionalidades
from qiskit import QuantumCircuit

# import datetime funcionalidades
from datetime import datetime

# create a Quantum Circuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```