| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 3 | `from qiskit.providers.fake_provider import FakeOpenPulse3Q` | Deprecation -> Using pulse jobs on backends from `qiskit.providers.fake_provider` is deprecated | qrn_tax_ddbb--27ebf47d-f549-4a4b-ad7c-72ec480eb99d | qiskit.providers.fake_provider | `from qiskit_ibm_runtime.fake_provider import FakeOpenPulse3Q` |
| 5 | `backend = FakeOpenPulse3Q()` | Deprecation -> Using pulse jobs on backends from `qiskit.providers.fake_provider` is deprecated | qrn_tax_ddbb--27ebf47d-f549-4a4b-ad7c-72ec480eb99d | FakeOpenPulse3Q | `backend = FakeOpenPulse3Q()` |
| 8 | `pulse.u2(0, math.pi, 0)` | Deprecation -> The `u2` function is deprecated | qrn_tax_ddbb--b5111ded-f178-4354-a8db-f475bdf64d57 | pulse | `pulse.gaussian(0, math.pi, 0)` |
| 12 | `pulse.cx(0, 1)` | Deprecation -> Using `cx` is not deprecated but will require adjustment in context of deprecated pulse builder iterations | IK | pulse | `pulse.cx(0, 1)` |
| 16 | `pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)` | Deprecation -> `Constant` pulse class is deprecated | qrn_tax_ddbb--b5111ded-f178-4354-a8db-f475bdf64d57 | pulse | `pulse.play(pulse.SymbolicPulse(duration=bell_prep.duration, amp=0.02), d2)` |

```python  
import math
from qiskit_ibm_runtime.fake_provider import FakeOpenPulse3Q
from qiskit import pulse

backend = FakeOpenPulse3Q()
d2 = pulse.DriveChannel(2)
 
with pulse.build(backend) as bell_prep:
    pulse.gaussian(0, math.pi, 0)
    pulse.cx(0, 1)
 
with pulse.build(backend) as decoupled_bell_prep_and_measure:
    with pulse.align_right():
        pulse.call(bell_prep)
        pulse.play(pulse.SymbolicPulse(duration=bell_prep.duration, amp=0.02), d2)
        pulse.barrier(0, 1, 2)
        registers = pulse.measure_all()
 
decoupled_bell_prep_and_measure.draw()
```