| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------:| :------- | :---------- |
| 3 | `from qiskit.providers import fake_provider` | Deprecation -> Importing fake_provider from qiskit.providers is deprecated | IK | fake_provider | `from qiskit.providers.fake_provider import FakeOpenPulse3Q` |
| 5 | `backend = fake_provider.FakeOpenPulse3Q()` | Deprecation -> Using fake_provider.FakeOpenPulse3Q is deprecated | IK | FakeOpenPulse3Q | `backend = FakeOpenPulse3Q()` |

```python
from qiskit import pulse
from qiskit.pulse import Gaussian
from qiskit.providers.fake_provider import FakeOpenPulse3Q

backend = FakeOpenPulse3Q()

with pulse.build(backend) as schedule:
    d0 = pulse.DriveChannel(0)
    pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16)
    pulse.play(pulse_obj, d0)
    pulse.delay(100, d0)
    pulse.measure(0)

print(schedule)
```