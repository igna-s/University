| Line | Code | Scenario | Reference | Artifact | Refactoring |  
| :--: | :--- | :------- | :-------: | :------- | :---------- |  
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> qiskit.Aer object is deprecated | c02fdd64-b33a-477c-a00d-105424346f39 | qiskit.Aer | `from qiskit_aer import Aer` |  
| 2 | `from qiskit import qasm2 as qasm` | Optional -> rename import alias | IK | qiskit.qasm2 | `import qiskit.qasm2 as qasm2` |  
| 9 | `qasm_str = qc.qasm()` | Deprecation -> QuantumCircuit.qasm() method deprecated | 002bb3d5-8c9b-4e4e-997d-9404592460f6 | QuantumCircuit.qasm | `qasm_str = qasm2.dumps(qc)` |  
| 11 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Deprecation -> qiskit.qasm2.Qasm class deprecated | 002bb3d5-8c9b-4e4e-997d-9404592460f6 | qiskit.qasm2.Qasm | `circuit = QuantumCircuit.from_qasm_str(qasm_str)` |  
| 16 | `job = execute(qasm_qc, simulator, shots=1024)` | Optional -> variable rename | IK | execute | `job = execute(circuit, simulator, shots=1024)` |  
| 18 | `counts = result.get_counts(qasm_qc)` | Optional -> variable rename | IK | result.get_counts | `counts = result.get_counts(circuit)` |  

```python
from qiskit import QuantumCircuit, execute
from qiskit_aer import Aer
import qiskit.qasm2 as qasm2

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qasm2.dumps(qc)
circuit = QuantumCircuit.from_qasm_str(qasm_str)

simulator = Aer.get_backend('qasm_simulator')
job = execute(circuit, simulator, shots=1024)
result = job.result()
counts = result.get_counts(circuit)
print(counts)
```