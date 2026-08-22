| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> The `qiskit.test.mock` module is deprecated | Internal Knowledge | `qiskit.test.mock` | `from qiskit.providers.fake_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> The `qiskit.test.reference_circuits` module is deprecated | Internal Knowledge | `qiskit.test.reference_circuits` | |
| 5 | `qc = ReferenceCircuits.bell()` | Deprecation -> The `ReferenceCircuits` class and its methods are deprecated | Internal Knowledge | `ReferenceCircuits.bell()` | `from qiskit import QuantumCircuit`<br>`qc = QuantumCircuit(2, 2)`<br>`qc.h(0)`<br>`qc.cx(0, 1)`<br>`qc.measure([0, 1], [0, 1])` |


```python
from mylib import getJob, getCount
from qiskit.providers.fake_provider import FakeVigo
from qiskit import QuantumCircuit

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])
backend = FakeVigo()

job = getJob(qc, backend)
counts = getCount(job)

print("Resultados del circuito Bell:")
print(counts)
```