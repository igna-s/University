| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.providers.fake_provider import *` | Deprecation -> qiskit.providers.fake_provider module is deprecated | f24d40d4-9a98-4431-85f5-3e6f98fee373 | qiskit.providers.fake_provider | `from qiskit_ibm_runtime.fake_provider import FakeOpenPulse2Q` |

```python
from qiskit import transpile, pulse
from qiskit_ibm_runtime.fake_provider import FakeOpenPulse2Q

backend = FakeOpenPulse2Q()

d0 = pulse.DriveChannel(0)

with pulse.build() as pulse_prog:
    pulse.play(pulse.Constant(100, 0.5), d0)
```