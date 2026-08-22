```markdown
| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer              # type: ignore` | Deprecation -> Aer import is deprecated | * | Internal Knowledge | Aer | `from qiskit_aer import Aer` |
| 4 | `from qiskit import qasm             # type: ignore` | Removal -> qasm module removed | * | Internal Knowledge | qasm |  |
```

```python
    import os
from qiskit import QuantumCircuit   # type: ignore
from qiskit_aer import Aer              # type: ignore
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```
