| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit.providers import fake_provider` | Deprecation -> The qiskit.providers.fake_provider module is deprecated | 6 | 02c83a5a-c28d-46c6-acc2-4db931c4c15a | qiskit.providers.fake_provider | `from qiskit.providers.fake_provider import FakeOpenPulse3Q` |
| 5 | `backend = fake_provider.FakeOpenPulse3Q()` | Deprecation -> The qiskit.providers.fake_provider.FakeOpenPulse3Q class is deprecated | 6 | 02c83a5a-c28d-46c6-acc2-4db931c4c15a | fake_provider.FakeOpenPulse3Q | `backend = FakeOpenPulse3Q()` |


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