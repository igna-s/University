| Line | Code                                                       | Scenario                                              | Reference                                          | Artifact                       | Refactoring                         |
| :--: | :------------------------------------------------------- | :-------------------------------------------------- | :------------------------------------------------ | :----------------------------- | :---------------------------------- |
| 7    | `from qiskit import Aer`                                | Deprecation -> The `Aer` object is deprecated       | qrn_tax_ddbb--4e1a7f69-eeb4-4a93-9f27-322819438bf4 | qiskit import                 | `from qiskit_aer import Aer`      |
| 8    | `backend = Aer.get_backend('aer_simulator')`           | Updated -> use of `Aer.get_backend`                 | qrn_tax_ddbb--4e1a7f69-eeb4-4a93-9f27-322819438bf4 | backend                        | `backend = Aer.get_backend('aer_simulator')` |
| 12   | `from utils import getJob`                               | (optional)                                           | IK                                                | utils                         |                                     |
| 18   | `import matplotlib.pyplot as plt`                        | (optional)                                           | IK                                                | matplotlib                     |                                     |
| 19   | `qc.draw(output='mpl')`                                  | Updated -> output type 'mpl' will not be handled by `draw` | IK                                                | qc.draw                       | `qc.draw()`                         |
| 20   | `plt.show()`                                            | (optional)                                           | IK                                                | plt                            |                                     | 

```python
import os

from qiskit_aer import Aer
from qiskit import QuantumCircuit 
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = Aer.get_backend('aer_simulator')

from utils import getJob
from datetime import datetime
job = getJob(qc, backend, 1000).result().get_counts(qc)

import matplotlib.pyplot as plt
qc.draw()
plt.show()
```