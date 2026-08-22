| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 6 | `d2 = pulse.DriveChannel(2)` | Deprecation -> `DriveChannel` moved to `qiskit.transpiler.Target` and `qiskit.circuit.channel` | qrn_ddbb-5096 | `pulse.DriveChannel` | `d2 = DriveChannel(2)` |
| 9 | `pulse.u2(0, math.pi, 0)` | Deprecation -> `pulse.u2` is deprecated. Use `qiskit.pulse.instructions.qiskit.pulse.instructions.Rz and qiskit.pulse.instructions.SX and qiskit.pulse.instructions.Rz` instead. | qrn_ddbb-c276 | `pulse.u2` | `pulse.rz(0, 0)`<br>`pulse.sx(0)`<br>`pulse.rz(math.pi, 0)` |
| 10 | `pulse.cx(0, 1)` | Deprecation -> `pulse.cx` is deprecated. Use `qiskit.pulse.instructions.CX` instead. | qrn_ddbb-a0f7 | `pulse.cx` | `pulse.cx(0, 1)` |
| 16 | `registers = pulse.measure_all()` | Deprecation -> `measure_all()` is deprecated. Use `qiskit.pulse.instructions.Measure` instead. | qrn_ddbb-e794 | `pulse.measure_all` | `registers = pulse.measure(0, 1, 2)` |
| 19 | `decoupled_bell_prep_and_measure.draw()` | Deprecation -> `QuantumCircuit.draw()` no longer supports the `plot_barrier` argument | qrn_ddbb-3d44 | `QuantumCircuit.draw()` | `decoupled_bell_prep_and_measure.draw(output='mpl')` |


```python
import math
from qiskit import pulse
from qiskit.providers.fake_provider import FakeOpenPulse3Q
from qiskit.circuit.channel import DriveChannel

backend = FakeOpenPulse3Q()
d2 = DriveChannel(2)
 
with pulse.build(backend) as bell_prep:
    pulse.rz(0, 0)
    pulse.sx(0)
    pulse.rz(math.pi, 0)
    pulse.cx(0, 1)
 
with pulse.build(backend) as decoupled_bell_prep_and_measure:
    with pulse.align_right():
        pulse.call(bell_prep)
        pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)
        pulse.barrier(0, 1, 2)
        registers = pulse.measure(0, 1, 2)
 
decoupled_bell_prep_and_measure.draw(output='mpl')
```