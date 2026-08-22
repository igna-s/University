| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.pulse import Gaussian` | Deprecation -> The `Gaussian` class is deprecated. It has been superseded by `SymbolicPulse` and the corresponding pulse library. | qrn_tax_ddbb-b5111ded-f178-4354-a8db-f475bdf64d57 | `qiskit.pulse.Gaussian` | `from qiskit.pulse.library import Gaussian as SymbolicGaussian` |
| 3 | `from qiskit.providers import fake_provider` | Deprecation -> The `qiskit.providers.fake_provider` module is deprecated and has been migrated to `qiskit_ibm_runtime.fake_provider`. | qrn_tax_ddbb-d7e68a47-8d01-4433-a93c-1aebfca5d9f4 | `qiskit.providers.fake_provider` | `from qiskit.providers.fake_provider import GenericBackendV2` |
| 5 | `backend = fake_provider.FakeOpenPulse3Q()` | Deprecation -> Fake backends like `FakeOpenPulse3Q` are deprecated and superseded by the new `GenericBackendV2` class. Running pulse jobs on `fake_provider` backends is also deprecated. | qrn_tax_ddbb-4eac3cea-1324-4c47-9db5-0bc5765e8775 | `fake_provider.FakeOpenPulse3Q` | `backend = GenericBackendV2(num_qubits=3)` |
| 9 | `pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16)` | Deprecation -> The `Gaussian` class is deprecated. It has been superseded by `SymbolicPulse` and the corresponding pulse library. | qrn_tax_ddbb-b5111ded-f178-4354-a8db-f475bdf64d57 | `Gaussian` | `pulse_obj = SymbolicGaussian(duration=128, amp=0.5, sigma=16)` |


```python
from qiskit import pulse
from qiskit.pulse.library import Gaussian as SymbolicGaussian
from qiskit.providers.fake_provider import GenericBackendV2

backend = GenericBackendV2(num_qubits=3)

with pulse.build(backend) as schedule:
    d0 = pulse.DriveChannel(0)
    pulse_obj = SymbolicGaussian(duration=128, amp=0.5, sigma=16)
    pulse.play(pulse_obj, d0)
    pulse.delay(100, d0)
    pulse.measure(0)

print(schedule)
```