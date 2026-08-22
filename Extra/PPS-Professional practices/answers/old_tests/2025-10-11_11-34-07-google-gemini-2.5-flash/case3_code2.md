| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Deprecation of qiskit.Aer object | f4629adb-1cfe-4469-9df9-d8d0172ab667 | f4629adb-1cfe-4469-9df9-d8d0172ab667 | qiskit.Aer | `from qiskit_aer import Aer` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> The execute() function is deprecated | * | internal | execute | `from qiskit.providers.basic_provider import BasicProvider` |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | qiskit.qasm | `import qiskit.qasm2 as qasm` |
| 11 | `qasm_str = qc.qasm()` | Deprecation -> The QuantumCircuit.qasm() method used to generate a OpenQASM 2 representation of the QuantumCircuit object has been deprecated | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | QuantumCircuit.qasm() | `qasm_str = qasm.dumps(qc)` |
| 13 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | qiskit.qasm | `qasm_qc = QuantumCircuit.from_qasm_str(qasm_str)` |
| 14 | `program = qasm_qc.parse()` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | qiskit.qasm | |
| 15 | `circuit = program.get_circuit()` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | qiskit.qasm | `circuit = qasm_qc` |
| 17 | `simulator = Aer.get_backend('qasm_simulator')` | Deprecation -> Deprecation of qiskit.Aer object | f4629adb-1cfe-4469-9df9-d8d0172ab667 | f4629adb-1cfe-4469-9df9-d8d0172ab667 | Aer.get_backend | `simulator = AerSimulator()` |
| 18 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> The execute() function is deprecated | * | internal | execute | `job = simulator.run(qasm_qc, shots=1024)` |
| 19 | `result = job.result()` | Deprecation -> The execute() function is deprecated | * | internal | job.result() | `result = job.result()` |
| 20 | `counts = result.get_counts(qasm_qc)` | Deprecation -> The execute() function is deprecated | * | internal | result.get_counts() | `counts = result.get_counts(qasm_qc)` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
import qiskit.qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qasm.dumps(qc)

qasm_qc = QuantumCircuit.from_qasm_str(qasm_str)
circuit = qasm_qc

simulator = AerSimulator()
job = simulator.run(qasm_qc, shots=1024)
result = job.result()
counts = result.get_counts(qasm_qc)
print(counts)
```