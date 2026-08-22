| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | from qiskit.providers import fake_provider | Renamed module -> The `qiskit.providers.fake_provider` module has been moved to `qiskit.providers.fake_provider` (with lowercase naming convention). | qrn_tax_ddbb--3d224670-dec6-4f81-8f8b-65d9d6f5b6ea | qiskit.providers.fake_provider | from qiskit.providers import fake_provider |
| 7 | pulse.measure(0) | Removal -> `pulse.measure` function has been removed; explicit kernel/instruction creation required | qrn_tax_ddbb--b2882e02-ab8c-4201-8cd0-ca0cf2745d0a | pulse.measure |  |
  
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

print(schedule)
```