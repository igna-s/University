| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.pulse import Gaussian` | Deprecation -> ParametricPulse base class and pulses are now deprecated | 90 | 4a85ead9-680f-49b5-b1dc-982401b98f61 | qiskit.pulse.Gaussian | `from qiskit.pulse.library import Gaussian` |
| 3 | `from qiskit.providers import fake_provider` | Deprecation -> qiskit.providers.fake_provider module has been migrated to the qiskit-ibm-runtime Python package | * | 8857bf5d-09e4-4288-8051-2265f446768c | qiskit.providers.fake_provider | `from qiskit_ibm_runtime.fake_provider import FakeOpenPulse3Q` |
| 5 | `backend = fake_provider.FakeOpenPulse3Q()` | Deprecation -> Running pulse jobs on backends from qiskit.providers.fake_provider is deprecated | * | 3e95df91-e1c5-4340-8243-daa95d502170 | fake_provider.FakeOpenPulse3Q | `backend = FakeOpenPulse3Q()` |


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