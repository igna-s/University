| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import pulse` | Deprecation -> pulse functionality on fake_provider backends is deprecated | qrn_tax_ddbb-40a2b284-ffbb-4e7f-8042-3892bbb00583 | qiskit.providers.fake_provider |  |
| 2 | `from qiskit.pulse import Gaussian` | Deprecation -> Gaussian pulse class is deprecated | qrn_tax_ddbb-7bf6a882-1ff2-461f-b97b-9aeaf737333d | qiskit.pulse | `from qiskit.pulse import SymbolicPulse` |
| 3 | `from qiskit.providers import fake_provider` | Deprecation -> fake_provider is deprecated | qrn_tax_ddbb-084696d9-2c75-437a-8e84-96506e6766aa | qiskit.providers.fake_provider | `from qiskit.providers.basic_provider import BasicProvider` |
| 5 | `backend = fake_provider.FakeOpenPulse3Q()` | Deprecation -> Usage of FakeOpenPulse3Q is deprecated | qrn_tax_ddbb-4eac3cea-1324-4c47-9db5-0bc5765e8775 | qiskit.providers.fake_provider | `backend = BasicProvider().get_backend("basic_simulator")` |
| 7 | `pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16)` | Deprecation -> Gaussian pulse is deprecated | qrn_tax_ddbb-b5111ded-f178-4354-a8db-f475bdf64d57 | qiskit.pulse | `pulse_obj = SymbolicPulse(128, 0.5, 16).get_waveform()` |
| 9 | `pulse.play(pulse_obj, d0)` | Deprecation -> pulse.play is deprecated | qrn_tax_ddbb-7bf6a882-1ff2-461f-b97b-9aeaf737333d | qiskit.pulse | `pulse.call(pulse_obj)` |
| 10 | `pulse.delay(100, d0)` | Deprecation -> pulse.delay method exists but implied changes due to context | qrn_tax_ddbb-7bf6a882-1ff2-461f-b97b-9aeaf737333d | qiskit.pulse |  |
| 11 | `pulse.measure(0)` | Deprecation -> pulse.measure method exists but implied changes due to context | qrn_tax_ddbb-7bf6a882-1ff2-461f-b97b-9aeaf737333d | qiskit.pulse |  |

```python
from qiskit import pulse
from qiskit.pulse import SymbolicPulse
from qiskit.providers.basic_provider import BasicProvider

backend = BasicProvider().get_backend("basic_simulator")

with pulse.build(backend) as schedule:
    d0 = pulse.DriveChannel(0)
    pulse_obj = SymbolicPulse(128, 0.5, 16).get_waveform()
    pulse.call(pulse_obj)
    pulse.delay(100, d0)
    pulse.measure(0)

print(schedule)
```