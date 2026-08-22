| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.providers.fake_provider import FakeOpenPulse3Q` | Deprecation -> The `qiskit.providers.fake_provider` module has been migrated to the `qiskit-ibm-runtime` Python package. | * | 8857bf5d-09e4-4288-8051-2265f446768c | qiskit.providers.fake_provider | `from qiskit_ibm_runtime.fake_provider import FakeOpenPulse3Q` |
| 4 | `backend = FakeOpenPulse3Q()` | Deprecation -> Running pulse jobs on backends from `qiskit.providers.fake_provider` is deprecated, and all support will be removed in Qiskit 1.0. | * | 3e95df91-e1c5-4340-8243-daa95d502170 | FakeOpenPulse3Q | |


```python
import math
from qiskit_ibm_runtime.fake_provider import FakeOpenPulse3Q
from qiskit import pulse

backend = FakeOpenPulse3Q()
d2 = pulse.DriveChannel(2)
 
with pulse.build(backend) as bell_prep:
    pulse.u2(0, math.pi, 0)
    pulse.cx(0, 1)
 
with pulse.build(backend) as decoupled_bell_prep_and_measure:
    with pulse.align_right():
        pulse.call(bell_prep)
        pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)
        pulse.barrier(0, 1, 2)
        registers = pulse.measure_all()
 
decoupled_bell_prep_and_measure.draw()
```