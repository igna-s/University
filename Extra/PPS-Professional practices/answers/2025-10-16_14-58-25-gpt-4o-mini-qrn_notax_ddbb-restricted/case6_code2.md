| Line | Code                                      | Scenario                                                                                         | Reference                                  | Artifact                     | Refactoring                                           |
| :--: | :--------------------------------------- | :----------------------------------------------------------------------------------------------- | :----------------------------------------: | :--------------------------- | :--------------------------------------------------- |
| 1    | `from qiskit import transpile, pulse`  | Deprecation -> Importing from qiskit.providers.fake_provider is deprecated                      | qrn_notax_ddbb-548acfe8-db26-45b7-ab5c-c637c63ee4b0 | qiskit.providers.fake_provider | `from qiskit import transpile, pulse`               |
| 2    | `from qiskit.providers.fake_provider import *` | Deprecation -> The fake_provider module has been migrated to the qiskit-ibm-runtime package    | qrn_notax_ddbb-aa6cda1f-af91-4940-8d4c-1897f9a56701 | qiskit.providers.fake_provider | leave this line out for compatibility                  |
| 4    | `backend = FakeOpenPulse2Q()`          | Update -> FakeOpenPulse2Q is deprecated                                                         | qrn_notax_ddbb-203ce4fc-c0db-4a02-805d-d3efbed47466 | FakeOpenPulse2Q              | `backend = GenericBackendV2()`                       |
| 6    | `pulse.play(pulse.Constant(100, 0.5), d0)`  | Deprecation -> Constant is deprecated                                                          | qrn_notax_ddbb-508fb6f3-cdfc-4b96-ad81-f550801dbe2f | pulse.Constant | `pulse.play(pulse.Gaussian(100, 0.5, 10).get_waveform(), d0)` |

```python
from qiskit import transpile, pulse
from qiskit.providers.fake_provider import GenericBackendV2

backend = GenericBackendV2()

d0 = pulse.DriveChannel(0)

with pulse.build() as pulse_prog:
    pulse.play(pulse.Gaussian(100, 0.5, 10).get_waveform(), d0)
```