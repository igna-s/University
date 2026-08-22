| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 10 | `    pulse.play(pulse_obj, d0)` | Deprecation -> pulse.play function is deprecated | IK | pulse.play | `    pulse.instructions.play(pulse_obj, d0)` |
| 11 | `    pulse.delay(100, d0)` | Deprecation -> pulse.delay function is deprecated | IK | pulse.delay | `    pulse.instructions.delay(100, d0)` |
| 12 | `    pulse.measure(0)` | Deprecation -> pulse.measure function is deprecated | IK | pulse.measure | `    pulse.instructions.measure(0)` |

```python
    from qiskit import pulse
from qiskit.pulse import Gaussian
from qiskit.providers import fake_provider

backend = fake_provider.FakeOpenPulse3Q()

with pulse.build(backend) as schedule:
    d0 = pulse.DriveChannel(0)
    pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16)
    pulse.instructions.play(pulse_obj, d0)
    pulse.instructions.delay(100, d0)
    pulse.instructions.measure(0)

print(schedule)
```