| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 11 | `from qiskit import QuantumCircuit` | Import relocation: `qiskit.circuit.QuantumCircuit` is deprecated | 20 | 30b6e54c-0842-4f7e-8440-63033636c106 | qiskit | `from qiskit.circuit import QuantumCircuit` |
| 17 | `qc = QuantumCircuit(2, 2)` | Method relocation: `QuantumCircuit.h` is deprecated | 20 | 30b6e54c-0842-4f7e-8440-63033636c106 | qiskit.circuit.QuantumCircuit | `qc = QuantumCircuit(2, 2)` |
| 18 | `qc.h(0)` | Method relocation: `QuantumCircuit.h` is deprecated | 20 | 30b6e54c-0842-4f7e-8440-63033636c106 | qiskit.circuit.QuantumCircuit | `qc.h(0)` |
| 19 | `qc.cx(0, 1)` | Method relocation: `QuantumCircuit.cx` is deprecated | 20 | 30b6e54c-0842-4f7e-8440-63033636c106 | qiskit.circuit.QuantumCircuit | `qc.cx(0, 1)` |
| 20 | `qc.measure(0, 0)` | Method relocation: `QuantumCircuit.measure` is deprecated | 20 | 30b6e54c-0842-4f7e-8440-63033636c106 | qiskit.circuit.QuantumCircuit | `qc.measure(0, 0)` |
| 21 | `qc.measure(1, 1)` | Method relocation: `QuantumCircuit.measure` is deprecated | 20 | 30b6e54c-0842-4f7e-8440-63033636c106 | qiskit.circuit.QuantumCircuit | `qc.measure(1, 1)` |


```python
    '''
    Test code for importing and 
    using libraries that are not related to Qiskit.
'''


# requeriments imports

# import os funcionalities
import os

# import QuantumCircuit funcionalities
from qiskit.circuit import QuantumCircuit

# import datetime funcionalities
from datetime import datetime

# create a Quantum Circuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```