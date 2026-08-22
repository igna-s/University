| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> The `qiskit.qasm` module is deprecated. | * | 2edcf1ef-edac-448b-be69-fe31c5179872 | qiskit.qasm.Qasm | |
| 5 | `from qiskit.algorithms import VQE` | Deprecation -> The `qiskit.algorithms` module has been moved to the `qiskit_algorithms` package. | * | Internal Knowledge | qiskit.algorithms.VQE | `from qiskit_algorithms import VQE` |
| 6 | `from qiskit import qasm2 as qasm` | Usage -> The import path for `qiskit.qasm2` is incorrect. | * | Internal Knowledge | qiskit.qasm2 | `import qiskit.qasm2 as qasm` |


```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit_algorithms import VQE
import qiskit.qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```