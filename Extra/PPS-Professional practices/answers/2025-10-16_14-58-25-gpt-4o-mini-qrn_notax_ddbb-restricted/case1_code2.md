| Line | Code                                               | Scenario                                                                                              | Reference                                                 | Artifact                  | Refactoring                                                                                         |
|:----:|:--------------------------------------------------|:------------------------------------------------------------------------------------------------------|:---------------------------------------------------------|:--------------------------|:----------------------------------------------------------------------------------------------------|
| 5    | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> execute() function is deprecated                                  | qrn_notax_ddbb-7dcaf104-d552-4d87-994a-c7691846d9a9     | qiskit                    | `from qiskit import QuantumCircuit`<br>`from qiskit.primitives import BackendSampler`<br>`sampler = BackendSampler(getMyBackend())`<br>`job = sampler.run(qc)` |
| 11   | `job = execute(qc, getMyBackend(), shots=1000)`   | Update -> execute() now requires direct backend.run()                                       | qrn_notax_ddbb-7dcaf104-d552-4d87-994a-c7691846d9a9     | qiskit                    | `new_circuit = transpile(qc, getMyBackend())`<br>`job = getMyBackend().run(new_circuit, shots=1000)` |
| 12   | `result = job.result().get_counts(qc)`             | (optional)                                                                        | IK                                                       | result                    | `result = job.get_counts(qc)` (already valid)                                                     |
| 13   | `plt.show()`                                        | (optional)                                                                        | IK                                                       | matplotlib.pyplot         | (remains)                                                                                           |

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit
from qiskit.primitives import BackendSampler
import matplotlib.pyplot as plt
from utils import getMyBackend

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

sampler = BackendSampler(getMyBackend())
job = sampler.run(qc)

result = job.get_counts(qc)
plt.show()
```