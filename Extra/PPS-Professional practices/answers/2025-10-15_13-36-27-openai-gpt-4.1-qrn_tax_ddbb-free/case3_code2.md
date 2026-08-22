| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> execute() function deprecated | qrn_tax_ddbb--86a3c4cd-f02b-4a6f-ab7e-5babd1572e01 | execute | Remove use of execute and use the run() method of Qiskit backend objects |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> qiskit.qasm2 is deprecated in favor of qiskit_qasm2 | qrn_tax_ddbb--c6fc3228-4887-4c9e-95dd-a8c53b7d32c2 | qiskit.qasm2 | `from qiskit_qasm2 import loads as load_qasm2` |
| 7 | `qasm_str = qc.qasm()` | Deprecation -> QuantumCircuit.qasm() is deprecated | qrn_tax_ddbb--0a7b2b7c-d14a-46e6-8612-75a60670fc04 | QuantumCircuit.qasm | Use `QuantumCircuit.qasm(formatted=True)` for QASM 2 output or use `qiskit_qasm2.dumps` |
| 9 | `qasm_qc = qasm.Qasm(data=qasm_str)` | API Removal -> qiskit.qasm2.Qasm is removed, use qiskit_qasm2.loads or qiskit_qasm2.load | qrn_tax_ddbb--c6fc3228-4887-4c9e-95dd-a8c53b7d32c2 | qiskit.qasm2.Qasm | `qasm_qc = load_qasm2(qasm_str)` |
| 10 | `program = qasm_qc.parse()` | API Change -> qiskit.qasm2.Qasm.parse() removed, qiskit_qasm2.loads returns QuantumCircuit | qrn_tax_ddbb--c6fc3228-4887-4c9e-95dd-a8c53b7d32c2 | qiskit.qasm2.Qasm.parse | Use `qasm_qc` directly as QuantumCircuit |
| 11 | `circuit = program.get_circuit()` | Removal -> QASM parsed program format removed, no get_circuit method | qrn_tax_ddbb--c6fc3228-4887-4c9e-95dd-a8c53b7d32c2 | QasmProgram.get_circuit | Use `circuit = qasm_qc` |
| 13 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> execute() deprecated, run() should be used | qrn_tax_ddbb--86a3c4cd-f02b-4a6f-ab7e-5babd1572e01 | execute | `job = simulator.run(qasm_qc, shots=1024)` |
| 15 | `counts = result.get_counts(qasm_qc)` | API Update -> get_counts expects QuantumCircuit/run input | qrn_tax_ddbb--36e5d5b4-3247-4aec-848f-c1a13f0b1f63 | result.get_counts | `counts = result.get_counts(qasm_qc)` (no change necessary when using QuantumCircuit) |

```python
from qiskit import QuantumCircuit, Aer
from qiskit_qasm2 import loads as load_qasm2

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm(formatted=True)
qasm_qc = load_qasm2(qasm_str)
circuit = qasm_qc

simulator = Aer.get_backend('qasm_simulator')
job = simulator.run(circuit, shots=1024)
result = job.result()
counts = result.get_counts(circuit)
print(counts)
```