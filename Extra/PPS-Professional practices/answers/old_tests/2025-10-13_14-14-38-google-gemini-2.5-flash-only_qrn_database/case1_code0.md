| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. | 86 | 2edcf1ef-edac-448b-be69-fe31c5179872 | qiskit.qasm | |
| 5 | `from qiskit.algorithms import VQE` | Deprecation -> The qiskit.algorithms module is deprecated. | * | Internal Knowledge | qiskit.algorithms | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 6 | `from qiskit import qasm2 as qasm` | Deprecation -> The QuantumCircuit.qasm() method used to generate a OpenQASM 2 representation of the QuantumCircuit object has been deprecated. | 88 | 4a85ead9-680f-49b5-b1dc-982401b98f61 | qiskit.qasm2 | |


```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit.algorithms.minimum_eigensolvers import VQE

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```