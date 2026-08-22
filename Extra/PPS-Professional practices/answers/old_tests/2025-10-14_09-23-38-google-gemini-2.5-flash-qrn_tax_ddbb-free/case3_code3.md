| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit import qasm2 as qasm # type: ignore` | Deprecation -> The `qiskit.qasm2` module is deprecated | Internal Knowledge | qiskit.qasm2 | `from qiskit.qasm import loads, dumps` |
| 9 | `qasm_str = qasm.dumps(qc)` | Deprecation -> `qiskit.qasm2.dumps` is deprecated. | Internal Knowledge | qasm.dumps | `qasm_str = dumps(qc)` |
| 10 | `parsed_circuit = qasm.loads(qasm_str)` | Deprecation -> `qiskit.qasm2.loads` is deprecated. | Internal Knowledge | qasm.loads | `parsed_circuit = loads(qasm_str)` |


```python
from qiskit import QuantumCircuit
from qiskit.qasm import loads, dumps
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

qasm_str = dumps(qc)
parsed_circuit = loads(qasm_str)

simulator = AerSimulator()
job = simulator.run(parsed_circuit, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```