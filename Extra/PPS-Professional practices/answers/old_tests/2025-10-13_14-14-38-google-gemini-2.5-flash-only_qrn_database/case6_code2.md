| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.providers.fake_provider import *` | Deprecation -> The `qiskit.providers.fake_provider` module has been migrated to the `qiskit_ibm_runtime` Python package. For this reason, the elements in the `qiskit.providers.fake_provider` have been deprecated as of Qiskit 0.46 and will be removed in Qiskit 1.0. | * | 8857bf5d-09e4-4288-8051-2265f446768c | qiskit.providers.fake_provider | `from qiskit.providers.fake_provider import GenericBackendV2` |
| 4 | `backend = FakeOpenPulse2Q()` | Deprecation -> `FakeOpenPulse2Q` is deprecated. Running pulse jobs on backends from `qiskit.providers.fake_provider` is deprecated, and all support will be removed in Qiskit 1.0. This is due to Qiskit Aer removing its simulation functionality for such jobs. | * | 3e95df91-e1c5-4340-8243-daa95d502170 | FakeOpenPulse2Q | `backend = GenericBackendV2(num_qubits=2, pulse=True)` |
| 7 | `with pulse.build() as pulse_prog:` | Deprecation -> The `qiskit.pulse.build` function is deprecated. | * | Internal Knowledge | pulse.build() | `with pulse.builder.build() as pulse_prog:` |
| 8 | `pulse.play(pulse.Constant(100, 0.5), d0)` | Deprecation -> The `qiskit.pulse.play` function is deprecated. | * | Internal Knowledge | pulse.play() | `pulse.builder.play(pulse.Constant(100, 0.5), d0)` |


```python
from qiskit import transpile, pulse
from qiskit.providers.fake_provider import GenericBackendV2

backend = GenericBackendV2(num_qubits=2, pulse=True)

d0 = pulse.DriveChannel(0)

with pulse.builder.build() as pulse_prog:
    pulse.builder.play(pulse.Constant(100, 0.5), d0)
```