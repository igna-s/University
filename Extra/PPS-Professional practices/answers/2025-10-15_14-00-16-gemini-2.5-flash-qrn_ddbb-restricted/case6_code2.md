| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.providers.fake_provider import *` | Deprecation -> The qiskit.providers.fake_provider module has been migrated to the qiskit-ibm-runtime Python package. | aa6cda1f-af91-4940-8d4c-1897f9a56701 | qiskit.providers.fake_provider | `from qiskit_ibm_runtime.fake_provider import *` |
| 4 | `backend = FakeOpenPulse2Q()` | Deprecation -> Running pulse jobs on backends from qiskit.providers.fake_provider is deprecated, and all support will be removed in Qiskit 1.0. | 548acfe8-db26-45b7-ab5c-c637c63ee4b0 | FakeOpenPulse2Q | `backend = GenericBackendV2(num_qubits=2)` |
| 4 | `backend = FakeOpenPulse2Q()` | Deprecation -> FakeOpenPulse2Q has been superseded by the new GenericBackendV2 class. | aa6cda1f-af91-4940-8d4c-1897f9a56701 | FakeOpenPulse2Q | `backend = GenericBackendV2(num_qubits=2)` |


```python
from qiskit import transpile, pulse
from qiskit_ibm_runtime.fake_provider import *

backend = GenericBackendV2(num_qubits=2)

d0 = pulse.DriveChannel(0)

with pulse.build() as pulse_prog:
    pulse.play(pulse.Constant(100, 0.5), d0)
```