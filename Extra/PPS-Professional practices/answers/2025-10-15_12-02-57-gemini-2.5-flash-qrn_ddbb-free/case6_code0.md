| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.pulse import Gaussian` | Deprecation -> ParametricPulse and pulses are now deprecated | 508fb6f3-cdfc-4b96-ad81-f550801dbe2f | Gaussian | `from qiskit.pulse.library import Gaussian` |
| 3 | `from qiskit.providers import fake_provider` | Deprecation -> The qiskit.providers.fake_provider module has been migrated to the qiskit-ibm-runtime Python package | aa6cda1f-af91-4940-8d4c-1897f9a56701 | qiskit.providers.fake_provider | `from qiskit_ibm_runtime.fake_provider import FakeOpenPulse3Q` |
| 5 | `backend = fake_provider.FakeOpenPulse3Q()` | Deprecation -> Fake backends superseded by GenericBackendV2 class | aa6cda1f-af91-4940-8d4c-1897f9a56701 | fake_provider.FakeOpenPulse3Q | `backend = FakeOpenPulse3Q()` |


```python
from qiskit import pulse
from qiskit.pulse.library import Gaussian
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