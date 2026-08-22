| Line | Code                                     | Scenario                                             | Scenario Id | Reference                                | Artifact        | Refactoring                           |
| :--: | :--------------------------------------- | :--------------------------------------------------- | :---------: | :--------------------------------------- | :-------------- | :------------------------------------ |
| 3    | `from qiskit import Aer`                 | Deprecation -> Aer provider                          |      1      | 7d0f7b01-b57c-48a2-9e42-33581455f19f | Aer             | `from qiskit.providers.basic_provider import BasicSimulator` |
| 4    | `from qiskit import qasm`                | Deprecation -> qasm module                           |      7      | f98f4b1b-9e07-405c-8c2f-4401e623286f | qiskit.qasm     | `from qiskit.qasm3 import dumps`      |
| 7    | `qc = QuantumCircuit(2, 2)`              | Updated -> QuantumCircuit constructor               |     25      | 12c83a5a-c28d-4986-acc2-4db931c4c15a | QuantumCircuit  | `qc = QuantumCircuit(2, 2)`           |
| 8    | `qc.h(0)`                                | Updated -> H gate                                    |     25      | 12c83a5a-c28d-4986-acc2-4db931c4c15a | qc.h            | `qc.h(0)`                             |
| 9    | `qc.cx(0, 1)`                            | Updated -> CX gate                                   |     25      | 12c83a5a-c28d-4986-acc2-4db931c4c15a | qc.cx           | `qc.cx(0, 1)`                         |
| 10   | `qc.measure(0, 0)`                       | Updated -> Measure instruction                       |     25      | 12c83a5a-c28d-4986-acc2-4db931c4c15a | qc.measure      | `qc.measure(0, 0)`                    |
| 11   | `qc.measure(1, 1)`                       | Updated -> Measure instruction                       |     25      | 12c83a5a-c28d-4986-acc2-4db931c4c15a | qc.measure      | `qc.measure(1, 1)`                    |


```python
    import os
from qiskit import QuantumCircuit   # type: ignore
from qiskit.providers.basic_provider import BasicSimulator
from qiskit.qasm3 import dumps
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```