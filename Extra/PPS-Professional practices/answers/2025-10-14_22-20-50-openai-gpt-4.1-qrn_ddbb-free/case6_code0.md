| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 2 | from qiskit.providers import fake_provider | Move/Rename -> fake_provider moved to qiskit.providers.fake_provider | qrn_ddbb-a13c87200164cf13bdb7aaa1fd47dfbf | fake_provider | from qiskit.providers.fake_provider import FakeOpenPulse3Q |
| 4 | backend = fake_provider.FakeOpenPulse3Q() | Move/Rename -> FakeOpenPulse3Q imported directly from qiskit.providers.fake_provider | qrn_ddbb-a13c87200164cf13bdb7aaa1fd47dfbf | FakeOpenPulse3Q | backend = FakeOpenPulse3Q() |

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