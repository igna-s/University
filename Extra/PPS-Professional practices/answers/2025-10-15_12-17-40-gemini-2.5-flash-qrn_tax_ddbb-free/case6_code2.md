| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.providers.fake_provider import *` | Deprecation -> The `qiskit.providers.fake_provider` module is deprecated | qrn_tax_ddbb--d7e68a47-8d01-4433-a93c-1aebfca5d9f4 | `qiskit.providers.fake_provider` | `from qiskit_ibm_runtime.fake_provider import *` |
| 4 | `backend = FakeOpenPulse2Q()` | Deprecation -> Specific fake backends are superseded by `GenericBackendV2` | qrn_tax_ddbb--6ecf0d75-110b-4dc1-8d77-d73f6b1eadb5 | `FakeOpenPulse2Q` | `backend = GenericBackendV2(num_qubits=2)` |


```python
from qiskit import transpile, pulse
from qiskit_ibm_runtime.fake_provider import *
 
backend = GenericBackendV2(num_qubits=2)
 
d0 = pulse.DriveChannel(0)
 
with pulse.build() as pulse_prog:
    pulse.play(pulse.Constant(100, 0.5), d0)
```