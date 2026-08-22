| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 5 | `with pulse.build() as pulse_prog:` | Deprecation -> The pulse.build() context manager is removed | qrn_tax_ddbb--03137c87-78b2-4922-b7b9-6419372e949d | pulse.build | `with pulse.program() as pulse_prog:` |

```python
from qiskit import transpile, pulse
from qiskit.providers.fake_provider import *

backend = FakeOpenPulse2Q()

d0 = pulse.DriveChannel(0)

with pulse.program() as pulse_prog:
    pulse.play(pulse.Constant(100, 0.5), d0)
```