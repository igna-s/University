| Line | Code                                               | Scenario                                           | Reference                                   | Artifact                       | Refactoring                                     |
| :--: | :---                                              | :-------                                          | :-------                                   | :-------                       | :----------                                    |
| 5    | `from qiskit import QuantumCircuit`               | Import Path Change -> qiskit.providers.aer is deprecated | qrn_notax_ddbb-508fb6f3-cdfc-4b96-ad81-f550801dbe2f | qiskit.providers.aer           | `from qiskit import QuantumCircuit`            |
| 6    | `qc = QuantumCircuit(2, 2)`                       | Updated -> initialize a new QuantumCircuit object with parameters | IK                                         | QuantumCircuit                 | `qc = QuantumCircuit(2, 2)`                    |
| 7    | `qc.h(0)`                                         | Updated -> apply a Hadamard gate to the first qubit | IK                                         | QuantumCircuit                 | `qc.h(0)`                                     |
| 8    | `qc.cx(0, 1)`                                     | Updated -> apply a CNOT gate from qubit 0 to qubit 1 | IK                                         | QuantumCircuit                 | `qc.cx(0, 1)`                                   |
| 9    | `qc.measure(0, 0)`                                | Updated -> measure the first qubit to classical bit 0 | IK                                         | QuantumCircuit                 | `qc.measure(0, 0)`                              |
| 10   | `qc.measure(1, 1)`                                | Updated -> measure the second qubit to classical bit 1 | IK                                         | QuantumCircuit                 | `qc.measure(1, 1)`                              |
| 12   | `print("work done !")`                            | Not required                                    | IK                                         | print                         | `print("work done !")`                         |

```python
'''
Test code for importing and 
using libraries that are not related to Qiskit.
'''

# requeriments imports

# import os functionalities
import os

# import QuantumCircuit functionalities
from qiskit import QuantumCircuit

# import datetime functionalities
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