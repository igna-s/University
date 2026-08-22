| Line | Code                                                     | Scenario                                                           | Reference                                                   | Artifact                  | Refactoring                                                   |
| :--: | :------------------------------------------------------ | :---------------------------------------------------------------- | :-------------------------------------------------------- | :----------------------- | :---------------------------------------------------------- |
| 5    | `from qiskit import QuantumCircuit`                     | Import -> `from qiskit.providers.basic_provider import BasicProvider` | qrn_notax_ddbb-98ed0e4a-c3d2-4c4f-93a7-42ebe62e7869     | qiskit.providers.basic_provider | `from qiskit import BasicProvider`                          |
| 10   | `qc = QuantumCircuit(2, 2)`                             | Update -> use BasicProvider and its backend                       | qrn_notax_ddbb-9c5ff30f-89b3-477d-8e94-7d231d6ab6bd      | QuantumCircuit           | `provider = BasicProvider(); backend = provider.get_backend('basic_simulator'); qc = QuantumCircuit(2, 2)` |
| 11   | `qc.h(0)`                                              |                                                              | IK                                                       | QuantumCircuit           | `qc.h(0)`                                                  |
| 12   | `qc.cx(0, 1)`                                          |                                                              | IK                                                       | QuantumCircuit           | `qc.cx(0, 1)`                                              |
| 13   | `qc.measure(0, 0)`                                     |                                                              | IK                                                       | QuantumCircuit           | `qc.measure(0, 0)`                                         |
| 14   | `qc.measure(1, 1)`                                     |                                                              | IK                                                       | QuantumCircuit           | `qc.measure(1, 1)`                                         |
| 16   | `print("work done !")`                                 |                                                              | IK                                                       | print                   | `print("work done !")`                                     |

```python
'''
Test code for importing and 
using libraries that are not related to Qiskit.
'''

# requeriments imports

# import os functionalities
import os

# import BasicProvider functionalities
from qiskit.providers.basic_provider import BasicProvider

# import datetime functionalities
from datetime import datetime

# create a Quantum Circuit
provider = BasicProvider()
backend = provider.get_backend('basic_simulator')
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```