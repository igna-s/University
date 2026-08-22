| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit import qasm2 as qasm` | Meta-package Removed -> The `qiskit.qasm2` module has been removed. | qrn_tax_ddbb-77c9d252-896c-4f41-9364-622977885885 | qiskit.qasm2 | `from qiskit import qasm3` |
| 9 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Meta-package Removed -> Use the `Qasm3Parser` class in `qiskit.qasm3` instead. | qrn_tax_ddbb-0194a941-0c90-4426-b709-f89571806409 | qiskit.qasm2 | `from qiskit.qasm3 import Qasm3Parser`<br>`qasm_qc = Qasm3Parser().parse_str(qasm_str)` |
| 13 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> The `execute` function is deprecated and will be removed in a future release. | qrn_tax_ddbb-39c65228-ddc6-47c7-860e-576307ca8858 | qiskit.execute |  |
| 13 | `job = execute(qasm_qc, simulator, shots=1024)` | Replacement ->  Use `backend.run(circuits, **options)` instead. | qrn_tax_ddbb-885896ff-5efd-4422-936c-2539f7760c98 | qiskit.execute | `job = simulator.run(circuit, shots=1024)` |
| 15 | `counts = result.get_counts(qasm_qc)` | Deprecation -> `result.get_counts(circuit)` is deprecated  | qrn_tax_ddbb-5684dd22-d906-41d6-940c-501169c30344 | qiskit.result.Result#get_counts | `counts = result.get_counts(circuit)` |

```python
from qiskit import QuantumCircuit, Aer

from qiskit import qasm3
from qiskit.qasm3 import Qasm3Parser

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm()

qasm_qc = Qasm3Parser().parse_str(qasm_str)
program = qasm_qc.get_circuit()
circuit = program

simulator = Aer.get_backend('qasm_simulator')
job = simulator.run(circuit, shots=1024)
result = job.result()
counts = result.get_counts(circuit)
print(counts)
```