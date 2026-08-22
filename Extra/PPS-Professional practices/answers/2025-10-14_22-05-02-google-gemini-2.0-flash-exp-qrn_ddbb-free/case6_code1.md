| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 5 | `from qiskit.providers.fake_provider import FakeOpenPulse3Q` | Deprecation -> The fake providers are deprecated. | qrn_ddbb-a4d6b01b94e911ee91ca0242ac120002 | qiskit.providers.fake_provider | `from qiskit.providers.fake_provider.backends import FakeOpenPulse3Q` |
| 10 | `pulse.u2(0, math.pi, 0)` | Deprecation -> The QuantumCircuit.u2 method is deprecated. | qrn_ddbb-c117b78194e911ee91ca0242ac120002 | qiskit.QuantumCircuit.u2 | `pulse.u(math.pi/2, 0, math.pi, 0)` |
| 11 | `pulse.cx(0, 1)` | Deprecation -> The QuantumCircuit.cx method is deprecated. | qrn_ddbb-c9550b4c94e911ee91ca0242ac120002 | qiskit.QuantumCircuit.cx | `pulse.cx(0, 1)` |

```python
import math
from qiskit import pulse
from qiskit.providers.fake_provider.backends import FakeOpenPulse3Q

backend = FakeOpenPulse3Q()
d2 = pulse.DriveChannel(2)
 
with pulse.build(backend) as bell_prep:
    pulse.u(math.pi/2, 0, math.pi, 0)
    pulse.cx(0, 1)
 
with pulse.build(backend) as decoupled_bell_prep_and_measure:
    with pulse.align_right():
        pulse.call(bell_prep)
        pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)
        pulse.barrier(0, 1, 2)
        registers = pulse.measure_all()
 
decoupled_bell_prep_and_measure.draw()
```