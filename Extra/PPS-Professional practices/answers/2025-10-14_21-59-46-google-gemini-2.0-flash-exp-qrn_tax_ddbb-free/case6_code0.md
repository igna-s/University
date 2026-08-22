| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import pulse` | Meta -> Changed pulse imports | IK | qiskit.pulse | `from qiskit import QuantumCircuit, transpile, schedule, pulse` |
| 3 | `from qiskit.providers import fake_provider` | Meta -> Changed fake_provider imports | IK | qiskit.providers.fake_provider | `from qiskit.test.mock import FakeOpenPulse3Q` |
| 5 | `backend = fake_provider.FakeOpenPulse3Q()` | Meta -> Changed fake_provider imports | IK | qiskit.providers.fake_provider | `backend = FakeOpenPulse3Q()` |
| 7 | `with pulse.build(backend) as schedule:` | Meta -> Changed pulse imports | IK | qiskit.pulse | `with pulse.build(backend=backend) as schedule:` |

```python
from qiskit import QuantumCircuit, transpile, schedule, pulse
from qiskit.pulse import Gaussian
from qiskit.test.mock import FakeOpenPulse3Q

backend = FakeOpenPulse3Q()

with pulse.build(backend=backend) as schedule:
    d0 = pulse.DriveChannel(0)
    pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16)
    pulse.play(pulse_obj, d0)
    pulse.delay(100, d0)
    pulse.measure(0)

print(schedule)
```