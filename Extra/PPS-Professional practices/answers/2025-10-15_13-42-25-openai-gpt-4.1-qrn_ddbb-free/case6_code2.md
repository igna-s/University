| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 2 | `from qiskit.providers.fake_provider import *` | Import change -> qiskit.providers.fake_provider moved to qiskit.providers.fake_provider.backends | qrn_notax_ddbb--b2048bdf-4974-4b18-889f-2f46c31e1bca | qiskit.providers.fake_provider | `from qiskit.providers.fake_provider.backends import *` |
| 4 | `backend = FakeOpenPulse2Q()` | Module path update -> FakeOpenPulse2Q moved to qiskit.providers.fake_provider.backends | qrn_notax_ddbb--b2048bdf-4974-4b18-889f-2f46c31e1bca | FakeOpenPulse2Q | `backend = FakeOpenPulse2Q()` |

```python
from qiskit import transpile, pulse
from qiskit.providers.fake_provider.backends import *

backend = FakeOpenPulse2Q()

d0 = pulse.DriveChannel(0)

with pulse.build() as pulse_prog:
    pulse.play(pulse.Constant(100, 0.5), d0)
```