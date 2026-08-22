| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | from qiskit.providers import fake_provider | Deprecation -> The `qiskit.providers.fake_provider` module has been migrated to the qiskit-ibm-runtime package | qrn_notax_ddbb-aa6cda1f-af91-4940-8d4c-1897f9a56701 | qiskit.providers.fake_provider | from qiskit_ibm_runtime.fake_provider import FakeOpenPulse3Q |
| 5 | backend = fake_provider.FakeOpenPulse3Q() | Deprecation -> The `qiskit.providers.fake_provider.FakeOpenPulse3Q` backend should be imported from qiskit-ibm-runtime.fake_provider | qrn_notax_ddbb-aa6cda1f-af91-4940-8d4c-1897f9a56701 | FakeOpenPulse3Q | backend = FakeOpenPulse3Q() |

```python
from qiskit import pulse
from qiskit.pulse import Gaussian
from qiskit_ibm_runtime.fake_provider import FakeOpenPulse3Q

backend = FakeOpenPulse3Q()

with pulse.build(backend) as schedule:
    d0 = pulse.DriveChannel(0)
    pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16)
    pulse.play(pulse_obj, d0)
    pulse.delay(100, d0)
    pulse.measure(0)

print(schedule)
```