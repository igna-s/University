| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit.providers.fake_provider import FakeOpenPulse3Q` | Deprecation -> The `qiskit.providers.fake_provider` module has been deprecated | Internal Knowledge | qiskit.providers.fake_provider | `from qiskit.utils.fake_provider import FakeOpenPulse3Q` |
| 11 | `pulse.u2(0, math.pi, 0)` | Deprecation -> `u2` instruction has been deprecated | Internal Knowledge | u2 | `pulse.rz(0, 0)`<br>`pulse.sx(0)`<br>`pulse.rz(0, math.pi)` |
| 12 | `pulse.cx(0, 1)` | Deprecation -> `cx` instruction has been deprecated | Internal Knowledge | cx | `pulse.cx(0, 1)` |
| 17 | `registers = pulse.measure_all()` | Deprecation -> The function `measure_all()` has been deprecated | Internal Knowledge | measure_all | `registers = pulse.measure_all(backend.control_channels)` |

```python
import math
from qiskit import pulse
from qiskit.utils.fake_provider import FakeOpenPulse3Q

backend = FakeOpenPulse3Q()
d2 = pulse.DriveChannel(2)
 
with pulse.build(backend) as bell_prep:
    pulse.rz(0, 0)
    pulse.sx(0)
    pulse.rz(0, math.pi)
    pulse.cx(0, 1)
 
with pulse.build(backend) as decoupled_bell_prep_and_measure:
    with pulse.align_right():
        pulse.call(bell_prep)
        pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)
        pulse.barrier(0, 1, 2)
        registers = pulse.measure_all(backend.control_channels)
 
decoupled_bell_prep_and_measure.draw()
```