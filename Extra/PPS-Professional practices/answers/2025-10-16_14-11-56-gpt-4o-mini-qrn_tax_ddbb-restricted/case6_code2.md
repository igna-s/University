| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 2 | `from qiskit.providers.fake_provider import *` | Deprecation -> Running pulse jobs on backends from qiskit.providers.fake_provider is deprecated | qrn_tax_ddbb-6ecf0d75-110b-4dc1-8d77-d73f6b1eadb5 | qiskit.providers.fake_provider | `from qiskit.providers.fake_provider import GenericBackendV2` | 
| 4 | `backend = FakeOpenPulse2Q()` | Structural change -> Migration: Special fake backends superseded by GenericBackendV2 | qrn_tax_ddbb-6ecf0d75-110b-4dc1-8d77-d73f6b1eadb5 | FakeOpenPulse2Q | `backend = GenericBackendV2(num_qubits=2)` | 
| 6 | `d0 = pulse.DriveChannel(0)` | Deprecation -> Use of discrete pulse library is deprecated | qrn_tax_ddbb-b04b3fd0-03ff-4ee8-b78b-a5219681461e | qiskit.pulse | `d0 = pulse.DriveChannel(0)` |
| 8 | `pulse.play(pulse.Constant(100, 0.5), d0)` | Deprecation -> Constant pulse is deprecated | qrn_tax_ddbb-17c3e95b-4a93-4760-912d-6cdb59f594e3 | pulse.Constant | `pulse.play(pulse.SymbolicPulse.from_waveform(pulse.Constant(100, 0.5)), d0)` |

```python
from qiskit import transpile, pulse
from qiskit.providers.fake_provider import GenericBackendV2

backend = GenericBackendV2(num_qubits=2)

d0 = pulse.DriveChannel(0)

with pulse.build() as pulse_prog:
    pulse.play(pulse.SymbolicPulse.from_waveform(pulse.Constant(100, 0.5)), d0)
```