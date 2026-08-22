| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import execute` | Deprecation -> The execute() function is deprecated | qrn_notax_ddbb--7dcaf104-d552-4d87-994a-c7691846d9a9 | qiskit | `from qiskit import transpile` |
| 1 | `from qiskit import execute` | Deprecation -> The execute() function is deprecated | qrn_notax_ddbb--7dcaf104-d552-4d87-994a-c7691846d9a9 | qiskit | `sampler = BackendSampler(backend)` |
| 5 | `from qiskit.test.mock import FakeVigo` | Deprecation -> The FakeVigo backend is deprecated | qrn_notax_ddbb--aa6cda1f-af91-4940-8d4c-1897f9a56701 | qiskit.providers.fake_provider | `from qiskit_ibm_runtime.fake_provider import FakeProvider` |
| 6 | `backend = FakeVigo()` | Deprecation -> The FakeVigo backend is deprecated | qrn_notax_ddbb--aa6cda1f-af91-4940-8d4c-1897f9a56701 | qiskit.providers.fake_provider | `backend = FakeProvider().get_backend("fake_ourense")` |
| 8 | `qc = ReferenceCircuits.bell()` | Deprecation -> The ReferenceCircuits.bell() method is deprecated | qrn_notax_ddbb--86365b6b-cadf-4648-9399-b34d06c20ecd | qiskit.test.reference_circuits | `qc = QuantumCircuit.from_instruction(...your implementation...)` |
| 12 | `self.assertTrue('00' in counts or '11' in counts)` | (optional) | IK | unittest | `self.assertTrue(counts.get('00', 0) or counts.get('11', 0))` |

```python
from qiskit import transpile
from qiskit_ibm_runtime.fake_provider import FakeProvider
from qiskit.test.base import BaseTestCase
import unittest

qc = QuantumCircuit.from_instruction(...your implementation...)
backend = FakeProvider().get_backend("fake_ourense")
job = backend.run(transpile(qc, backend), shots=1024)
result = job.result()
counts = result.get_counts()

print("Resultados del circuito Bell:")
print(counts)

# Prueba unitaria usando BaseTestCase
class TestBellCircuit(BaseTestCase):
    
    def test_bell_state(self):
        qc = QuantumCircuit.from_instruction(...your implementation...)
        backend = FakeProvider().get_backend("fake_ourense")
        job = backend.run(transpile(qc, backend), shots=1024)
        result = job.result()
        counts = result.get_counts()        
        self.assertTrue(counts.get('00', 0) or counts.get('11', 0))
        self.assertAlmostEqual(counts.get('00', 0) + counts.get('11', 0), 1024, delta=50)


if __name__ == '__main__':
    unittest.main()
```