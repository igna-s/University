| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> qiskit.qasm module is deprecated | qrn_tax_ddbb-8c684429-f46f-4ea3-9bde-e99f63908292 | qiskit.qasm | `from qiskit import qasm2` |
| 7 | `from qiskit import qasm` | Structural change -> import/change to use new qasm2 module | qrn_tax_ddbb-8c684429-f46f-4ea3-9bde-e99f63908292 | qiskit.qasm | `from qiskit import qasm2` |
| 12 | `qc.measure(1, 1)` | New feature -> deprecated QuantumCircuit.qasm method | qrn_tax_ddbb-5a6d002f-95c2-4460-89f5-305ef4b7d4f3 | QuantumCircuit.qasm | Use `qasm2.dump()` or `qasm2.dumps()` instead of `qc.qasm()` for QASM representation |
| 12 | `qc.measure(0, 0)` | New feature -> deprecated QuantumCircuit.qasm method | qrn_tax_ddbb-5a6d002f-95c2-4460-89f5-305ef4b7d4f3 | QuantumCircuit.qasm | Use `qasm2.dump()` or `qasm2.dumps()` instead of `qc.qasm()` for QASM representation |

```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit import qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```