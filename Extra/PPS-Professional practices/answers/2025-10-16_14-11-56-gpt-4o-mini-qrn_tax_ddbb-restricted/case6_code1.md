| Line | Code | Scenario | Reference | Artifact | Refactoring |  
| :--: | :--- | :------- | :-------: | :------- | :---------- |  
| 2 | `from qiskit.providers.fake_provider import FakeOpenPulse3Q` | Deprecation -> The FakeOpenPulse3Q class is deprecated | qrn_tax_ddbb-4fa02758-623b-41e3-b4c5-3719c73896d2 | qiskit.providers.fake_provider | `from qiskit.providers import fake_provider` |  
| 4 | `backend = FakeOpenPulse3Q()` | Deprecation -> The FakeOpenPulse3Q class is deprecated | qrn_tax_ddbb-4fa02758-623b-41e3-b4c5-3719c73896d2 | qiskit.providers.fake_provider | `backend = FakeBackend()` |  
| 7 | `pulse.u2(0, math.pi, 0)` | Deprecation -> The u2() function is deprecated | qrn_tax_ddbb-4f791e8e-887c-47d9-80fa-50227b769092 | qiskit.pulse | `pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)` |  

```python
import math
from qiskit import pulse
from qiskit.providers import fake_provider

backend = FakeBackend()
d2 = pulse.DriveChannel(2)

with pulse.build(backend) as bell_prep:
    pulse.cx(0, 1)

with pulse.build(backend) as decoupled_bell_prep_and_measure:
    with pulse.align_right():
        pulse.call(bell_prep)
        pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)
        pulse.barrier(0, 1, 2)
        registers = pulse.measure_all()

decoupled_bell_prep_and_measure.draw()
```