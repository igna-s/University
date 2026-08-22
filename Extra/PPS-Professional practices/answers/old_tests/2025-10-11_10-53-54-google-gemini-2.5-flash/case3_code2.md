| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> The execute() function is deprecated | 203 | cc6d2843-80cd-4947-9bb4-a8bf5bc7b9f6 | execute | `from qiskit import QuantumCircuit, transpile` |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> The qiskit.qasm2 module is deprecated and replaced by qiskit.qasm | * | internal | qiskit.qasm2 | `import qiskit.qasm as qasm` |
| 12 | `simulator = Aer.get_backend('qasm_simulator')` | Deprecation -> Aer.get_backend() is deprecated. The qiskit.Aer namespace has been deprecated. | * | internal | Aer.get_backend | `from qiskit_aer import AerSimulator`<br>`simulator = AerSimulator()` |
| 13 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> The execute() function is deprecated. | 203 | cc6d2843-80cd-4947-9bb4-a8bf5bc7b9f6 | execute | `transpiled_qc = transpile(qasm_qc, simulator)`<br>`job = simulator.run(transpiled_qc, shots=1024)` |
| 15 | `counts = result.get_counts(qasm_qc)` | Deprecation -> The get_counts() method no longer accepts a QuantumCircuit object. | * | internal | result.get_counts | `counts = result.get_counts()` |


```python
from qiskit import QuantumCircuit, transpile
import qiskit.qasm as qasm
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm()

qasm_qc = qasm.Qasm(data=qasm_str)
program = qasm_qc.parse()
circuit = program.get_circuit()

simulator = AerSimulator()
transpiled_qc = transpile(qasm_qc, simulator)
job = simulator.run(transpiled_qc, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```