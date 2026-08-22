| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> Deprecation of qiskit.qasm module | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | 16 | qiskit.qasm | |
| 5 | `from qiskit.algorithms import VQE` | Deprecation -> The `qiskit.algorithms` module has been removed. | * | internal | qiskit.algorithms | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 6 | `from qiskit import qasm2 as qasm` | Deprecation -> Deprecation of qiskit.qasm module | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | 16 | qiskit.qasm | `import qiskit.qasm2 as qasm` |


```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit.algorithms.minimum_eigensolvers import VQE
import qiskit.qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```