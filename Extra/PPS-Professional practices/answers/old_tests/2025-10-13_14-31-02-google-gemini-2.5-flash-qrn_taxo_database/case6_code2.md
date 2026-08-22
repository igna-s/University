| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.providers.fake_provider import *` | Deprecation -> The `qiskit.providers.fake_provider` module is deprecated. | 23 | `e87b5b50-19b6-479a-8677-ad049ae04f4d` | `qiskit.providers.fake_provider` | Remove import |
| 4 | `backend = FakeOpenPulse2Q()` | Deprecation -> Running pulse jobs on `qiskit.providers.fake_provider` backends is deprecated and will be removed. | 6 | `7aad79e0-4c8d-459b-b706-58437a29ec5b` | `FakeOpenPulse2Q` | Remove line (pulse simulation on fake backends no longer supported) |
| 8 | `    pulse.play(pulse.Constant(100, 0.5), d0)` | Deprecation -> `Constant` pulse is deprecated, superseded by `SymbolicPulse`. | 17 | `a0bf665f-0ddf-4053-871e-ba32d3fe3428` | `pulse.Constant` | `pulse.library.Constant` |


```python
from qiskit import pulse
from qiskit.pulse import library

d0 = pulse.DriveChannel(0)

with pulse.build() as pulse_prog:
    pulse.play(library.Constant(100, 0.5), d0)
```