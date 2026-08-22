| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 5 | `from qiskit import QuantumCircuit` | Deprecation -> The qiskit.qasm module is deprecated | qrn_tax_ddbb-73416f9b-79f5-487c-8137-c658a216ef0a | qiskit.qasm | `from qiskit import qasm2` |
| 6 | `from datetime import datetime` | Deprecation -> The qiskit.converters.ast_to_dag function is deprecated | qrn_tax_ddbb-3d29b53a-f154-48e4-b303-e2678d10eab0 | qiskit.converters | `from qiskit import circuit_to_dag` |
| 10 | `qc.measure(0, 0)` | Deprecation -> The QuantumCircuit.qasm() method is deprecated | qrn_tax_ddbb-e85d1110-0e45-4ea8-bb9c-e5d59f068a3a | QuantumCircuit | `qasm2.dump()` or `qasm2.dumps()` |

```python
'''
Test code for importing and 
using libraries that are not related to Qiskit.
'''

import os
from qiskit import qasm2
from datetime import datetime

# create a Quantum Circuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(1, 1)

# print
print("work done !")
```