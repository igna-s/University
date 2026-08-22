| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
|  |  |  |  |  |  |  |

```python
    from qiskit import transpile, pulse
from qiskit.providers.fake_provider import *
 
backend = FakeOpenPulse2Q()
 
d0 = pulse.DriveChannel(0)
 
with pulse.build() as pulse_prog:
    pulse.play(pulse.Constant(100, 0.5), d0)
```
