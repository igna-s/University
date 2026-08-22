| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.pulse import Gaussian` | Deprecation -> `qiskit.pulse.Gaussian` has been removed | * | internal | qiskit.pulse.Gaussian | `from qiskit.pulse.amplitude import Gaussian` |
| 3 | `from qiskit.providers import fake_provider` | Deprecation -> `qiskit.providers.fake_provider` module has been migrated to the `qiskit-ibm-runtime` Python package. | 25 | bc39cc74-3382-4b55-bc9c-c44558547f03 | qiskit.providers.fake_provider | `from qiskit_ibm_runtime.fake_provider import FakeOpenPulse3Q` |
| 5 | `backend = fake_provider.FakeOpenPulse3Q()` | Deprecation -> `qiskit.providers.fake_provider` module has been migrated to the `qiskit-ibm-runtime` Python package. | 25 | bc39cc74-3382-4b55-bc9c-c44558547f03 | fake_provider.FakeOpenPulse3Q | `backend = FakeOpenPulse3Q()` |


```python
from qiskit import pulse
from qiskit.pulse.amplitude import Gaussian
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