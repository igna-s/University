| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit.providers import fake_provider` | Deprecation -> `qiskit.providers.fake_provider` has been moved to `qiskit.providers.fake_backends` | 1 | 374944b0-333e-4688-ae38-7243b3554b73 | fake_provider | `from qiskit.providers.fake_backends import FakeOpenPulse3Q` |
| 5 | `backend = fake_provider.FakeOpenPulse3Q()` | Deprecation -> `qiskit.providers.fake_provider` has been moved to `qiskit.providers.fake_backends` | 1 | 374944b0-333e-4688-ae38-7243b3554b73 | FakeOpenPulse3Q | `backend = FakeOpenPulse3Q()` |


```python
from qiskit import pulse
from qiskit.pulse import Gaussian
from qiskit.providers.fake_backends import FakeOpenPulse3Q

backend = FakeOpenPulse3Q()

with pulse.build(backend) as schedule:
    d0 = pulse.DriveChannel(0)
    pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16)
    pulse.play(pulse_obj, d0)
    pulse.delay(100, d0)
    pulse.measure(0)

print(schedule)
```