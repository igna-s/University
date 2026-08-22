| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit.providers.fake_provider import FakeOpenPulse3Q` | Deprecation -> The `qiskit.providers.fake_provider` module has been migrated to the `qiskit_ibm_runtime` Python package; `FakeOpenPulse3Q` superseded by `GenericBackendV2` | qrn_tax_ddbb-27ebf47d-f549-4a4b-ad7c-72ec480eb99d | qiskit.providers.fake_provider.FakeOpenPulse3Q | `from qiskit_ibm_runtime.fake_provider import GenericBackendV2` |
| 5 | `backend = FakeOpenPulse3Q()` | Structural change -> `FakeOpenPulse3Q` superseded by `GenericBackendV2` | qrn_tax_ddbb-6ecf0d75-110b-4dc1-8d77-d73f6b1eadb5 | FakeOpenPulse3Q | `backend = GenericBackendV2(num_qubits=3)` |
| 9 | `pulse.u2(0, math.pi, 0)` | Deprecation -> Injecting circuit gate operations into the pulse builder context is deprecated | qrn_tax_ddbb-4f791e8e-887c-47d9-80fa-50227b769092 | pulse.builder | |
| 10 | `pulse.cx(0, 1)` | Deprecation -> Injecting circuit gate operations into the pulse builder context is deprecated | qrn_tax_ddbb-4f791e8e-887c-47d9-80fa-50227b769092 | pulse.builder | |
| 16 | `pulse.Constant(bell_prep.duration, 0.02)` | Deprecation -> ParametricPulse base class and pulses are deprecated, including Constant | qrn_tax_ddbb-b5111ded-f178-4354-a8db-f475bdf64d57 | Constant | `pulse.library.Constant(bell_prep.duration, 0.02)` |


```python
import math
from qiskit import pulse
from qiskit_ibm_runtime.fake_provider import GenericBackendV2

backend = GenericBackendV2(num_qubits=3)
d2 = pulse.DriveChannel(2)
 
with pulse.build(backend) as bell_prep:
    # pulse.u2(0, math.pi, 0) # Deprecated in pulse.build context
    # pulse.cx(0, 1) # Deprecated in pulse.build context
    pass
 
with pulse.build(backend) as decoupled_bell_prep_and_measure:
    with pulse.align_right():
        pulse.call(bell_prep)
        pulse.play(pulse.library.Constant(bell_prep.duration, 0.02), d2)
        pulse.barrier(0, 1, 2)
        registers = pulse.measure_all()
 
decoupled_bell_prep_and_measure.draw()
```