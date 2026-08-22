| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------: | :------- | :---------- |
| 9 | `    pulse.u2(0, math.pi, 0)` | Deprecation -> pulse.u2() function is deprecated | IK | pulse.u2 | `    pulse.library.u2(0, math.pi, 0)` |
| 10 | `    pulse.cx(0, 1)` | Deprecation -> pulse.cx() function is deprecated | IK | pulse.cx | `    pulse.library.cx(0, 1)` |

```python
import math
from qiskit import pulse
from qiskit.providers.fake_provider import FakeOpenPulse3Q

backend = FakeOpenPulse3Q()
d2 = pulse.DriveChannel(2)
 
with pulse.build(backend) as bell_prep:
    pulse.library.u2(0, math.pi, 0)
    pulse.library.cx(0, 1)
 
with pulse.build(backend) as decoupled_bell_prep_and_measure:
    with pulse.align_right():
        pulse.call(bell_prep)
        pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)
        pulse.barrier(0, 1, 2)
        registers = pulse.measure_all()
 
decoupled_bell_prep_and_measure.draw()
```