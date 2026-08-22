| Line | Code                                 | Scenario                                     | Scenario Id | Reference                              | Artifact     | Refactoring                               |
| :---: | :----------------------------------- | :------------------------------------------- | :---------: | :------------------------------------- | :----------- | :---------------------------------------- |
| 4     | from qiskit.qasm import Qasm         | Deprecation -> qiskit.qasm.Qasm is deprecated | *           | Internal Knowledge                     | qiskit.qasm  |                                           |
| 5     | from qiskit.algorithms import VQE    | Deprecation -> qiskit.algorithms.VQE is deprecated | 1           | 3e8f5d3f-47c1-432f-9914-32f3e02657f5 | qiskit.algorithms |                                           |
| 11    | qasm.dump(qc, file_out)              | Updated -> qasm.dump to qiskit.qasm.dump     | 2           | 5a7d1a3e-8c1b-4b2a-8f7d-5c7b6a8e9d0f | qiskit.qasm.dump | `qiskit.qasm.dump(qc, file_out)`            |
| 12    | qiskit.assembler.run_assembler(transpiled_circuits, backend) | Updated -> qiskit.assembler.run_assembler is deprecated | 5 | 7e9a2b8c-1e9d-4a2b-8f7c-5d6e7a8b9c0d | qiskit.assembler |                                           |


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

# print
print("work done !")
```