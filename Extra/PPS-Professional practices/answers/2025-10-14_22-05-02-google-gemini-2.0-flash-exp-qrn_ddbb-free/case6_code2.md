| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import transpile, pulse` | Deprecation -> The `qiskit.pulse` module is deprecated | qrn_ddbb-660c99f5b569f539978e9571c41f7b05 | qiskit.pulse | `from qiskit import transpile`\n`from qiskit import pulse as qiskit_pulse` |
| 4 | `backend = FakeOpenPulse2Q()` | Deprecation ->  `FakeOpenPulse2Q` is deprecated and will be removed in a future release.  | qrn_ddbb-9b885a5255417d238a98924798ef252f | FakeOpenPulse2Q | `backend = FakeBackendV2(num_qubits=2)` |
| 6 | `d0 = pulse.DriveChannel(0)` | Deprecation -> The `qiskit.pulse` module is deprecated | qrn_ddbb-660c99f5b569f539978e9571c41f7b05 | qiskit.pulse | `d0 = qiskit_pulse.DriveChannel(0)` |
| 8 | `with pulse.build() as pulse_prog:` | Deprecation -> The `qiskit.pulse` module is deprecated | qrn_ddbb-660c99f5b569f539978e9571c41f7b05 | qiskit.pulse | `with qiskit_pulse.build() as pulse_prog:` |
| 9 | `pulse.play(pulse.Constant(100, 0.5), d0)` | Deprecation -> The `qiskit.pulse` module is deprecated | qrn_ddbb-660c99f5b569f539978e9571c41f7b05 | qiskit.pulse | `qiskit_pulse.play(qiskit_pulse.Constant(100, 0.5), d0)` |

```python
from qiskit import transpile
from qiskit import pulse as qiskit_pulse
from qiskit.providers.fake_provider import *
backend = FakeBackendV2(num_qubits=2)
d0 = qiskit_pulse.DriveChannel(0)
with qiskit_pulse.build() as pulse_prog:
    qiskit_pulse.play(qiskit_pulse.Constant(100, 0.5), d0)
```