| Line | Code | Scenario | Reference | Artifact | Refactoring |  
| :--: | :--- | :------- | :-------: | :------- | :---------- |  
| 3 | `from qiskit.providers.fake_provider import FakeOpenPulse3Q` | Deprecation -> Running pulse jobs on backends from qiskit.providers.fake_provider is deprecated | 69c3e5d9-9799-494e-9ed1-aa8df3e85fea | fake_provider | `from qiskit_aer import AerSimulator` |  
| 5 | `backend = FakeOpenPulse3Q()` | Deprecation -> Fake provider backends are deprecated for pulse jobs | 69c3e5d9-9799-494e-9ed1-aa8df3e85fea | backend | `backend = AerSimulator(pulse=True)` |  
| 15 | `pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)` | Deprecation -> Constant pulse is deprecated; use symbolic pulse and get_waveform | e42eed6a-8a13-4284-917c-626dbb2fc282 | pulse.Constant | `pulse.play(pulse.Constant(bell_prep.duration, 0.02).get_waveform(), d2)` |

```python
import math
from qiskit import pulse
from qiskit_aer import AerSimulator

backend = AerSimulator(pulse=True)
d2 = pulse.DriveChannel(2)

with pulse.build(backend) as bell_prep:
    pulse.u2(0, math.pi, 0)
    pulse.cx(0, 1)

with pulse.build(backend) as decoupled_bell_prep_and_measure:
    with pulse.align_right():
        pulse.call(bell_prep)
        pulse.play(pulse.Constant(bell_prep.duration, 0.02).get_waveform(), d2)
        pulse.barrier(0, 1, 2)
        registers = pulse.measure_all()

decoupled_bell_prep_and_measure.draw()
```
