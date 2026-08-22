| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `with pulse.build() as pulse_prog:` | Updated -> pulse.build context manager removed; use pulse.build function | IK | pulse.build | `pulse_prog = pulse.build(instructions=[pulse.play(pulse.Constant(100, 0.5), d0)], backend=backend)` |

```python
from qiskit import transpile, pulse
from qiskit.providers.fake_provider import *

backend = FakeOpenPulse2Q()

d0 = pulse.DriveChannel(0)

pulse_prog = pulse.build(
    instructions=[pulse.play(pulse.Constant(100, 0.5), d0)],
    backend=backend,
)
```