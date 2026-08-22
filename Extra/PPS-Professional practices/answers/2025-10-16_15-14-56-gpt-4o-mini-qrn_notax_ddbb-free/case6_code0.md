| Line | Code                                            | Scenario                                                        | Reference                                      | Artifact                     | Refactoring                                                          |
| :--: | :---------------------------------------------- | :-------                                                       | :--------------------------------------------- | :--------------------------- | :------------------------------------------------------------------- |
| 1    | `from qiskit import pulse`                     | Deprecation -> The pulse module is deprecated                  | qrn_notax_ddbb-aa6cda1f-af91-4940-8d4c-1897f9a56701 | qiskit.pulse                | `from qiskit.pulse import Gaussian`                                  |
| 2    | `from qiskit.pulse import Gaussian`           | Updated -> Gaussian class moved to a different module          | qrn_notax_ddbb-75b1b2e6-8a53-49df-9caa-0a183b4c4a70 | qiskit.pulse                | `from qiskit.pulse import Gaussian`                                  |
| 3    | `from qiskit.providers import fake_provider`   | Deprecation -> The fake_provider module is deprecated          | qrn_notax_ddbb-203ce4fc-c0db-4a02-805d-d3efbed47466 | qiskit.providers.fake_provider | `from qiskit_ibm_runtime.fake_provider import FakeProvider`         |
| 5    | `backend = fake_provider.FakeOpenPulse3Q()`   | Deprecation -> FakeOpenPulse3Q() is deprecated                 | qrn_notax_ddbb-aa6cda1f-af91-4940-8d4c-1897f9a56701 | fake_provider                | `backend = FakeProvider().get_backend("fake_open_pulse_3q")`       |

```python
from qiskit.pulse import Gaussian
from qiskit_ibm_runtime.fake_provider import FakeProvider

backend = FakeProvider().get_backend("fake_open_pulse_3q")

with pulse.build(backend) as schedule:
    d0 = pulse.DriveChannel(0)
    pulse_obj = Gaussian(duration=128, amp=0.5, sigma=16)
    pulse.play(pulse_obj, d0)
    pulse.delay(100, d0)
    pulse.measure(0)

print(schedule)
```