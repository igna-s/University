| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 5 | `from qiskit.providers.fake_provider import FakeOpenPulse3Q` | Deprecation -> The fake providers are deprecated. | qrn_tax_ddbb-d0b958a14ca74959a3d3e265d43ef948 | qiskit.providers.fake_provider | `from qiskit.providers.fake_provider.backends import FakeOpenPulse3Q` |
| 9 | `pulse.u2(0, math.pi, 0)` | Deprecation -> The control-flow commands `QuantumCircuit.for_loop()` and `pulse.call()` cannot be nested in Qiskit 1.0. | qrn_tax_ddbb-a890316884d94c5b9afb6a75464598ff | pulse.call | `pulse.u(0, math.pi, math.pi/2, 0)` |
| 10 | `pulse.cx(0, 1)` | Removed -> The `cx` method is removed in Pulse builder. | qrn_tax_ddbb-645f08d77f4b4976a5b4c5d8e3a788ba | pulse.cx |  |

```python
import math
from qiskit import pulse
from qiskit.providers.fake_provider.backends import FakeOpenPulse3Q

backend = FakeOpenPulse3Q()
d2 = pulse.DriveChannel(2)
 
with pulse.build(backend) as bell_prep:
    pulse.u(0, math.pi, math.pi/2, 0)
    
 
with pulse.build(backend) as decoupled_bell_prep_and_measure:
    with pulse.align_right():
        pulse.call(bell_prep)
        pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)
        pulse.barrier(0, 1, 2)
        registers = pulse.measure_all()
 
decoupled_bell_prep_and_measure.draw()
```