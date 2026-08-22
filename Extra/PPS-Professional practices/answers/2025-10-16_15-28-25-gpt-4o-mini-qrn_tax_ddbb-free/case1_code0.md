| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> The qiskit.qasm module is deprecated | qrn_tax_ddbb--d5bc1bb4-7acd-47c5-be94-ef19074cbdcc | qiskit.qasm | `from qiskit import qasm2` |
| 8 | `from qiskit import qasm` | Deprecation -> The qiskit import should be updated to qiskit.qasm2 | qrn_tax_ddbb--f24d40d4-9a98-4431-85f5-3e6f98fee373 | | Do not include this line as qasm2 will be used instead. |
| 10 | `qc.measure(1, 1)` | Deprecation -> QuantumCircuit.qasm() method is deprecated | qrn_tax_ddbb--f24d40d4-9a98-4431-85f5-3e6f98fee373 | QuantumCircuit.qasm() | Do not use measure with qasm method. Instead use `qasm2.dump()`.| 

```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit import qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)

# print
print("work done !")
```