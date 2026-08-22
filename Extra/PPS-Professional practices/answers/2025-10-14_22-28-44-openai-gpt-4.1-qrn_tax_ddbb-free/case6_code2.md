| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 2 | from qiskit.providers.fake_provider import * | Deprecation -> Wildcard import is discouraged and partial module reorganization in 1.0.0 | qrn_tax_ddbb-0e1ea8cb2e454a80a33782ecc35fa817 | qiskit.providers.fake_provider | from qiskit.providers.fake_provider import FakeOpenPulse2Q |
| 4 | backend = FakeOpenPulse2Q() | Deprecation -> Some fake backends relocated/renamed under 'qiskit.providers.fake_provider' | qrn_tax_ddbb-0e1ea8cb2e454a80a33782ecc35fa817 | FakeOpenPulse2Q | backend = FakeOpenPulse2Q() |
| 6 | d0 = pulse.DriveChannel(0) | API Change -> pulse.DriveChannel now accessed from qiskit.pulse.channels | qrn_tax_ddbb-abfd81169f98617df70bf172eacb6b03 | pulse.DriveChannel | from qiskit.pulse.channels import DriveChannel \n d0 = DriveChannel(0) |
| 8 | with pulse.build() as pulse_prog: | API Change -> pulse.build context manager now at qiskit.pulse.builder | qrn_tax_ddbb-e68e1ec800b7d7d50d72b0b6673ea420 | pulse.build | from qiskit.pulse import builder \n with builder.build() as pulse_prog: |
| 9 | pulse.play(pulse.Constant(100, 0.5), d0) | API Change -> pulse.play now at qiskit.pulse.builder (use builder.play), Constant now at qiskit.pulse.library | qrn_tax_ddbb-9edf6e23edd932998f97a17e731a3a43 | pulse.play, pulse.Constant | from qiskit.pulse.library import Constant \n builder.play(Constant(100, 0.5), d0) |

```python
from qiskit import transpile
from qiskit.providers.fake_provider import FakeOpenPulse2Q
from qiskit.pulse.channels import DriveChannel
from qiskit.pulse import builder
from qiskit.pulse.library import Constant

backend = FakeOpenPulse2Q()

d0 = DriveChannel(0)

with builder.build() as pulse_prog:
    builder.play(Constant(100, 0.5), d0)
```