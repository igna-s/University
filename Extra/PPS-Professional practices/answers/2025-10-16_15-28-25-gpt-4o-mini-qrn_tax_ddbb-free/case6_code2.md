| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 1 | `from qiskit import transpile, pulse` | Deprecation -> Running pulse jobs on backends from qiskit.providers.fake_provider is deprecated | IK | qiskit.providers.fake_provider | `from qiskit import transpile` | 
| 2 | `from qiskit.providers.fake_provider import *` | Deprecation -> Importing from qiskit.providers.fake_provider is deprecated | IK | qiskit.providers.fake_provider | `from qiskit.providers.fake_provider import GenericBackendV2` | 
| 4 | `backend = FakeOpenPulse2Q()` | Deprecation -> all support will be removed in Qiskit 1.0 for fake backends | IK | FakeOpenPulse2Q | `backend = GenericBackendV2()` | 
| 6 | `with pulse.build() as pulse_prog:` | Deprecation -> Running pulse jobs on backends from qiskit.providers.fake_provider is deprecated | IK | pulse.build | `with pulse.build() as pulse_prog:` | 
| 7 | `    pulse.play(pulse.Constant(100, 0.5), d0)` | Deprecation -> Injecting circuit gate operations into the pulse builder context is now deprecated | IK | pulse.play | `    pulse.play(pulse.Constant(100, 0.5), d0)` | 

```python
from qiskit import transpile
from qiskit.providers.fake_provider import GenericBackendV2

backend = GenericBackendV2()

d0 = pulse.DriveChannel(0)

with pulse.build() as pulse_prog:
    pulse.play(pulse.Constant(100, 0.5), d0)
```