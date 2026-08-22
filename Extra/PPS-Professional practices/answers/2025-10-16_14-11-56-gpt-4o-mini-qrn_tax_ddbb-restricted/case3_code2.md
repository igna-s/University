| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> The use of Aer from qiskit is deprecated | qrn_tax_ddbb-09db4543-63a6-47dd-9cd7-097a6f9fe1a8 | qiskit | `from qiskit import QuantumCircuit`\n`from qiskit_aer import Aer` |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> The qiskit.qasm module is deprecated | qrn_tax_ddbb-14d60789-87f8-4c87-b51f-145ed1d62b70 | qiskit.qasm | `from qiskit import qasm2 as qasm` |
| 8 | `qc.measure([0, 1], [0, 1])` | Deprecation -> The use of qiskit's measure method should replace | qrn_tax_ddbb-06d59d36-2c63-4461-91c4-edac933eac19 | qiskit | `qc.measure([0, 1], [0, 1])` |
| 10 | `qasm_str = qc.qasm()` | Deprecation -> QuantumCircuit.qasm() is deprecated | qrn_tax_ddbb-16d8d706-67ec-4d20-9aaa-f45f8940b773 | qiskit | `qasm_str = qasm.dumps(qc)` |
| 11 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Deprecation -> Qasm initialization has changed | qrn_tax_ddbb-60bcdc23-5881-458e-8762-93fa3a58e0d5 | qiskit.qasm | `qasm_qc = qasm.loads(qasm_str)` |
| 13 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> The execute function has been deprecated | qrn_tax_ddbb-48a35b67-b938-487b-aef2-7b4596ff4105 | qiskit | `from qiskit.primitives import BackendSampler`\n`sampler = BackendSampler(simulator)`\n`job = sampler.run(qasm_qc, shots=1024)` |

```python
from qiskit import QuantumCircuit
from qiskit_aer import Aer
from qiskit import qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qasm.dumps(qc)
qasm_qc = qasm.loads(qasm_str)

simulator = Aer.get_backend('qasm_simulator')
from qiskit.primitives import BackendSampler
sampler = BackendSampler(simulator)
job = sampler.run(qasm_qc, shots=1024)
result = job.result()
counts = result.get_counts(qasm_qc)
print(counts)
```