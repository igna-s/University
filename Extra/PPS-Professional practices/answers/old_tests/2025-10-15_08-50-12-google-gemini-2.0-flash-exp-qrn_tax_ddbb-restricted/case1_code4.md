| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 10 | `from qiskit import Aer` | Meta-package -> The `qiskit` meta-package is deprecated. | qrn_tax_ddbb-e999940c-c736-44cb-9743-64c91151f931 | qiskit | `from qiskit_aer import Aer` |
| 11 | `backend = Aer.get_backend('aer_simulator')` | Package change -> `Aer.get_backend` is deprecated and replaced with `AerSimulator()` | qrn_tax_ddbb-29a34970-b973-4771-b668-c3995893f573 | Aer.get_backend | `backend = Aer.get_backend('simulator')` |
| 11 | `backend = Aer.get_backend('aer_simulator')` |  Deprecated -> Using a string literal to specify a backend is deprecated. | qrn_tax_ddbb-effccca9-2c1b-4974-b322-959e1f195934 | Aer.get_backend | `backend = Aer.get_backend('aer_simulator')` |
| 14 | `from utils import getJob` | Removed -> The utils module has been removed | IK | utils |  |

```python
import os

from qiskit import QuantumCircuit 
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import Aer
backend = Aer.get_backend('aer_simulator')

from datetime import datetime
import matplotlib.pyplot as plt
qc.draw(output='mpl')
plt.show()
```