| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.pulse import Gaussian` | Deprecation -> ParametricPulse and pulses deprecated | qrn_notax_ddbb-508fb6f3-cdfc-4b96-ad81-f550801dbe2f | Gaussian | `from qiskit.pulse.library import Gaussian` |
| 3 | `from qiskit.providers import fake_provider` | Deprecation -> qiskit.providers.fake_provider module migrated | qrn_notax_ddbb-aa6cda1f-af91-4940-8d4c-1897f9a56701 | fake_provider | `from qiskit_ibm_runtime.fake_provider import GenericBackendV2` |
| 5 | `backend = fake_provider.FakeOpenPulse3Q()` | Deprecation -> Fake backends superseded by GenericBackendV2 | qrn_notax_ddbb-8fa78c41-fe65-4855-a211-6812b683b158 | fake_provider.FakeOpenPulse3Q | `backend = GenericBackendV2(num_qubits=3)` |


```python
from qiskit import pulse
from qiskit.pulse.library import Gaussian
from qiskit_ibm_runtime.fake_provider import GenericBackendV2

backend = GenericBackendV2(num_qubits=3)

with pulse.build(backend) as schedule:
    d0 = pulse.DriveChannel(0)
    pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16)
    pulse.play(pulse_obj, d0)
    pulse.delay(100, d0)
    pulse.measure(0)

print(schedule)
```