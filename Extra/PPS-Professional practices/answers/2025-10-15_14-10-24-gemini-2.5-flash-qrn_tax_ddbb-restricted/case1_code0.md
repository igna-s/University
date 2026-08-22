| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. It will be removed in the Qiskit 1.0.0 release. | qrn_tax_ddbb-d81c6f52-5772-420b-9094-0c9d7d5b64a2 | qiskit.qasm | |
| 5 | `from qiskit.algorithms import VQE` | Deprecation -> Importing from qiskit.algorithms is deprecated. The algorithms module has been moved to a separate package. | IK | qiskit.algorithms | `from qiskit_algorithms import VQE` |
| 6 | `from qiskit import qasm2 as qasm` | Deprecation -> The legacy OpenQASM 2 parser has been superseded by the qiskit.qasm2 module which provides a faster more correct parser for OpenQASM 2. | qrn_tax_ddbb-d81c6f52-5772-420b-9094-0c9d7d5b64a2 | qiskit.qasm2 | `from qiskit.qasm import QASM2Classes` |


```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit_algorithms import VQE
from qiskit.qasm import QASM2Classes

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```