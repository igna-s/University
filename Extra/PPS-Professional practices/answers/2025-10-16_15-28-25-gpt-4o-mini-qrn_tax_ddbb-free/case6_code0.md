| Line | Code                                                | Scenario                                                      | Reference                                          | Artifact                 | Refactoring                                                               |
| :--: | :------------------------------------------------- | :-------                                                     | :-------                                          | :-------                 | :----------                                                              |
| 2    | `from qiskit.providers import fake_provider`       | Deprecation -> qiskit.providers.fake_provider is deprecated | qrn_tax_ddbb--5675e75e-e976-4a4d-a2c7-23dc577eab7d | fake_provider            | `from qiskit_ibm_runtime.fake_provider import FakeProvider`             |
| 5    | `backend = fake_provider.FakeOpenPulse3Q()`       | Deprecation -> backend from fake_provider is deprecated      | qrn_tax_ddbb--5675e75e-e976-4a4d-a2c7-23dc577eab7d | FakeOpenPulse3Q         | `backend = FakeProvider().get_backend("fake_open_pulse_3q")`          |

```python
from qiskit_ibm_runtime.fake_provider import FakeProvider

backend = FakeProvider().get_backend("fake_open_pulse_3q")

with pulse.build(backend) as schedule:
    d0 = pulse.DriveChannel(0)
    pulse_obj = pulse.Gaussian(duration=128, amp=0.5, sigma=16)
    pulse.play(pulse_obj, d0)
    pulse.delay(100, d0)
    pulse.measure(0)

print(schedule)
```