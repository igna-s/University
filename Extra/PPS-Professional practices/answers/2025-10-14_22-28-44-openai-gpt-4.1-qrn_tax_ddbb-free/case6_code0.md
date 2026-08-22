| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | from qiskit.providers import fake_provider | Rename -> fake_provider module moved to qiskit.providers.fake_provider | qrn_tax_ddbb-db9fa0e57b3c47a5bbd43fae7b2ee226 | qiskit.providers.fake_provider | from qiskit.providers.fake_provider import FakeOpenPulse3Q |
| 4 | backend = fake_provider.FakeOpenPulse3Q() | Rename -> FakeOpenPulse3Q now imported directly | qrn_tax_ddbb-db9fa0e57b3c47a5bbd43fae7b2ee226 | FakeOpenPulse3Q | backend = FakeOpenPulse3Q() |

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