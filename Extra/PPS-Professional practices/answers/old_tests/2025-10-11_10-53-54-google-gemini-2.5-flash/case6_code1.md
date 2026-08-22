| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.providers.fake_provider import FakeOpenPulse3Q` | Deprecation -> The qiskit.providers.fake_provider module has been migrated to the qiskit-ibm-runtime Python package. | 943c2cdd-5da0-4bef-a876-d781822244d8 | 96533960-c282-41c1-86d8-f9bc7fa809d8 | qiskit.providers.fake_provider.FakeOpenPulse3Q | `from qiskit_ibm_runtime.fake_provider import FakeOpenPulse3Q` |
| 5 | `backend = FakeOpenPulse3Q()` | Deprecation -> Running pulse jobs on backends from qiskit.providers.fake_provider is deprecated, and all support will be removed in Qiskit 1.0. | 1f5a35a2-9fb1-431b-8aec-35c0fe26e1bf | 4ec56801-7f49-4393-8b0c-abb25d65aac5 | FakeOpenPulse3Q | `backend = GenericBackendV2(num_qubits=3, control_channels=[[1, 0]], drive_channels=[(0, 1.0, 0.0), (1, 1.0, 0.0), (2, 1.0, 0.0)])` |


```python
import math
from qiskit_ibm_runtime.fake_provider import FakeOpenPulse3Q
from qiskit.providers.fake_provider import GenericBackendV2
from qiskit import pulse

backend = GenericBackendV2(num_qubits=3, control_channels=[[1, 0]], drive_channels=[(0, 1.0, 0.0), (1, 1.0, 0.0), (2, 1.0, 0.0)])
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