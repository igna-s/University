| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit.providers.fake_provider import FakeOpenPulse3Q` | Deprecation -> The qiskit.providers.fake_provider module has been migrated to the qiskit-ibm-runtime Python package. | 38 | 8ac21514-86a7-4cbb-b4aa-413e2c7cc479 | qiskit.providers.fake_provider | `from qiskit_ibm_runtime.fake_provider import FakeOpenPulse3Q` |
| 5 | `backend = FakeOpenPulse3Q()` | Deprecation -> Running pulse jobs on backends from qiskit.providers.fake_provider is deprecated. | 6 | 7aad79e0-4c8d-459b-b706-58437a29ec5b | FakeOpenPulse3Q | `backend = FakeOpenPulse3Q()` |
| 8 | `pulse.u2(0, math.pi, 0)` | Deprecation -> `u2` instruction is deprecated. | * | Internal Knowledge | pulse.u2 | `pulse.rz(0, 0)`<br>`pulse.sx(0)`<br>`pulse.rz(math.pi, 0)` |
| 9 | `pulse.cx(0, 1)` | Deprecation -> `cx` instruction is deprecated. | * | Internal Knowledge | pulse.cx | `pulse.cx(0, 1)` |
| 11 | `with pulse.build(backend) as decoupled_bell_prep_and_measure:` | Deprecation -> `pulse.build()` has deprecated arguments. | * | Internal Knowledge | pulse.build | `with pulse.build() as decoupled_bell_prep_and_measure:` |
| 13 | `pulse.call(bell_prep)` | Deprecation -> `pulse.call` is deprecated. | * | Internal Knowledge | pulse.call | `pulse.call(bell_prep)` |
| 14 | `pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)` | Deprecation -> `pulse.Constant` is deprecated. | * | Internal Knowledge | pulse.Constant | `pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)` |
| 15 | `pulse.barrier(0, 1, 2)` | Deprecation -> `pulse.barrier` is deprecated. | * | Internal Knowledge | pulse.barrier | `pulse.barrier(0, 1, 2)` |
| 16 | `registers = pulse.measure_all()` | Deprecation -> `pulse.measure_all` is deprecated. | * | Internal Knowledge | pulse.measure_all | `registers = pulse.measure_all()` |
| 18 | `decoupled_bell_prep_and_measure.draw()` | Deprecation -> `Schedule.draw()` is deprecated. | * | Internal Knowledge | decoupled_bell_prep_and_measure.draw | `decoupled_bell_prep_and_measure.draw()` |


```python
import math
from qiskit_ibm_runtime.fake_provider import FakeOpenPulse3Q
from qiskit import pulse

backend = FakeOpenPulse3Q()
d2 = pulse.DriveChannel(2)

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
        registers = pulse.measure_all()

decoupled_bell_prep_and_measure.draw()
```