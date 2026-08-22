| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import execute` | Deprecation -> `execute` function is deprecated. | IK | execute | `from qiskit.transpiler import PassManager` <br> `from qiskit.visualization import plot_histogram` <br> `from qiskit.primitives import Sampler` |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> `qiskit.test` module is deprecated. | 12ee0486-d662-444e-bf93-2dc6e1e66ac2 | qiskit.test.mock | `from qiskit_ibm_runtime.fake_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> `qiskit.test` module is deprecated. | 12ee0486-d662-444e-bf93-2dc6e1e66ac2 | qiskit.test.reference_circuits | `from qiskit.circuit.library import (  QuantumVolume,  EfficientSU2,  NLocal,  RealAmplitudes,  TwoLocal,  ZZFeatureMap,  ZFeatureMap,  PauliFeatureMap,)` |
| 4 | `from qiskit.test.base import BaseTestCase` | Deprecation -> `qiskit.test` module is deprecated. | 12ee0486-d662-444e-bf93-2dc6e1e66ac2 | qiskit.test.base | |
| 7 | `qc = ReferenceCircuits.bell()` | Deprecation -> `ReferenceCircuits.bell()` is deprecated. | IK | ReferenceCircuits.bell | `from qiskit.circuit.library import BellState` <br> `qc = BellState().decompose()` |
| 8 | `backend = FakeVigo()` | Deprecation -> `FakeVigo` is deprecated. | aa6cda1f-af91-4940-8d4c-1897f9a56701 | FakeVigo | `backend = FakeVigo()` |
| 9 | `job = execute(qc, backend, shots=1024)` | Deprecation -> `execute` function is deprecated. | IK | execute | `sampler = Sampler()` <br> `job = sampler.run(qc, shots=1024)` |
| 10 | `result = job.result()` | Updated -> `result` method return type changed. | IK | result | `result = job.result()` |
| 11 | `counts = result.get_counts()` | Deprecation -> `get_counts` method is deprecated. | IK | get_counts | `counts = result.quasi_dists[0].binary_probabilities()` |
| 16 | `def test_bell_state(self):` | Deprecation -> `BaseTestCase` should not be used for unit tests. | IK | BaseTestCase | `def test_bell_state(self):` |
| 17 | `qc = ReferenceCircuits.bell()` | Deprecation -> `ReferenceCircuits.bell()` is deprecated. | IK | ReferenceCircuits.bell | `qc = BellState().decompose()` |
| 18 | `backend = FakeVigo()` | Deprecation -> `FakeVigo` is deprecated. | aa6cda1f-af91-4940-8d4c-1897f9a56701 | FakeVigo | `backend = FakeVigo()` |
| 19 | `job = execute(qc, backend, shots=1024)` | Deprecation -> `execute` function is deprecated. | IK | execute | `job = sampler.run(qc, shots=1024)` |
| 20 | `result = job.result()` | Updated -> `result` method return type changed. | IK | result | `result = job.result()` |
| 21 | `counts = result.get_counts()` | Deprecation -> `get_counts` method is deprecated. | IK | get_counts | `counts = result.quasi_dists[0].binary_probabilities()` |


```python
from qiskit.transpiler import PassManager
from qiskit.visualization import plot_histogram
from qiskit.primitives import Sampler
from qiskit_ibm_runtime.fake_provider import FakeVigo
from qiskit.circuit.library import BellState
import unittest

qc = BellState().decompose()
backend = FakeVigo()
sampler = Sampler()
job = sampler.run(qc, shots=1024)
result = job.result()
counts = result.quasi_dists[0].binary_probabilities()

print("Resultados del circuito Bell:")
print(counts)

class TestBellCircuit(unittest.TestCase):
    
    def test_bell_state(self):
        qc = BellState().decompose()
        backend = FakeVigo()
        sampler = Sampler()
        job = sampler.run(qc, shots=1024)
        result = job.result()
        counts = result.quasi_dists[0].binary_probabilities()
        self.assertTrue('00' in counts or '11' in counts)
        self.assertAlmostEqual(counts.get('00', 0) + counts.get('11', 0), 1024, delta=50)


if __name__ == '__main__':
    unittest.main()
```