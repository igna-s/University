| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.providers.fake_provider import *` | Deprecation -> The qiskit.providers.fake_provider module has been migrated to the qiskit-ibm-runtime Python package and is deprecated. (optional) | 23 | e6060d0b-af91-4a01-b996-9b15437b5793 | qiskit.providers.fake_provider | `from qiskit_ibm_runtime.fake_provider import *` |
| 4 | `backend = FakeOpenPulse2Q()` | Deprecation -> FakeOpenPulse2Q is deprecated and superseded by GenericBackendV2. | 39 | 804bc312-98a2-49f4-879f-78949fb777aa | FakeOpenPulse2Q | `backend = GenericBackendV2(num_qubits=2)` |
| 4 | `backend = FakeOpenPulse2Q()` | Deprecation -> Deprecation of pulse jobs on fake_provider backends. (optional) | 6 | cfbb0eb4-ee5f-4b9f-a316-bdddcbe42a14 | FakeOpenPulse2Q | |
| 7 | `with pulse.build() as pulse_prog:` | Deprecation -> The `pulse.build()` context manager is deprecated. (optional) | * | Internal Knowledge | pulse.build | `pulse_prog = pulse.Schedule()` |
| 8 | `pulse.play(pulse.Constant(100, 0.5), d0)` | Deprecation -> The `pulse.play()` function is deprecated. (optional) | * | Internal Knowledge | pulse.play | `pulse_prog.append(pulse.Play(pulse.Constant(100, 0.5), d0))` |


```python
from qiskit import transpile, pulse
from qiskit_ibm_runtime.fake_provider import *

backend = GenericBackendV2(num_qubits=2)

d0 = pulse.DriveChannel(0)

pulse_prog = pulse.Schedule()
pulse_prog.append(pulse.Play(pulse.Constant(100, 0.5), d0))
```