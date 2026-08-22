| Line | Code | Refactoring | Reference | Scenario | New Code |
|------|------|-------------|-----------|----------|----------|
| 3 | `from qiskit.providers import fake_provider` | Replace fake_provider import with PulseSimulator from qiskit_aer | `084696d9-2c75-437a-8e84-96506e6766aa` | Deprecation of fake_provider import | `from qiskit_aer.backends import PulseSimulator` |
| 5 | `backend = fake_provider.FakeOpenPulse3Q()` | Replace fake provider backend with PulseSimulator | `084696d9-2c75-437a-8e84-96506e6766aa` | Deprecation of fake provider backend | `backend = PulseSimulator()` |
| 9 | `pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16)` | Use `get_waveform()` to avoid parametric pulse | `fcb14a10-22cd-4440-b488-df6f988e16ca` | Deprecation of Gaussian pulse usage | `pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16).get_waveform()` |

```python
from qiskit import pulse
from qiskit.pulse import Gaussian
from qiskit_aer.backends import PulseSimulator

backend = PulseSimulator()

with pulse.build(backend) as schedule:
    d0 = pulse.DriveChannel(0)
    pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16).get_waveform()
    pulse.play(pulse_obj, d0)
    pulse.delay(100, d0)
    pulse.measure(0)

print(schedule)
```