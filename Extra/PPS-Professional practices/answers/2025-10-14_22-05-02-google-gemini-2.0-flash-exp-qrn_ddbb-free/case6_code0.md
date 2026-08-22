| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import pulse` | Updated -> The package `qiskit.pulse` has been split up. | IK | qiskit.pulse | `from qiskit import QuantumCircuit, transpile, assemble, schedule` |
| 2 | `from qiskit.pulse import Gaussian` | Updated -> The package `qiskit.pulse` has been split up. | IK | qiskit.pulse | `from qiskit.pulse import Gaussian` |
| 3 | `from qiskit.providers import fake_provider` | Deprecation -> `fake_provider` is deprecated and will be removed in a future release. | qrn_ddbb-13ecf1b8d9a74836b37605c80691f41b | qiskit.providers | `from qiskit.test.mock import FakeOpenPulse3Q` |
| 5 | `backend = fake_provider.FakeOpenPulse3Q()` | Deprecation -> `fake_provider` is deprecated and will be removed in a future release. | qrn_ddbb-13ecf1b8d9a74836b37605c80691f41b | qiskit.providers | `backend = FakeOpenPulse3Q()` |

```python
from qiskit import QuantumCircuit, transpile, assemble, schedule
from qiskit.pulse import Gaussian
from qiskit.test.mock import FakeOpenPulse3Q

backend = FakeOpenPulse3Q()

with schedule.build(backend) as schedule:
    d0 = pulse.DriveChannel(0)
    pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16)
    pulse.play(pulse_obj, d0)
    pulse.delay(100, d0)
    pulse.measure(0)

print(schedule)
```