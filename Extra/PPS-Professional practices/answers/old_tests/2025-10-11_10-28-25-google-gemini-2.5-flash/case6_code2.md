| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.providers.fake_provider import *` | Deprecation -> The qiskit.providers.fake_provider module has been migrated to the qiskit-ibm-runtime Python package. | bc39cc74-3382-4b55-bc9c-c44558547f03 | 96533960-c282-41c1-86d8-f9bc7fa809d8 | qiskit.providers.fake_provider | `from qiskit_ibm_runtime.fake_provider import *` |
| 4 | `backend = FakeOpenPulse2Q()` | Deprecation -> Special fake backends are superseded by GenericBackendV2 | c2c72864-60b6-4a05-8ba8-ea04f14a65c0 | c2c72864-60b6-4a05-8ba8-ea04f14a65c0 | FakeOpenPulse2Q | `backend = GenericBackendV2(num_qubits=2, basis_gates=['sx', 'rz', 'ecr'])` |
| 7 | `with pulse.build() as pulse_prog:` | Deprecation -> Deprecation of pulse jobs on fake_provider backends. (optional) | 4ec56801-7f49-4393-8b0c-abb25d65aac5 | 4ec56801-7f49-4393-8b0c-abb25d65aac5 | pulse.build() | `with pulse.build(backend=backend) as pulse_prog:` |


```python
from qiskit import transpile, pulse
from qiskit_ibm_runtime.fake_provider import *

backend = GenericBackendV2(num_qubits=2, basis_gates=['sx', 'rz', 'ecr'])

d0 = pulse.DriveChannel(0)

with pulse.build(backend=backend) as pulse_prog:
    pulse.play(pulse.Constant(100, 0.5), d0)
```