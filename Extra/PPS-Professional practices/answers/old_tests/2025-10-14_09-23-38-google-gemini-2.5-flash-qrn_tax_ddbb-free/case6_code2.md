| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.providers.fake_provider import *` | Deprecation -> `qiskit.providers.fake_provider` is deprecated. Use `qiskit_ibm_runtime.fake_provider` instead. | Internal Knowledge | `qiskit.providers.fake_provider` | `from qiskit_ibm_runtime.fake_provider import *` |
| 4 | `backend = FakeOpenPulse2Q()` | Deprecation -> `FakeOpenPulse2Q` is deprecated. Use `GenericBackendV2` instead. | Internal Knowledge | `FakeOpenPulse2Q` | `backend = GenericBackendV2(num_qubits=2, basis_gates=['u1', 'u2', 'u3', 'cx', 'id'], dtm=250.0, qubin=0)` |

```python
from qiskit import transpile, pulse
from qiskit_ibm_runtime.fake_provider import *

backend = GenericBackendV2(num_qubits=2, basis_gates=['u1', 'u2', 'u3', 'cx', 'id'], dtm=250.0, qubin=0)

d0 = pulse.DriveChannel(0)

with pulse.build() as pulse_prog:
    pulse.play(pulse.Constant(100, 0.5), d0)
```