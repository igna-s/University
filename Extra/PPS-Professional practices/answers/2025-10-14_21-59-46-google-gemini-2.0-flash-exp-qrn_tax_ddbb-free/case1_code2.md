| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> The qasm module is deprecated. | qrn_tax_ddbb-7ca8d4 | qasm | `from qiskit import QuantumCircuit, execute` |
| 4 | `import matplotlib.pyplot as plt` |  Changed  ->  The use of `matplotlib.pyplot` is discouraged. | qrn_tax_ddbb-e907 | matplotlib.pyplot |  Use `qiskit.visualization.plot_histogram` instead |

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit, execute
import matplotlib.pyplot as plt
from utils import getMyBackend

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

job = execute(qc, getMyBackend(), shots=1000)
result = job.result().get_counts(qc)
plt.show()
```