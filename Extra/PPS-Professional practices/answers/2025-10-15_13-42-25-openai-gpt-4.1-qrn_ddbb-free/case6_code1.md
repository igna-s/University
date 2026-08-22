| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 7 | `pulse.u2(0, math.pi, 0)` | Removal -> pulse.u2() has been removed in Qiskit 1.0.0 | IK | pulse.u2 | Replace with supported gate or pulse definition; use circuit-level approach for standard gates |
| 8 | `pulse.cx(0, 1)` | Removal -> pulse.cx() has been removed in Qiskit 1.0.0 | IK | pulse.cx | Replace with supported gate or pulse definition; use circuit-level approach for standard gates |
| 15 | `pulse.barrier(0, 1, 2)` | Removal -> pulse.barrier() has been removed in Qiskit 1.0.0 | IK | pulse.barrier | Remove—barrier is not available in pulse builder context |

```python
import math
from qiskit import pulse
from qiskit.providers.fake_provider import FakeOpenPulse3Q

backend = FakeOpenPulse3Q()
d2 = pulse.DriveChannel(2)
 
with pulse.build(backend) as bell_prep:
    # Define custom pulses or use play/call for qubit 0
    # Example for placeholder: pulse.play(pulse.Gaussian(...), pulse.DriveChannel(0))
    pass
 
with pulse.build(backend) as decoupled_bell_prep_and_measure:
    with pulse.align_right():
        pulse.call(bell_prep)
        pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)
        # pulse.barrier is removed; skip this line
        registers = pulse.measure_all()
 
decoupled_bell_prep_and_measure.draw()
```