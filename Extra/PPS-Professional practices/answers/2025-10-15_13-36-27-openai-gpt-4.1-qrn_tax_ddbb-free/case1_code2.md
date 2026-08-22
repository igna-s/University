| Line | Code                                                        | Scenario                                                        | Reference                                | Artifact                | Refactoring                                            |
| :--: | :---------------------------------------------------------- | :-------------------------------------------------------------- | :---------------------------------------: | :---------------------- | :----------------------------------------------------- |
| 3    | from qiskit import QuantumCircuit, qasm, execute            | Deprecation -> qasm and execute moved (No longer in qiskit root) | qrn_tax_ddbb--40c4226b-ab19-4d9f-903e-6272ac24bbaf | qiskit.qasm, qiskit.execute | from qiskit import QuantumCircuit<br>from qiskit.compiler import assemble<br>from qiskit_ibm_provider import IBMQ<br>from qiskit_aer import Aer |
| 7    | job = execute(qc, getMyBackend(), shots=1000)               | Deprecation -> execute() must be imported from qiskit.primitives or IBMProvider | qrn_tax_ddbb--0aa7e128-4f34-4d91-970d-b2e7f39055cc | qiskit.execute         | See rewritten code below (use Aer/IBMQ + run instead of execute)      |

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit
from qiskit_aer import Aer
import matplotlib.pyplot as plt
from utils import getMyBackend

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = getMyBackend()
job = backend.run(qc, shots=1000)
result = job.result().get_counts(qc)
plt.show()
```