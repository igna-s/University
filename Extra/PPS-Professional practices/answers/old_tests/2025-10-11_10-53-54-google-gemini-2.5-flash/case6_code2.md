| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.providers.fake_provider import *` | Deprecation -> The qiskit.providers.fake_provider module has been migrated to the qiskit-ibm-runtime Python package. | bc39cc74-3382-4b55-bc9c-c44558547f03 | 943c2cdd-5da0-4bef-a876-d781822244d8 | qiskit.providers.fake_provider | `from qiskit_ibm_runtime.fake_provider import *` |
| 4 | `backend = FakeOpenPulse2Q()` | Deprecation -> FakeProvider and fake backends moved to `qiskit_ibm_runtime.fake_provider` | * | 943c2cdd-5da0-4bef-a876-d781822244d8 | FakeOpenPulse2Q | `backend = FakeOpenPulse2Q()` |
| 4 | `backend = FakeOpenPulse2Q()` | Deprecation -> Deprecation of pulse jobs on fake_provider backends | 8 | 4ec56801-7f49-4393-8b0c-abb25d65aac5 | qiskit.providers.fake_provider | |


```python
from qiskit import transpile, pulse
from qiskit_ibm_runtime.fake_provider import *

backend = FakeOpenPulse2Q()

d0 = pulse.DriveChannel(0)

with pulse.build() as pulse_prog:
    pulse.play(pulse.Constant(100, 0.5), d0)
```