| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | from qiskit import qasm2 as qasm | New Path -> Use qiskit.qasm2 module for OpenQASM 2 parsing and serialization (instead of legacy qiskit.qasm) | qrn_ddbb-1ff0d2a4-05b0-4eb6-87ae-fe09d97a40e6 | qiskit.qasm2 |  |
| 3 | from qiskit_aer import AerSimulator | New Path -> qiskit_aer should be used instead of qiskit.providers.aer | qrn_ddbb-31f0ecfd-f398-43e4-8297-263f360dff81 | qiskit_aer.AerSimulator |  |

```python
from qiskit import QuantumCircuit
from qiskit import qasm2 as qasm
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

qasm_str = qasm.dumps(qc)
parsed_circuit = qasm.loads(qasm_str)

simulator = AerSimulator()
job = simulator.run(parsed_circuit, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```