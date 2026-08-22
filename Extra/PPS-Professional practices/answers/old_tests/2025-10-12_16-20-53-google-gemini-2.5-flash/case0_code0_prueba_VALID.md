| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `importar os;` | Python Syntax -> Invalid keyword 'importar' | * | Internal Knowledge | importar | `import os` |
| 6 | `// import datetime funcionalities` | Python Syntax -> Invalid comment syntax '//' | * | Internal Knowledge | // | `# import datetime funcionalities` |
| 14 | `syout("work done !")` | Python Syntax -> Undefined function 'syout' | * | Internal Knowledge | syout | `print("work done !")` |


```python
'''
    Este es un codigo invalido python para pruebas
'''

import os

# import QuantumCircuit funcionalities
from qiskit import QuantumCircuit

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