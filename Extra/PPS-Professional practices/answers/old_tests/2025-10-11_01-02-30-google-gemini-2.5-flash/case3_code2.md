| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `Aer` | Deprecation -> Importing from qiskit.providers.aer is deprecated and will stop working in Qiskit 1.0. | d632081c-97e1-4fa4-b5aa-e11204bcd570 | Aer | `from qiskit_aer import Aer` |
| 1 | `execute` | Deprecation -> Qiskit’s execute() function is deprecated. | 0b78d58d-ae5a-415b-aabc-02e0532a0c9e | execute | Use `transpile()` and `backend.run()` |
| 9 | `qc.qasm()` | Deprecation -> The QuantumCircuit.qasm() method used to generate a OpenQASM 2 representation is deprecated. | 4bbc9ad5-a04d-4ad1-97e1-83484b7a6eba | QuantumCircuit.qasm() | `qasm2.dumps(qc)` |
| 11 | `qasm.Qasm(data=qasm_str)` | Deprecation -> The legacy OpenQASM 2 parser (in `qiskit.qasm` module) and its instantiation `qasm.Qasm` has been deprecated. | d3e0c6f3-753f-4ff7-a61d-73446a5621de | qiskit.qasm | `QuantumCircuit.from_qasm_str(qasm_str)` |
| 12 | `program = qasm_qc.parse()` | Deprecation -> This parsing method is deprecated as part of the legacy OpenQASM 2 parser. | d3e0c6f3-753f-4ff7-a61d-73446a5621de | Qasm.parse() | (Not needed with `QuantumCircuit.from_qasm_str`) |
| 13 | `circuit = program.get_circuit()` | Deprecation -> This method is deprecated as part of the legacy OpenQASM 2 parser. | d3e0c6f3-753f-4ff7-a61d-73446a5621de | Program.get_circuit() | (Not needed with `QuantumCircuit.from_qasm_str`) |
| 15 | `Aer.get_backend` | Deprecation -> Use `qiskit_aer.Aer.get_backend()` instead of `qiskit.Aer.get_backend()`. | d632081c-97e1-4fa4-b5aa-e11204bcd570 | Aer.get_backend | `Aer.get_backend('qasm_simulator')` (after importing `Aer` from `qiskit_aer`) |
| 16 | `execute(qasm_qc, simulator, shots=1024)` | Deprecation -> Qiskit’s `execute()` function is deprecated. | 0b78d58d-ae5a-415b-aabc-02e0532a0c9e | execute | `transpiled_circuit = transpile(circuit, simulator)` then `job = simulator.run(transpiled_circuit, shots=1024)` |
| 18 | `result.get_counts(qasm_qc)` | Deprecation -> The `result.get_counts()` method no longer takes the circuit as an argument in Qiskit 1.0+. | internal | Result.get_counts() | `result.get_counts()` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import Aer
from qiskit import qasm2
from qiskit import transpile

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qasm2.dumps(qc)

circuit = QuantumCircuit.from_qasm_str(qasm_str)

simulator = Aer.get_backend('qasm_simulator')
transpiled_circuit = transpile(circuit, simulator)
job = simulator.run(transpiled_circuit, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```