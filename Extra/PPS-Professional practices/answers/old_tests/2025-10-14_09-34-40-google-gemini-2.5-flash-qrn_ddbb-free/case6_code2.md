| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.providers.fake_provider import *` | Module moved -> `qiskit.providers.fake_provider` module moved to `qiskit.providers.fake_backends` | Internal Knowledge | `qiskit.providers.fake_provider` | `from qiskit.providers.fake_backends import *` |


```python
from qiskit import transpile, pulse
from qiskit.providers.fake_backends import *
 
backend = FakeOpenPulse2Q()
 
d0 = pulse.DriveChannel(0)
 
with pulse.build() as pulse_prog:
    pulse.play(pulse.Constant(100, 0.5), d0)
```