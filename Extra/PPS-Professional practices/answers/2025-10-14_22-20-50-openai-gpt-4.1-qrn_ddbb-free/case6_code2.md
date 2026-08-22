| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import transpile, pulse` | Deprecation -> `qiskit.pulse` deprecated, moved to `qiskit_pulse` namespace | qrn_ddbb-4b1935cfa87e41ffbd3e88e47a0af21a | qiskit.pulse | `from qiskit_qec.pulse import pulse` (substitute usages of pulse with qiskit_qec.pulse or the new location) |
| 2 | `from qiskit.providers.fake_provider import *` | Deprecation -> `FakeOpenPulse2Q` now found in `qiskit.providers.fake_provider.backends` | qrn_ddbb-fd1bdb5f242c497bad9c99e17b5daf87 | FakeOpenPulse2Q | `from qiskit.providers.fake_provider.backends import FakeOpenPulse2Q` |
| 5 | `d0 = pulse.DriveChannel(0)` | Migration -> DriveChannel must be imported from namespace, not accessed through pulse | qrn_ddbb-0aac9ab0b594456aa828f4b6024dd42f | DriveChannel | `from qiskit.pulse.channels import DriveChannel` and use `DriveChannel(0)` |
| 7 | `with pulse.build() as pulse_prog:` | Deprecation -> `qiskit.pulse.build` is now under new pulse module | qrn_ddbb-4b1935cfa87e41ffbd3e88e47a0af21a | pulse.build | Use the latest import as per new namespace |
| 8 | `pulse.play(pulse.Constant(100, 0.5), d0)` | Migration -> pulse.Constant and play now imported from pulse.instructions | qrn_ddbb-9be6f69a8c7e41659e51dbeefc38a9e6 | pulse.Constant, pulse.play | `from qiskit.pulse.instructions import Play, Constant` and create `Play(Constant(...), d0)` |

```python
from qiskit import transpile
from qiskit.providers.fake_provider.backends import FakeOpenPulse2Q
from qiskit.pulse.channels import DriveChannel
from qiskit.pulse import build
from qiskit.pulse.instructions import Play, Constant

backend = FakeOpenPulse2Q()

d0 = DriveChannel(0)

with build() as pulse_prog:
    Play(Constant(100, 0.5), d0)
```