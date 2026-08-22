| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------:| :------- | :---------- |
| 7 | with pulse.build(backend) as schedule: | Deprecation -> pulse.build context manager is deprecated | IK | pulse.build context manager | schedule = pulse.build(backend) |
| 10 | pulse.play(pulse_obj, d0) | Deprecation -> pulse.play usage inside context manager; must use schedule += | IK | pulse.play | schedule += pulse.play(pulse_obj, d0) |
| 11 | pulse.delay(100, d0) | Deprecation -> pulse.delay usage inside context manager; must use schedule += | IK | pulse.delay | schedule += pulse.delay(100, d0) |
| 12 | pulse.measure(0) | Deprecation -> pulse.measure requires measurement channel | IK | pulse.measure | schedule += pulse.measure(0, pulse.MeasureChannel(0)) |

```python
from qiskit import pulse
from qiskit.pulse import Gaussian
from qiskit.providers import fake_provider

backend = fake_provider.FakeOpenPulse3Q()

schedule = pulse.build(backend)

d0 = pulse.DriveChannel(0)
pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16)
schedule += pulse.play(pulse_obj, d0)
schedule += pulse.delay(100, d0)
schedule += pulse.measure(0, pulse.MeasureChannel(0))

print(schedule)
```
