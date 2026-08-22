| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. It will be removed in the Qiskit 1.0.0 release. The legacy OpenQASM 2 parser has been superseded by the qiskit.qasm2 module which provides a faster more correct parser for OpenQASM 2. | a03d6cfd-4c92-4523-a77d-3542afe18906 | qiskit.qasm2 | `from qiskit.qasm import QASM2` |
| 9 | `qasm_str = qasm.dumps(qc)` | Deprecation -> The QuantumCircuit.qasm() method used to generate a OpenQASM 2 representation of the QuantumCircuit object has been deprecated and will be removed in the Qiskit 1.0.0 release. The qasm2.dump() or qasm2.dumps() functions which provide similar functionality should be used instead. | 4bbc9ad5-a04d-4ad1-97e1-83484b7a6eba | qasm.dumps | `qasm_str = QASM2.dumps(qc)` |
| 10 | `parsed_circuit = qasm.loads(qasm_str)` | Deprecation -> The QuantumCircuit.qasm() method used to generate a OpenQASM 2 representation of the QuantumCircuit object has been deprecated and will be removed in the Qiskit 1.0.0 release. The qasm2.dump() or qasm2.dumps() functions which provide similar functionality should be used instead. | 4bbc9ad5-a04d-4ad1-97e1-83484b7a6eba | qasm.loads | `parsed_circuit = QASM2.loads(qasm_str)` |


```python
from qiskit import QuantumCircuit
from qiskit.qasm import QASM2
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

qasm_str = QASM2.dumps(qc)
parsed_circuit = QASM2.loads(qasm_str)

simulator = AerSimulator()
job = simulator.run(parsed_circuit, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```