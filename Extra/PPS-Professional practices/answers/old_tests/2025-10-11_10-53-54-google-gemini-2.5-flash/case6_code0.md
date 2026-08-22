| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.pulse import Gaussian` | Deprecation -> `qiskit.pulse.Gaussian` moved to `qiskit.circuit.library.GaussianPulse` | * | internal | qiskit.pulse.Gaussian | `from qiskit.circuit.library import GaussianPulse` |
| 3 | `from qiskit.providers import fake_provider` | Structural change -> `qiskit.providers.fake_provider` moved to `qiskit_ibm_runtime.fake_provider` | 40 | 943c2cdd-5da0-4bef-a876-d781822244d8 | qiskit.providers.fake_provider | `from qiskit_ibm_runtime.fake_provider import FakeOpenPulse3Q` |
| 5 | `backend = fake_provider.FakeOpenPulse3Q()` | Structural change -> `fake_provider.FakeOpenPulse3Q` should be imported directly or replaced by `GenericBackendV2` | 40 | 943c2cdd-5da0-4bef-a876-d781822244d8 | fake_provider.FakeOpenPulse3Q | `backend = FakeOpenPulse3Q()` |
| 9 | `pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16)` | Deprecation -> `Gaussian` class renamed to `GaussianPulse` | * | internal | Gaussian | `pulse_obj = GaussianPulse(duration=128, amp=0.5, sigma=16)` |


```python
from qiskit import pulse
from qiskit.circuit.library import GaussianPulse
from qiskit_ibm_runtime.fake_provider import FakeOpenPulse3Q

backend = FakeOpenPulse3Q()

with pulse.build(backend) as schedule:
    d0 = pulse.DriveChannel(0)
    pulse_obj = GaussianPulse(duration=128, amp=0.5, sigma=16)
    pulse.play(pulse_obj, d0)
    pulse.delay(100, d0)
    pulse.measure(0)

print(schedule)
```