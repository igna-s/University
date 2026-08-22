| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Use of the qiskit.Aer object is deprecated and will be removed in Qiskit 1.0. You should instead use the same object from the qiskit_aer namespace, which is a drop-in replacement. | 4194776d-c578-4b79-8dc6-9c5e286bc808 | Aer | `from qiskit_aer import Aer` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> The qiskit.execute() function is deprecated. This function served as a high-level wrapper around transpiling a circuit with some transpile options and running it on a backend with some run options. To do the same thing, you can explicitly use the transpile() function (with appropriate transpile options) followed by backend.run() (with appropriate run options). | 7dcaf104-d552-4d87-994a-c7691846d9a9 | execute | |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> The qiskit.qasm2 module is deprecated and will be removed in Qiskit 1.0. You should instead use the qiskit.qasm3 module, which is a drop-in replacement. | IK | qasm2 | `from qiskit import qasm3 as qasm` |
| 13 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> The qiskit.execute() function is deprecated. This function served as a high-level wrapper around transpiling a circuit with some transpile options and running it on a backend with some run options. To do the same thing, you can explicitly use the transpile() function (with appropriate transpile options) followed by backend.run() (with appropriate run options). | 7dcaf104-d552-4d87-994a-c7691846d9a9 | execute | `job = simulator.run(qasm_qc, shots=1024)` |
| 15 | `counts = result.get_counts(qasm_qc)` | Deprecation -> The `get_counts()` method now takes no arguments. | IK | get_counts | `counts = result.get_counts()` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import Aer
from qiskit import qasm3 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm()

qasm_qc = qasm.Qasm(data=qasm_str)
program = qasm_qc.parse()
circuit = program.get_circuit()

simulator = Aer.get_backend('qasm_simulator')
job = simulator.run(qasm_qc, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```