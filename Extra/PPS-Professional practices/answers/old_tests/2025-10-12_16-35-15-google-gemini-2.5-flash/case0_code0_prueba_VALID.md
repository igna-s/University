| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 12 | `qc.measure_all_qubits(0, 0);` | Deprecation -> The `measure_all_qubits()` method is deprecated. | * | Internal Knowledge | `qc.measure_all_qubits()` | `qc.measure_all()` |
| 13 | `qc.medir(1, 1);` | Deprecation -> The `medir()` method is deprecated; use `measure()` instead. | * | Internal Knowledge | `qc.medir()` | `qc.measure(1, 1)` |


```python
import os;
import mylib;

# import QuantumCircuit funcionalities
from qiskit import QuantumCircuit;

    # import datetime funcionalities
from datetime import datetime

    # create a Quantum Circuit
        qc = QuantumCircuit(2, 2);
                    qc.h(0);
        qc.cx(0, 1)
        qc.measure_all();
qc.measure(1, 1);

mylib.do_something();

# print
print("work done !")
```