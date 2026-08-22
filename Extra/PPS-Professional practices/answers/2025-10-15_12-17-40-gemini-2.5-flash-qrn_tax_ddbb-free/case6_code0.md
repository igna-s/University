| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.pulse import Gaussian` | Deprecation -> `Gaussian` pulse class migrated to `qiskit.pulse.library` | qrn_tax_ddbb--b5111ded-f178-4354-a8db-f475bdf64d57 | Gaussian | `from qiskit.pulse.library import Gaussian` |
| 3 | `from qiskit.providers import fake_provider` | Deprecation -> `qiskit.providers.fake_provider` module moved to `qiskit_ibm_runtime.fake_provider` | qrn_tax_ddbb--27ebf47d-f549-4a4b-ad7c-72ec480eb99d | fake_provider | `from qiskit_ibm_runtime import fake_provider` |
| 4 | `backend = fake_provider.FakeOpenPulse3Q()` | Deprecation -> Running pulse jobs on `fake_provider` backends is deprecated and `FakeOpenPulse3Q` is superseded by `GenericBackendV2` | qrn_tax_ddbb--4fa02758-623b-41e3-b4c5-3719c73896d2 | FakeOpenPulse3Q | `backend = fake_provider.GenericBackendV2(num_qubits=3)` |


```python
from qiskit import pulse
from qiskit.pulse.library import Gaussian
from qiskit_ibm_runtime import fake_provider

backend = fake_provider.GenericBackendV2(num_qubits=3)

with pulse.build(backend) as schedule:
    d0 = pulse.DriveChannel(0)
    pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16)
    pulse.play(pulse_obj, d0)
    pulse.delay(100, d0)
    pulse.measure(0)

print(schedule)
```