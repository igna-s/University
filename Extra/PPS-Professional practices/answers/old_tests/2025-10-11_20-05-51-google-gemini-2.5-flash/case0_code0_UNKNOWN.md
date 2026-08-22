| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 8 | `import os` | N/A | * | internal | os | `import os` |
| 11 | `from qiskit import QuantumCircuit` | Deprecation -> The `qiskit.QuantumCircuit` class has been moved to `qiskit.circuit.QuantumCircuit` | qiskit.circuit.QuantumCircuit | 02c83a5a-c28d-46c6-acc2-4db931c4c15a | qiskit.QuantumCircuit | `from qiskit.circuit import QuantumCircuit` |
| 14 | `from datetime import datetime` | N/A | * | internal | datetime | `from datetime import datetime` |
| 17 | `qc = QuantumCircuit(2, 2)` | N/A | * | internal | QuantumCircuit | `qc = QuantumCircuit(2, 2)` |
| 18 | `qc.h(0)` | N/A | * | internal | h | `qc.h(0)` |
| 19 | `qc.cx(0, 1)` | N/A | * | internal | cx | `qc.cx(0, 1)` |
| 20 | `qc.measure(0, 0)` | N/A | * | internal | measure | `qc.measure(0, 0)` |
| 21 | `qc.measure(1, 1)` | N/A | * | internal | measure | `qc.measure(1, 1)` |
| 24 | `print("work done !")` | N/A | * | internal | print | `print("work done !")` |

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