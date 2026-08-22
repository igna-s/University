from qiskit import execute
from qiskit.test.mock import FakeVigo
from qiskit.test.reference_circuits import ReferenceCircuits
from qiskit.test.base import BaseTestCase
import unittest

qc = ReferenceCircuits.bell()
backend = FakeVigo()
job = execute(qc, backend, shots=1024)
result = job.result()
counts = result.get_counts()

print("Resultados del circuito Bell:")
print(counts)

# Prueba unitaria usando BaseTestCase
class TestBellCircuit(BaseTestCase):
    
    def test_bell_state(self):
        qc = ReferenceCircuits.bell()
        backend = FakeVigo()
        job = execute(qc, backend, shots=1024)
        result = job.result()
        counts = result.get_counts()        
        self.assertTrue('00' in counts or '11' in counts)
        self.assertAlmostEqual(counts.get('00', 0) + counts.get('11', 0), 1024, delta=50)


if __name__ == '__main__':
    unittest.main()