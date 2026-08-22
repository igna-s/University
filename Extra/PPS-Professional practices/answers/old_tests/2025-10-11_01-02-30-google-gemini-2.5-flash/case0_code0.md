| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 10 | `from qiskit import QuantumCircuit` | Deprecation -> If you develop a library based on Qiskit and you still have a dependency on qiskit-terra, you should urgently release a new package that depends only on qiskit. | 49f3bff1-b074-49c3-8c97-f7174d8c9d70 | qiskit | `from qiskit.circuit import QuantumCircuit` |


```python
'''
    Test code for importing and 
    using libraries that are not related to Qiskit.
'''


# requeriments imports

# import os funcionalities
import os

# import QuantumCircuit funcionalities
from qiskit.circuit import QuantumCircuit

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