| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> The `qiskit.qasm` module is deprecated. It will be removed in the Qiskit 1.0.0 release. | d81c6f52-5772-420b-9094-0c9d7d5b64a2 | qiskit.qasm | `from qiskit.qasm2 import loads` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> The `qiskit.qasm` module is deprecated. It will be removed in the Qiskit 1.0.0 release. | d81c6f52-5772-420b-9094-0c9d7d5b64a2 | Qasm | `with open(qasm_file, "r") as f: qasm_content = f.read()` |
| 5 | `program2 = circuit2.parse()` | Deprecation -> The `qiskit.qasm` module is deprecated. It will be removed in the Qiskit 1.0.0 release. | d81c6f52-5772-420b-9094-0c9d7d5b64a2 | parse() | `program2 = loads(qasm_content)` |
| 6 | `qc2 = program2.get_circuit()` | Deprecation -> The `qiskit.qasm` module is deprecated. It will be removed in the Qiskit 1.0.0 release. | d81c6f52-5772-420b-9094-0c9d7d5b64a2 | get_circuit() | `qc2 = program2` |
| 8 | `simulator = getBackend()` | Deprecation -> The `qiskit.providers.basicaer` module and all of its classes are deprecated from Qiskit 0.46 onwards. | 5675e75e-e976-4a4d-a2c7-23dc577eab7d | BasicAerProvider | `simulator = BasicProvider().get_backend("basic_simulator")` |


```python
from qiskit.qasm2 import loads
from qiskit.providers.basic_provider import BasicProvider
from utils import getJob

qasm_file="C:/qasm_file.qasm"
with open(qasm_file, "r") as f:
    qasm_content = f.read()
program2 = loads(qasm_content)
qc2 = program2

simulator = BasicProvider().get_backend("basic_simulator")
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```