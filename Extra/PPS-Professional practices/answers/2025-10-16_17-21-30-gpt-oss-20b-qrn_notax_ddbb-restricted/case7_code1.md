| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------- | :------- | :---------- |
| 1 | `from qiskit import execute` | Deprecation -> execute() function is deprecated | 7dcaf104-d552-4d87-994a-c7691846d9a9 | qiskit.execute | Replace with `transpile` + `backend.run` |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> FakeVigo moved to qiskit-ibm-runtime | aa6cda1f-af91-4940-8d4c-1897f9a56701 | qiskit.test.mock.FakeVigo | `from qiskit_ibm_runtime.fake_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> qiskit.test module deprecated | 12ee0486-d662-444e-bf93-2dc6e1e66ac2 | qiskit.test.reference_circuits | Replace with custom bell circuit (`create_bell()`) |
| 4 | `from qiskit.test.base import BaseTestCase` | Deprecation -> qiskit.test module deprecated | 12ee0486-d662-444e-bf93-2dc6e1e66ac2 | qiskit.test.base.BaseTestCase | Use `unittest.TestCase` |
| 7 | `qc = ReferenceCircuits.bell()` | Deprecation -> qiskit.test.reference_circuits | 12ee0486-d662-444e-bf93-2dc6e1e66ac2 | qiskit.test.reference_circuits | Replace with `create_bell()` |
| 9 | `job = execute(qc, backend, shots=1024)` | Deprecation -> execute() function is deprecated | 7dcaf104-d552-4d87-994a-c7691846d9a9 | qiskit.execute | Use `transpile` + `backend.run` |
| 20 | `qc = ReferenceCircuits.bell()` | Deprecation -> qiskit.test.reference_circuits | 12ee0486-d662-444e-bf93-2dc6e1e66ac2 | qiskit.test.reference_circuits | Replace with `create_bell()` |
| 22 | `job = execute(qc, backend, shots=1024)` | Deprecation -> execute() function is deprecated | 7dcaf104-d552-4d87-994a-c7691846d9a9 | qiskit.execute | Use `transpile` + `backend.run` |

```python
from qiskit import transpile
from qiskit_ibm_runtime.fake_provider import FakeVigo
import unittest
from qiskit.circuit import QuantumCircuit

def create_bell():
    qc = QuantumCircuit(2)
    qc.h(0)
    qc.cx(0, 1)
    return qc

qc = create_bell()
backend = FakeVigo()
circ = transpile(qc, backend)
job = backend.run(circ, shots=1024)
result = job.result()
counts = result.get_counts()

print("Resultados del circuito Bell:")
print(counts)

class TestBellCircuit(unittest.TestCase):
    def test_bell_state(self):
        qc = create_bell()
        backend = FakeVigo()
        circ = transpile(qc, backend)
        job = backend.run(circ, shots=1024)
        result = job.result()
        counts = result.get_counts()
        self.assertTrue('00' in counts or '11' in counts)
        self.assertAlmostEqual(
            counts.get('00', 0) + counts.get('11', 0), 1024, delta=50
        )

if __name__ == "__main__":
    unittest.main()
```