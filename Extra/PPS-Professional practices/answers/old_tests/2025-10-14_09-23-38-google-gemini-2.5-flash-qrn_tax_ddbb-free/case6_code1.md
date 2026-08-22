| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit import pulse` | Deprecation -> The pulse submodule is deprecated | Internal Knowledge | qiskit.pulse | `from qiskit import circuit, schedule` |
| 3 | `from qiskit.providers.fake_provider import FakeOpenPulse3Q` | Deprecation -> The `qiskit.providers.fake_provider` module is deprecated. | qrn_tax_ddbb-a67b | qiskit.providers.fake_provider | `from qiskit.test.mock import FakeOpenPulse3Q` |
| 6 | `d2 = pulse.DriveChannel(2)` | Deprecation -> `pulse.DriveChannel` is deprecated | qrn_tax_ddbb-e9a6 | pulse.DriveChannel | `d2 = schedule.DriveChannel(2)` |
| 8 | `with pulse.build(backend) as bell_prep:` | Deprecation -> `pulse.build` is deprecated. | qrn_tax_ddbb-4786 | pulse.build | `with schedule.build(backend) as bell_prep:` |
| 9 | `pulse.u2(0, math.pi, 0)` | Deprecation -> `pulse.u2` is deprecated. | qrn_tax_ddbb-4a7b | pulse.u2 | `circuit.u2(0, math.pi, 0)` |
| 10 | `pulse.cx(0, 1)` | Deprecation -> `pulse.cx` is deprecated. | qrn_tax_ddbb-4a7b | pulse.cx | `circuit.cx(0, 1)` |
| 12 | `with pulse.build(backend) as decoupled_bell_prep_and_measure:` | Deprecation -> `pulse.build` is deprecated. | qrn_tax_ddbb-4786 | pulse.build | `with schedule.build(backend) as decoupled_bell_prep_and_measure:` |
| 13 | `with pulse.align_right():` | Deprecation -> `pulse.align_right` is deprecated. | qrn_tax_ddbb-4a7b | pulse.align_right | `with schedule.align_right():` |
| 14 | `pulse.call(bell_prep)` | Deprecation -> `pulse.call` is deprecated. | qrn_tax_ddbb-4a7b | pulse.call | `schedule.call(bell_prep)` |
| 15 | `pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)` | Deprecation -> `pulse.play` is deprecated. | qrn_tax_ddbb-4a7b | pulse.play | `schedule.play(schedule.Constant(bell_prep.duration, 0.02), d2)` |
| 16 | `pulse.barrier(0, 1, 2)` | Deprecation -> `pulse.barrier` is deprecated. | qrn_tax_ddbb-4a7b | pulse.barrier | `schedule.barrier(0, 1, 2)` |
| 17 | `registers = pulse.measure_all()` | Deprecation -> `pulse.measure_all` is deprecated. | qrn_tax_ddbb-4a7b | pulse.measure_all | `registers = schedule.measure_all()` |
| 19 | `decoupled_bell_prep_and_measure.draw()` | Deprecation -> The `schedule.draw()` method is deprecated. | qrn_tax_ddbb-4a7b | .draw() | `decoupled_bell_prep_and_measure.draw(backend=backend)` |


```python
import math
from qiskit import circuit, schedule
from qiskit.test.mock import FakeOpenPulse3Q

backend = FakeOpenPulse3Q()
d2 = schedule.DriveChannel(2)

with schedule.build(backend) as bell_prep:
    circuit.u2(0, math.pi, 0)
    circuit.cx(0, 1)

with schedule.build(backend) as decoupled_bell_prep_and_measure:
    with schedule.align_right():
        schedule.call(bell_prep)
        schedule.play(schedule.Constant(bell_prep.duration, 0.02), d2)
        schedule.barrier(0, 1, 2)
        registers = schedule.measure_all()

decoupled_bell_prep_and_measure.draw(backend=backend)
```