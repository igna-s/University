| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer` | Deprecation -> Use of the qiskit.Aer object is deprecated and will be removed in Qiskit 1.0. You should instead use the same object from the qiskit_aer namespace, which is a drop-in replacement. | qrn_notax_ddbb-4194776d-c578-4b79-8dc6-9c5e286bc808 | qiskit.Aer | `from qiskit_aer import Aer` |
| 4 | `from qiskit import qasm` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. It will be removed in the Qiskit 1.0.0 release. The legacy OpenQASM 2 parser has been superseded by the qiskit.qasm2 module which provides a faster more correct parser for OpenQASM 2. | qrn_notax_ddbb-910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qiskit.qasm | |

```python
import os
from qiskit import QuantumCircuit
from qiskit_aer import Aer
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```