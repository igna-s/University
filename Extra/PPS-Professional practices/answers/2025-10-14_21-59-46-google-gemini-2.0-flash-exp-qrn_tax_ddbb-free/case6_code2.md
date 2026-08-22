| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import transpile, pulse` |  Module Renamed -> The `pulse` module has been renamed to `qiskit.pulse` | qrn_tax_ddbb-3943cf6e | pulse | `from qiskit import transpile` |
| 1 | `from qiskit import transpile, pulse` |  New Location -> The `qiskit.pulse` module has been moved to `qiskit.pulse` | qrn_tax_ddbb-3943cf6e | pulse | `from qiskit import pulse` |
| 4 | `from qiskit.providers.fake_provider import *` | Package Renamed -> The package `qiskit.providers.fake_provider` has been renamed to `qiskit.providers.fake_backend` | qrn_tax_ddbb-4a94e564 | qiskit.providers.fake_provider | `from qiskit.providers.fake_backend import *` |

```python
from qiskit import transpile
from qiskit.providers.fake_backend import *
from qiskit import pulse
 
backend = FakeOpenPulse2Q()
 
d0 = pulse.DriveChannel(0)
 
with pulse.build() as pulse_prog:
    pulse.play(pulse.Constant(100, 0.5), d0)
```