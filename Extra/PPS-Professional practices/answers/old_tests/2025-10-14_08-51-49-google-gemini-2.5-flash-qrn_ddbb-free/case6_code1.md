| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 6 | `d2 = pulse.DriveChannel(2)` | Deprecation -> `DriveChannel` moved to `qiskit.transpiler.Target` and `qiskit.providers.backend` as device-specific objects. | Internal Knowledge | `pulse.DriveChannel` | |
| 9 | `pulse.u2(0, math.pi, 0)` | Deprecation -> The `u2` instruction is deprecated. | Internal Knowledge | `pulse.u2` | `pulse.rz(0); pulse.sx(0); pulse.rz(math.pi)` |
| 10 | `pulse.cx(0, 1)` | Deprecation -> The `cx` instruction is deprecated. | Internal Knowledge | `pulse.cx` | `pulse.h(0); pulse.cz(0, 1); pulse.h(0)` |
| 13 | `with pulse.align_right():` | Deprecation -> `align_right` is deprecated. | Internal Knowledge | `pulse.align_right` | `with pulse.transforms.block_to_schedule(backend) as decoupled_bell_prep_and_measure:` |
| 15 | `pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)` | Deprecation -> The `pulse.Constant` instruction is deprecated. | Internal Knowledge | `pulse.Constant` | `pulse.play(pulse.Constant(bell_prep.duration, 0.02), backend.channels.drive[2])` |
| 17 | `registers = pulse.measure_all()` | Deprecation -> `measure_all` is deprecated. | Internal Knowledge | `pulse.measure_all` | `registers = pulse.measure(0, 1, 2)` |


```python
import math
from qiskit import pulse
from qiskit.providers.fake_provider import FakeOpenPulse3Q

backend = FakeOpenPulse3Q()

with pulse.build(backend) as bell_prep:
    pulse.rz(0)
    pulse.sx(0)
    pulse.rz(math.pi)
    pulse.h(0)
    pulse.cz(0, 1)
    pulse.h(0)

with pulse.build(backend) as decoupled_bell_prep_and_measure:
    with pulse.transforms.block_to_schedule(backend) as decoupled_bell_prep_and_measure:
        pulse.call(bell_prep)
        pulse.play(pulse.Constant(bell_prep.duration, 0.02), backend.channels.drive[2])
        pulse.barrier(0, 1, 2)
        registers = pulse.measure(0, 1, 2)

decoupled_bell_prep_and_measure.draw()
```