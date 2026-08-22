| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
code fully compatible with version 1.0.0

```python  
    from qiskit import pulse
from qiskit.pulse import Gaussian
from qiskit.providers import fake_provider

backend = fake_provider.FakeOpenPulse3Q()

with pulse.build(backend) as schedule:
    d0 = pulse.DriveChannel(0)
    pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16)
    pulse.play(pulse_obj, d0)
    pulse.delay(100, d0)
    pulse.measure(0)

print(schedule)
```