| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | from qiskit import execute | Deprecation -> The execute() function is deprecated and removed | qrn_notax_ddbb--7dcaf104-d552-4d87-994a-c7691846d9a9 | qiskit.execute | Remove and switch to 'transpile' + 'backend.run' |
| 2 | from qiskit.test.mock import FakeVigo | Deprecation -> qiskit.test.mock.FakeVigo is deprecated and removed. Use qiskit-ibm-runtime.fake_provider instead | qrn_notax_ddbb--aa6cda1f-af91-4940-8d4c-1897f9a56701 | qiskit.test.mock.FakeVigo | from qiskit_ibm_runtime.fake_provider import FakeVigo |
| 3 | from qiskit.test.reference_circuits import ReferenceCircuits | Deprecation -> qiskit.test.reference_circuits.ReferenceCircuits is deprecated and removed | qrn_notax_ddbb--12ee0486-d662-444e-bf93-2dc6e1e66ac2 | qiskit.test.reference_circuits.ReferenceCircuits | Implement bell circuit manually |
| 4 | from qiskit.test.base import BaseTestCase | Deprecation -> qiskit.test.base.BaseTestCase is deprecated and removed | qrn_notax_ddbb--12ee0486-d662-444e-bf93-2dc6e1e66ac2 | qiskit.test.base.BaseTestCase | Use unittest.TestCase |
| 7 | qc = ReferenceCircuits.bell() | Deprecation -> ReferenceCircuits.bell() is deprecated and removed | qrn_notax_ddbb--12ee0486-d662-444e-bf93-2dc6e1e66ac2 | ReferenceCircuits.bell | Implement bell circuit manually |
| 8 | backend = FakeVigo() | Deprecation -> FakeVigo is deprecated and removed. Use qiskit-ibm-runtime.fake_provider instead | qrn_notax_ddbb--aa6cda1f-af91-4940-8d4c-1897f9a56701 | FakeVigo | from qiskit_ibm_runtime.fake_provider import FakeVigo |
| 9 | job = execute(qc, backend, shots=1024) | Deprecation -> The execute() function is deprecated and removed | qrn_notax_ddbb--7dcaf104-d552-4d87-994a-c7691846d9a9 | execute | Use transpile/Backend.run |
| 17 | qc = ReferenceCircuits.bell() | Deprecation -> ReferenceCircuits.bell() is deprecated and removed | qrn_notax_ddbb--12ee0486-d662-444e-bf93-2dc6e1e66ac2 | ReferenceCircuits.bell | Implement bell circuit manually |
| 18 | backend = FakeVigo() | Deprecation -> FakeVigo is deprecated and removed. Use qiskit-ibm-runtime.fake_provider instead | qrn_notax_ddbb--aa6cda1f-af91-4940-8d4c-1897f9a56701 | FakeVigo | from qiskit_ibm_runtime.fake_provider import FakeVigo |
| 19 | job = execute(qc, backend, shots=1024) | Deprecation -> The execute() function is deprecated and removed | qrn_notax_ddbb--7dcaf104-d552-4d87-994a-c7691846d9a9 | execute | Use transpile/Backend.run |
| 24 | class TestBellCircuit(BaseTestCase): | Deprecation -> qiskit.test.base.BaseTestCase is deprecated and removed | qrn_notax_ddbb--12ee0486-d662-444e-bf93-2dc6e1e66ac2 | BaseTestCase | class TestBellCircuit(unittest.TestCase): |

```python
from qiskit_ibm_runtime.fake_provider import FakeVigo
import unittest
from qiskit import QuantumCircuit, transpile

def create_bell_circuit():
    qc = QuantumCircuit(2, 2)
    qc.h(0)
    qc.cx(0, 1)
    qc.measure([0, 1], [0, 1])
    return qc

qc = create_bell_circuit()
backend = FakeVigo()
qc_t = transpile(qc, backend)
job = backend.run(qc_t, shots=1024)
result = job.result()
counts = result.get_counts()

print("Resultados del circuito Bell:")
print(counts)

class TestBellCircuit(unittest.TestCase):

    def test_bell_state(self):
        qc = create_bell_circuit()
        backend = FakeVigo()
        qc_t = transpile(qc, backend)
        job = backend.run(qc_t, shots=1024)
        result = job.result()
        counts = result.get_counts()
        self.assertTrue('00' in counts or '11' in counts)
        self.assertAlmostEqual(counts.get('00', 0) + counts.get('11', 0), 1024, delta=50)

if __name__ == '__main__':
    unittest.main()
```