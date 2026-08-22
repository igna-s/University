| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 9 | `    pulse.u2(0, math.pi, 0)` | Deprecation → Injection of circuit gate operations into pulse builder context | qrn_tax_ddbb-4f791e8e-887c-47d9-80fa-50227b769092 | pulse.u2 | Replace with a `QuantumCircuit`, transpile, schedule, and use `pulse.call(bell_prep_schedule)` |
| 10 | `    pulse.cx(0, 1)` | Deprecation → Injection of circuit gate operations into pulse builder context | qrn_tax_ddbb-4f791e8e-887c-47d9-80fa-50227b769092 | pulse.cx | Replace with a `QuantumCircuit`, transpile, schedule, and use `pulse.call(bell_prep_schedule)` |

```python
import math
from qiskit import pulse
from qiskit.providers.fake_provider import FakeOpenPulse3Q
from qiskit.circuit import QuantumCircuit
from qiskit.compiler import transpile, schedule

backend = FakeOpenPulse3Q()
d2 = pulse.DriveChannel(2)

# Build a pulse schedule from a quantum circuit
qc = QuantumCircuit(2)
qc.u2(0, math.pi, 0)
qc.cx(0, 1)
qc_t = transpile(qc, backend)
bell_prep_schedule = schedule(qc_t, backend)

with pulse.build(backend) as decoupled_bell_prep_and_measure:
    with pulse.align_right():
        pulse.call(bell_prep_schedule)
        pulse.play(pulse.Constant(bell_prep_schedule.duration, 0.02), d2)
        pulse.barrier(0, 1, 2)
        registers = pulse.measure_all()

decoupled_bell_prep_and_measure.draw()
```