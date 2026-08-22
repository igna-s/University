| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer # type: ignore` | Deprecation -> Deprecation of qiskit.Aer object | 4 | bb13d578-c8e9-44dd-8431-861cea75d5de | qiskit.Aer | `from qiskit_aer import Aer` |
| 4 | `from qiskit import qasm # type: ignore` | Deprecation -> Deprecation of qiskit.qasm module | * | Internal Knowledge | qiskit.qasm | |
| 6 | `qc = QuantumCircuit(2, 2)` | Deprecation -> The `QuantumCircuit` class has been updated and the `QuantumCircuit` constructor no longer implicitly adds classical bits. | * | Internal Knowledge | QuantumCircuit | `qc = QuantumCircuit(2)` |
| 9 | `qc.measure(0, 0)` | Deprecation -> The `measure` method of `QuantumCircuit` now returns a `QuantumCircuit` object directly. | * | Internal Knowledge | qc.measure | `qc.measure([0], [0])` |
| 10 | `qc.measure(1, 1)` | Deprecation -> The `measure` method of `QuantumCircuit` now returns a `QuantumCircuit` object directly. | * | Internal Knowledge | qc.measure | `qc.measure([1], [1])` |


```python
import os
from qiskit import QuantumCircuit
from qiskit_aer import Aer
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0], [0])
qc.measure([1], [1])

print("work done !")
```