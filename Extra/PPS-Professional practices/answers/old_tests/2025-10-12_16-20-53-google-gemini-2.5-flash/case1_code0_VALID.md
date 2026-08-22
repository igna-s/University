| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> Deprecation of qiskit.qasm module | 14 | 3c189cb9-1315-4402-b141-a88a25a253f2 | qiskit.qasm | |
| 5 | `from qiskit.algorithms import VQE` | Deprecation -> The `qiskit.algorithms` module is deprecated | * | Internal Knowledge | qiskit.algorithms.VQE | `from qiskit.primitives import VQE` |
| 6 | `from qiskit import qasm2 as qasm` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. It will be removed in the Qiskit 1.0.0 release. The legacy OpenQASM 2 parser has been superseded by the qiskit.qasm2 module which provides a faster more correct parser for OpenQASM 2. | * | 3b865a5c-0601-4d2f-8255-3c4db3ac0b8c | qiskit.qasm | `import qiskit.qasm2 as qasm` |


```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit.primitives import VQE
import qiskit.qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```