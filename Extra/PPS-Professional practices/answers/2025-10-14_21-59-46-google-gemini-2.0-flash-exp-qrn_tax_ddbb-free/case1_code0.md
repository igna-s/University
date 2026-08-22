| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> The qiskit.qasm module is deprecated. | qrn_tax_ddbb-ff63c9105e3dfa53f77892117832c5c7 | qiskit.qasm |  |
| 5 | `from qiskit.algorithms import VQE` | Deprecation -> Class ``VQE`` has been deprecated and replaced with the ``MinimumEigensolver`` interface. | qrn_tax_ddbb-5c32c903b01f4d9f9f41eee98b61c756 | qiskit.algorithms.VQE |  |
| 6 | `from qiskit import qasm2 as qasm` | Name change -> Module name qasm2 has been changed to parser. | qrn_tax_ddbb-12a846198c0b65e26a8bc7d81394e656 | qasm2 | `from qiskit import parser as qasm` |

```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit.algorithms import VQE
from qiskit import parser as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```