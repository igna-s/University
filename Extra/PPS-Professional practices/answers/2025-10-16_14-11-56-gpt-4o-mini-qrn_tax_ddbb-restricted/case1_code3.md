| Line | Code                                                         | Scenario                                                                                      | Reference                                                     | Artifact                                      | Refactoring                                                                      |
|:----:|:------------------------------------------------------------|:----------------------------------------------------------------------------------------------|:--------------------------------------------------------------|:----------------------------------------------|:----------------------------------------------------------------------------------|
| 3   | `from qiskit import QuantumCircuit, execute, Aer, qasm`    | Deprecation -> qiskit.Aer object is deprecated                                              | qrn_tax_ddbb-7b75a686-f0cf-48c9-89a9-352c0dcfe2d4            | qiskit.Aer                                  | `from qiskit_aer import Aer`                                                     |
| 4   | `import matplotlib.pyplot as plt`                            | (optional)                                                                                   | IK                                                           | matplotlib.pyplot                             |                                                                                |
| 9   | `backend = Aer.get_backend('aer_simulator')`               | Migration -> Use `BasicAer` provider and `Basic Simulator`                                  | qrn_tax_ddbb-4e1a7f69-eeb4-4a93-9f27-322819438bf4            | Aer.get_backend('aer_simulator')            | `backend = BasicProvider().get_backend('basic_simulator')`                         |
| 12  | `result = job.result().get_counts(qc)`                      | Deprecation -> job.result().get_counts() deprecated                                        | qrn_tax_ddbb-6ecf0d75-110b-4dc1-8d77-d73f6b1eadb5           | job.result                                   | `result = job.result().get_counts(qc)` should stay as is                      |
| 12  | `plt.show()`                                               | Updated -> job.result() was replaced                                                          | IK                                                           | plt.show                                     | `plt.plot(result)` but details depend on further libraries                       |

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit, execute
from qiskit_aer import Aer
import matplotlib.pyplot as plt
from utils import getJob

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = Aer.get_backend('basic_simulator')
job = getJob(qc, backend, 1000)
result = job.result().get_counts(qc)
plt.show()
```