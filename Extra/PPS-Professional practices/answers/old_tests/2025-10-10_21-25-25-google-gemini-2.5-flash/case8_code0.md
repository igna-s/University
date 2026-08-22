| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, transpile` | Deprecation -> The qiskit.transpile() standalone function has been deprecated. | d4726210-ddfa-450e-b2d9-e48f10640acb | qiskit.transpile | `from qiskit import QuantumCircuit` |
| 2 | `from qiskit.providers.aer import AerSimulator` | Deprecation -> The qiskit.providers.aer namespace has been deprecated. | 473a242f-b4b1-4177-a4bc-9a105c31252d | qiskit.providers.aer | `from qiskit.primitives import Sampler` |
| 5 | `qc = QuantumCircuit(2, 2)` | (optional) Refactor -> The QuantumCircuit constructor was updated to simplify the process of creating a circuit with classical registers. | 8dd1c964-b86a-4c28-971c-f23019819779 | QuantumCircuit | `qc = QuantumCircuit(2)` |
| 14 | `simulator = AerSimulator()` | Deprecation -> The AerSimulator backend from qiskit.providers.aer has been deprecated. | f74c4314-e53f-42a9-b3a3-11a5b2829158 | AerSimulator | `sampler = Sampler()` |
| 16 | `transpiled_qc = transpile(qc, simulator)` | Deprecation -> The qiskit.transpile() standalone function has been deprecated. | d4726210-ddfa-450e-b2d9-e48f10640acb | transpile | `qc.measure([0,1],[0,1])` |
| 18 | `job = simulator.run(transpiled_qc, shots=1024)` | Refactor -> The AerSimulator.run() method has been deprecated. | 851c3562-f94d-4952-8705-1a3b90940656 | run | `job = sampler.run(qc).result()` |
| 20 | `result = job.result()` | Refactor -> The AerSimulator.run() method has been deprecated. | 851c3562-f94d-4952-8705-1a3b90940656 | result | `counts = job.quasi_dists[0].binary_probabilities()` |
| 21 | `counts = result.get_counts(0)` | Refactor -> The AerSimulator.run() method has been deprecated. | 851c3562-f94d-4952-8705-1a3b90940656 | get_counts | |
| 23 | `print(f"Counts: {counts}")` | Refactor -> The AerSimulator.run() method has been deprecated. | 851c3562-f94d-4952-8705-1a3b90940656 | print | `print(f"Quasi-probabilities: {counts}")` |


```python
from qiskit import QuantumCircuit
from qiskit.primitives import Sampler

qc = QuantumCircuit(2)

qc.h(0)
qc.cx(0, 1)
qc.measure([0,1],[0,1])

sampler = Sampler()

job = sampler.run(qc).result()
counts = job.quasi_dists[0].binary_probabilities()

print(f"Quasi-probabilities: {counts}")
```