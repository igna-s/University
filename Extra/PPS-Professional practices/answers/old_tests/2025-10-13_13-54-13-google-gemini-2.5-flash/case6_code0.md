| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
|:--:|:---|:--------|:-----------:|:----------:|:--------:|:-----------:|
| 2 | `from qiskit.pulse import Gaussian` | Import -> Add missing MeasureChannel import | * | Internal Knowledge | qiskit.pulse | `from qiskit.pulse import Gaussian, MeasureChannel` |
| 3 | `from qiskit.providers import fake_provider` | Import -> Update provider import | * | Internal Knowledge | qiskit.providers.fake_provider | `from qiskit.providers.fake_provider import FakeOpenPulse3Q` |
| 5 | `backend = fake_provider.FakeOpenPulse3Q()` | Refactoring -> Remove fake_provider prefix after import change | * | Internal Knowledge | FakeOpenPulse3Q | `backend = FakeOpenPulse3Q()` |
| 12 | `pulse.measure(0)` | Deprecation -> pulse.measure(qubit) function is deprecated; requires MeasureChannel | * | Internal Knowledge | pulse.measure | `pulse.measure(0, MeasureChannel(0))` |

```python
from qiskit import pulse
from qiskit.pulse import Gaussian, MeasureChannel
from qiskit.providers.fake_provider import FakeOpenPulse3Q

backend = FakeOpenPulse3Q()

with pulse.build(backend) as schedule:
    d0 = pulse.DriveChannel(0)
    pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16)
    pulse.play(pulse_obj, d0)
    pulse.delay(100, d0)
    pulse.measure(0, MeasureChannel(0))

print(schedule)
```