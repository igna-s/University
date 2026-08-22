| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. | a03d6cfd-4c92-4523-a77d-3542afe18906 | qiskit.qasm | |
| 5 | `from qiskit.algorithms import VQE` | Deprecation -> The qiskit.algorithms module is deprecated. | internal | qiskit.algorithms | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 6 | `from qiskit import qasm2 as qasm` | Deprecation -> The QuantumCircuit.qasm() method used to generate a OpenQASM 2 representation of the QuantumCircuit object has been deprecated. | 4bbc9ad5-a04d-4ad1-97e1-83484b7a6eba | qiskit.qasm2 | |


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