| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> execute() function deprecated | qrn_tax_ddbb-531dbe936b18445e9c8fa11aebecab5f | qiskit.execute |  |
| 2 | `from qiskit import qasm2 as qasm` | API Change -> qasm2 module location and usage changed | qrn_tax_ddbb-7d78454744214d459ab96485943e5a77 | qiskit.qasm2 | `from qiskit_qasm2 import Qasm` |
| 7 | `qasm_qc = qasm.Qasm(data=qasm_str)` | API Change -> Qasm class constructor updated | qrn_tax_ddbb-7d78454744214d459ab96485943e5a77 | qiskit.qasm2.Qasm | `qasm_qc = Qasm(data=qasm_str)` |
| 8 | `program = qasm_qc.parse()` | API Change -> parse() method replaced | qrn_tax_ddbb-7d78454744214d459ab96485943e5a77 | qiskit.qasm2.Qasm.parse | `circuit = qasm_qc.circuit` |
| 9 | `circuit = program.get_circuit()` | API Change -> get_circuit() method replaced by direct access | qrn_tax_ddbb-7d78454744214d459ab96485943e5a77 | qiskit.qasm2.get_circuit |  |
| 11 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> execute() function deprecated, use Sampler or appropriate transpile/run pattern | qrn_tax_ddbb-531dbe936b18445e9c8fa11aebecab5f | qiskit.execute | `from qiskit import transpile, assemble\ntranspiled_circuit = transpile(circuit, simulator)\nqobj = assemble(transpiled_circuit, backend=simulator, shots=1024)\njob = simulator.run(qobj)` |
| 13 | `counts = result.get_counts(qasm_qc)` | API Change -> get_counts() argument should be None or the actual circuit | qrn_tax_ddbb-7e91d6d2e334412eb6e1073e9f43eb3a | qiskit.result.get_counts | `counts = result.get_counts()` |

```python
from qiskit import QuantumCircuit, Aer, transpile, assemble
from qiskit_qasm2 import Qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm()

qasm_qc = Qasm(data=qasm_str)
circuit = qasm_qc.circuit

simulator = Aer.get_backend('qasm_simulator')
transpiled_circuit = transpile(circuit, simulator)
qobj = assemble(transpiled_circuit, backend=simulator, shots=1024)
job = simulator.run(qobj)
result = job.result()
counts = result.get_counts()
print(counts)
```