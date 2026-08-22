| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.providers.fake_provider import *` | Deprecation -> The `qiskit.providers.fake_provider` module has been migrated to `qiskit-ibm-runtime` and specific classes like `FakeOpenPulse2Q` are deprecated. | * | 8857bf5d-09e4-4288-8051-2265f446768c | qiskit.providers.fake_provider | `from qiskit.providers.fake_provider import GenericBackendV2` |
| 4 | `backend = FakeOpenPulse2Q()` | Deprecation -> The `FakeOpenPulse2Q` class has been superseded by `GenericBackendV2`. | * | c4cd73f0-8f65-4176-a8da-ce2f599538b3 | FakeOpenPulse2Q | `backend = GenericBackendV2(num_qubits=2)` |


```python
from qiskit import transpile, pulse
from qiskit.providers.fake_provider import GenericBackendV2

backend = GenericBackendV2(num_qubits=2)

d0 = pulse.DriveChannel(0)

with pulse.build() as pulse_prog:
    pulse.play(pulse.Constant(100, 0.5), d0)
```