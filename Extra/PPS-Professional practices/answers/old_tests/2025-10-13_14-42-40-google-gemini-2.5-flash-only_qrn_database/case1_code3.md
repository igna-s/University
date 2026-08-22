| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> Use of the qiskit.Aer object is deprecated and will be removed in Qiskit 1.0. You should instead use the same object from the qiskit_aer namespace, which is a drop-in replacement. | * | ce25a304-5b28-43b2-8a0d-9b31e0b13fb7 | Aer | `from qiskit_aer import Aer` |
| 12 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Importing from qiskit.providers.aer is deprecated and will stop working in Qiskit 1.0. You should instead import from qiskit_aer, which is a drop-in replacement. | * | 3e95df91-e1c5-4340-8243-daa95d502170 | Aer.get_backend | `backend = AerSimulator()` |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> The qiskit.providers.basicaer module and all of its classes are deprecated from Qiskit 0.46 onwards. Their use should be replaced with the qiskit.quantum_info module and the new qiskit.providers.basic_provider module. | * | c7fe0ecc-6b73-4aed-a0c6-25de630eb29d | qasm | `from qiskit_aer import QasmSimulator` |


```python
import os
from datetime import datetime
from qiskit import QuantumCircuit, execute
from qiskit_aer import AerSimulator
import matplotlib.pyplot as plt
from utils import getJob

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = AerSimulator()
job = getJob(qc, backend, 1000)
result = job.result().get_counts(qc)
plt.show()
```