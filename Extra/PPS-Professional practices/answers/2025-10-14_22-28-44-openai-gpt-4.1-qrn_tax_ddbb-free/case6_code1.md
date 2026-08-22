| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | from qiskit import pulse | No major change (optional) | IK | qiskit.pulse |  |
| 3 | from qiskit.providers.fake_provider import FakeOpenPulse3Q | Deprecation -> The qiskit.providers.fake_provider module is deprecated | qrn_tax_ddbb-159727fb-bfcb-493c-8585-1df5caa7c111 | qiskit.providers.fake_provider | from qiskit_ibm_runtime.fake_provider import FakeOpenPulse3Q |
| 7 | d2 = pulse.DriveChannel(2) | No major change (optional) | IK | pulse.DriveChannel |  |
| 10 | with pulse.build(backend) as bell_prep: | No major change (optional) | IK | pulse.build |  |
| 11 | pulse.u2(0, math.pi, 0) | Deprecation -> pulse.u2() is deprecated in pulse builder context | IK | pulse.u2 | Use circuit gates via QuantumCircuit and pulse.call, or use symbolic pulse, or custom waveform |
| 12 | pulse.cx(0, 1) | Deprecation -> pulse.cx() is deprecated in pulse builder context | IK | pulse.cx | Use circuit gates via QuantumCircuit and pulse.call, or use symbolic pulse, or custom waveform |
| 15 | with pulse.build(backend) as decoupled_bell_prep_and_measure: | No major change (optional) | IK | pulse.build |  |
| 16 | with pulse.align_right(): | No major change (optional) | IK | pulse.align_right |  |
| 17 | pulse.call(bell_prep) | No major change (optional) | IK | pulse.call |  |
| 18 | pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2) | No major change (optional) | IK | pulse.play |  |
| 19 | pulse.barrier(0, 1, 2) | No major change (optional) | IK | pulse.barrier |  |
| 20 | registers = pulse.measure_all() | No major change (optional) | IK | pulse.measure_all |  |
| 22 | decoupled_bell_prep_and_measure.draw() | No major change (optional) | IK | draw |  |

```python
import math
from qiskit import pulse
from qiskit_ibm_runtime.fake_provider import FakeOpenPulse3Q

backend = FakeOpenPulse3Q()
d2 = pulse.DriveChannel(2)

from qiskit import QuantumCircuit

qc = QuantumCircuit(3)
qc.u2(0, math.pi, 0)
qc.cx(0, 1)

with pulse.build(backend) as bell_prep:
    pulse.call(qc)

with pulse.build(backend) as decoupled_bell_prep_and_measure:
    with pulse.align_right():
        pulse.call(bell_prep)
        pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)
        pulse.barrier(0, 1, 2)
        registers = pulse.measure_all()

decoupled_bell_prep_and_measure.draw()
```