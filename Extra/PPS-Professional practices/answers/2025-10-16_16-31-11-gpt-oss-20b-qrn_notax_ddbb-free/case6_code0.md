| Line | Code | Scenario | Reference | Artifact | Refactoring |
|:--:|:---|:--------|:----------|:--------|:-----------|
| 1 | `    from qiskit import pulse` | Deprecation -> from qiskit import pulse is deprecated | IK | pulse | `import qiskit.pulse as pulse` |
| 12 | `    pulse.measure(0)` | Deprecation -> pulse.measure(0) is deprecated | IK | pulse.measure | `pulse.measure(pulse.MeasureChannel(0))` |

```python
import qiskit.pulse as pulse
from qiskit.pulse import Gaussian
from qiskit.providers import fake_provider

backend = fake_provider.FakeOpenPulse3Q()

with pulse.build(backend) as schedule:
    d0 = pulse.DriveChannel(0)
    pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16)
    pulse.play(pulse_obj, d0)
    pulse.delay(100, d0)
    pulse.measure(pulse.MeasureChannel(0))

print(schedule)
```