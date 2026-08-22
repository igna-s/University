| Line | Code | Scenario | Reference | Artifact | Refactoring |  
| :--: | :--- | :------- | :-------- | :------- | :---------- |  
| 2 | `from qiskit.providers.fake_provider import *` | Deprecation -> star import from fake_provider is deprecated | IK | qiskit.providers.fake_provider | `from qiskit.providers.fake_provider import FakeOpenPulse2Q` |  

```python
from qiskit import pulse
from qiskit.providers.fake_provider import FakeOpenPulse2Q

backend = FakeOpenPulse2Q()

d0 = pulse.DriveChannel(0)

with pulse.build() as pulse_prog:
    pulse.play(pulse.Constant(100, 0.5), d0)
```
