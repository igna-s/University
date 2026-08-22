| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :---------: | :-------: | :-------: | :---------- | 
code fully compatible with version 1.0.0

```python  
    '''
    Test code for importing and 
    using libraries that are not related to Qiskit.
'''


# requeriments imports

# import os funcionalities
import os

# import QuantumCircuit funcionalities
from qiskit import QuantumCircuit

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