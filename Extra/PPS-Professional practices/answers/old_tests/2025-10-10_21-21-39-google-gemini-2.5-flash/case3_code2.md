| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit.providers.fake_provider import FakeSherbrooke` | Deprecation -> The `qiskit.providers.fake_provider` namespace has been deprecated | internal | `qiskit.providers.fake_provider` | `from qiskit.visualization.timeline import iplot_timeline_with_instruction_dists` |
| 2 | `from qiskit.compiler import assemble, schedule` | Deprecation -> The `qiskit.compiler.assemble` function has been deprecated | internal | `qiskit.compiler.assemble` | |
| 3 | `from qiskit.qobj.utils import MeasLevel, MeasReturnType` | Deprecation -> `qiskit.qobj.utils` namespace has been deprecated | internal | `qiskit.qobj.utils` | `from qiskit.result import MeasLevel, MeasReturnType` |
| 4 | `from qiskit import execute` | Deprecation -> The `qiskit.execute` function has been deprecated | internal | `qiskit.execute` | |
| 6 | `qc.add_schedule(schedule_obj, [0, 1])` | Deprecation -> The `QuantumCircuit.add_schedule` method has been deprecated | internal | `QuantumCircuit.add_schedule` | `qc.add_calibration(schedule_obj, [0, 1])` |
| 7 | `qc.add_parameter_instruction(instruction, [0])` | Deprecation -> The `QuantumCircuit.add_parameter_instruction` method has been deprecated | internal | `QuantumCircuit.add_parameter_instruction` | `qc.add_parametrized_instruction(instruction, [0])` |
| 8 | `qc.call(sub_q_circ)` | Deprecation -> The `QuantumCircuit.call` method has been deprecated | internal | `QuantumCircuit.call` | `qc.append(sub_q_circ)` |
| 9 | `qc.measure(0, 0, register=True)` | Deprecation -> The `register` argument of the `Acquire` instruction has been deprecated | internal | `Acquire` | `qc.measure(0, 0)` |


```python
from qiskit.visualization.timeline import iplot_timeline_with_instruction_dists
from qiskit.result import MeasLevel, MeasReturnType
from qiskit.circuit import QuantumCircuit, QuantumRegister, ClassicalRegister

qc = QuantumCircuit(2, 2)
schedule_obj = QuantumCircuit(1)
instruction = QuantumCircuit(1)
sub_q_circ = QuantumCircuit(1)

qc.add_calibration(schedule_obj, [0, 1])
qc.add_parametrized_instruction(instruction, [0])
qc.append(sub_q_circ)
qc.measure(0, 0)
```