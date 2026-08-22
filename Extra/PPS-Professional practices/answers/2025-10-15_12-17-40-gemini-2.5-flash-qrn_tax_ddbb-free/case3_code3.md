| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> The `qiskit.qasm` module has been deprecated and superseded by `qiskit.qasm2` | d81c6f52-5772-420b-9094-0c9d7d5b64a2 | qiskit.qasm | `from qiskit.qasm import QASMString` |
| 9 | `qasm_str = qasm.dumps(qc)` | Deprecation -> The `QuantumCircuit.qasm()` method is deprecated and superseded by `qasm2.dumps()` | b5111ded-f178-4354-a8db-f475bdf64d57 | QuantumCircuit.qasm() | `qasm_str = qc.qasm()` |
| 10 | `parsed_circuit = qasm.loads(qasm_str)` | Deprecation -> The legacy OpenQASM 2 parser module `qiskit.qasm` has been deprecated and superseded by the `qiskit.qasm2` module | d81c6f52-5772-420b-9094-0c9d7d5b64a2 | qiskit.qasm | `parsed_circuit = QuantumCircuit.from_qasm_str(qasm_str)` |

```python
from qiskit import QuantumCircuit
from qiskit import qasm
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

qasm_str = qc.qasm()
parsed_circuit = QuantumCircuit.from_qasm_str(qasm_str)

simulator = AerSimulator()
job = simulator.run(parsed_circuit, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```