| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Importing from qiskit.providers.aer is deprecated and will stop working in Qiskit 1.0. You should instead import from qiskit_aer, which is a drop-in replacement. | 548acfe8-db26-45b7-ab5c-c637c63ee4b0 | Aer | `from qiskit_aer import AerSimulator` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Qiskit’s execute() function is deprecated. | 7dcaf104-d552-4d87-994a-c7691846d9a9 | execute | |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> The `qiskit.qasm2` module has been deprecated. | IK | qasm2 | `from qiskit.qasm import loads` |
| 13 | `simulator = Aer.get_backend('qasm_simulator')` | Deprecation -> Aer.get_backend is deprecated. | IK | Aer.get_backend | `simulator = AerSimulator()` |
| 14 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> The `execute()` function is deprecated. | 7dcaf104-d552-4d87-994a-c7691846d9a9 | execute | `job = simulator.run(circuit, shots=1024)` |
| 16 | `counts = result.get_counts(qasm_qc)` | Deprecation -> result.get_counts(qasm_qc) is deprecated. | IK | result.get_counts | `counts = result.get_counts(circuit)` |

```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
from qiskit.qasm import loads

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm()

qasm_qc = loads(qasm_str)
circuit = qasm_qc

simulator = AerSimulator()
job = simulator.run(circuit, shots=1024)
result = job.result()
counts = result.get_counts(circuit)
print(counts)
```