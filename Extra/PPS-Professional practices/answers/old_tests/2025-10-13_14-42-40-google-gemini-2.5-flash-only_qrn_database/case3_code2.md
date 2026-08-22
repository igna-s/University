| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `Aer` module moved to `qiskit_aer` | 1 | 3e95df91-e1c5-4340-8243-daa95d502170 | Aer | `from qiskit_aer import Aer` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `execute` function deprecated | * | Internal Knowledge | execute | |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> `qiskit.qasm2` module is deprecated | * | Internal Knowledge | qasm2 | `from qiskit_qasm2 import QASM2Classical` |
| 16 | `simulator = Aer.get_backend('qasm_simulator')` | Deprecation -> `Aer.get_backend` is deprecated, use `QiskitAer.get_backend` | * | 3e95df91-e1c5-4340-8243-daa95d502170 | Aer.get_backend | `simulator = AerSimulator()` |
| 17 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> `execute` function deprecated. Replaced by `simulator.run().result()` | * | Internal Knowledge | execute | `job = simulator.run(qasm_qc, shots=1024)` |
| 19 | `counts = result.get_counts(qasm_qc)` | Deprecation -> `result.get_counts` parameter is no longer needed | * | Internal Knowledge | result.get_counts | `counts = result.get_counts()` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
from qiskit_qasm2 import QASM2Classical

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm()

qasm_qc = QASM2Classical(data=qasm_str)
program = qasm_qc.parse()
circuit = program.get_circuit()

simulator = AerSimulator()
job = simulator.run(qasm_qc, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```