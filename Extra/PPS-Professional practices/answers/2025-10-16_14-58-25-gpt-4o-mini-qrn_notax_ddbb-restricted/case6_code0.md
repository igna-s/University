| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import pulse` | Deprecation -> Importing from qiskit.providers.fake_provider is deprecated | qrn_notax_ddbb-aa6cda1f-af91-4940-8d4c-1897f9a56701 | qiskit.providers.fake_provider | `from qiskit_ibm_runtime.fake_provider import FakeProvider` |
| 2 | `from qiskit.pulse import Gaussian` | Deprecation -> Gaussian is deprecated | qrn_notax_ddbb-508fb6f3-cdfc-4b96-ad81-f550801dbe2f | qiskit.pulse | `from qiskit.pulse import SymbolicPulse` |
| 4 | `backend = fake_provider.FakeOpenPulse3Q()` | Deprecated -> FakeOpenPulse3Q is deprecated | qrn_notax_ddbb-aa6cda1f-af91-4940-8d4c-1897f9a56701 | fake_provider | `backend = GenericBackendV2()` |
| 6 | `pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16)` | Deprecated -> Use of Gaussian should be replaced with SymbolicPulse method | qrn_notax_ddbb-508fb6f3-cdfc-4b96-ad81-f550801dbe2f | Gaussian | `pulse_obj = SymbolicPulse(duration=128, amp=0.5, sigma=16).get_waveform()` |

```python
from qiskit_ibm_runtime.fake_provider import FakeProvider
from qiskit.pulse import SymbolicPulse

backend = GenericBackendV2()

with pulse.build(backend) as schedule:
    d0 = pulse.DriveChannel(0)
    pulse_obj = SymbolicPulse(duration=128, amp=0.5, sigma=16).get_waveform()
    pulse.play(pulse_obj, d0)
    pulse.delay(100, d0)
    pulse.measure(0)

print(schedule)
```