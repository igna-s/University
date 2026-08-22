| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.providers.fake_provider import *` | Deprecation -> `qiskit.providers.fake_provider` module moved | Internal Knowledge | `qiskit.providers.fake_provider` | `from qiskit.test.mock import *` |
| 4 | `backend = FakeOpenPulse2Q()` | Deprecation -> `FakeOpenPulse2Q` class moved and renamed | Internal Knowledge | `FakeOpenPulse2Q` | `backend = MockOpenPulse2Q()` |


```python
from qiskit import transpile, pulse
from qiskit.test.mock import *
 
backend = MockOpenPulse2Q()
 
d0 = pulse.DriveChannel(0)
 
with pulse.build() as pulse_prog:
    pulse.play(pulse.Constant(100, 0.5), d0)
```