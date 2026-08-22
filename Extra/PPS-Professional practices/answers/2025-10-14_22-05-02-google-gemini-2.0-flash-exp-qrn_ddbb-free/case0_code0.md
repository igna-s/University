| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 12 | `from qiskit import QuantumCircuit` | Updated -> Moved to quantum namespace | IK | qiskit | `from qiskit.quantum import QuantumCircuit` |

```python
    '''
    Test code for importing and 
    using libraries that are not related to Qiskit.
'''


# requeriments imports

# import os funcionalities
import os

# import QuantumCircuit funcionalities
from qiskit.quantum import QuantumCircuit

# import datetime funcionalities
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