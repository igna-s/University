| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecated -> Import from qiskit.providers.aer is deprecated | IK | qiskit.providers.aer | `from qiskit import QuantumCircuit, Aer as qiskit_aer, execute` | 
| 6 | `simulator = Aer.get_backend('qasm_simulator')` | Deprecated -> Use qiskit_aer to import Aer | IK | Aer | `simulator = qiskit_aer.get_backend('qasm_simulator')` | 
| 9 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecated -> qasm_qc execution context has changed | IK | execute |  `job = execute(circuit, simulator, shots=1024)` |

```python  
from qiskit import QuantumCircuit, Aer as qiskit_aer, execute
from qiskit import qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm()

qasm_qc = qasm.Qasm(data=qasm_str)
program = qasm_qc.parse()
circuit = program.get_circuit()

simulator = qiskit_aer.get_backend('qasm_simulator')
job = execute(circuit, simulator, shots=1024)
result = job.result()
counts = result.get_counts(circuit)
print(counts)
```