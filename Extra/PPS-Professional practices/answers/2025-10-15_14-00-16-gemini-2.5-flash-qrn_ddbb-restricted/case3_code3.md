| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. It will be removed in the Qiskit 1.0.0 release. The legacy OpenQASM 2 parser has been superseded by the qiskit.qasm2 module which provides a faster more correct parser for OpenQASM 2. | qrn_notax_ddbb-910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qiskit.qasm | |
| 9 | `qasm_str = qasm.dumps(qc)` | Deprecation -> The QuantumCircuit.qasm() method used to generate a OpenQASM 2 representation of the QuantumCircuit object has been deprecated and will be removed in the Qiskit 1.0.0 release. The qasm2.dump() or qasm2.dumps() functions which provide similar functionality should be used instead. | qrn_notax_ddbb-508fb6f3-cdfc-4b96-ad81-f550801dbe2f | qasm.dumps | |
| 10 | `parsed_circuit = qasm.loads(qasm_str)` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. It will be removed in the Qiskit 1.0.0 release. The legacy OpenQASM 2 parser has been superseded by the qiskit.qasm2 module which provides a faster more correct parser for OpenQASM 2. | qrn_notax_ddbb-910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qasm.loads | |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

qasm_str = qc.qasm() # If you want to dump to qasm, use qc.qasm() or qiskit.qasm3.dumps/loads
parsed_circuit = QuantumCircuit.from_qasm_str(qasm_str) # To load from qasm string, use QuantumCircuit.from_qasm_str

simulator = AerSimulator()
job = simulator.run(parsed_circuit, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```