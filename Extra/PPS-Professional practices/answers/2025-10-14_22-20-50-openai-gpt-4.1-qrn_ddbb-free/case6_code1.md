| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | from qiskit import pulse | Deprecation -> Some pulse module gate functions (`u2`, `cx`, `barrier`, `measure_all`) are deprecated in favor of working with schedules or calibrated gates. | qrn_ddbb-d3d9d3c0-8f73-43e5-9ae3-617bf0607640 | qiskit.pulse |  |
| 3 | from qiskit.providers.fake_provider import FakeOpenPulse3Q | Deprecation -> Running pulse jobs on backends from `qiskit.providers.fake_provider` is deprecated. Use GenericBackendV2 instead. | qrn_ddbb-31f0ecfd-f398-43e4-8297-263f360dff81 | qiskit.providers.fake_provider.FakeOpenPulse3Q | from qiskit.providers.fake_provider import GenericBackendV2 |
| 4 | backend = FakeOpenPulse3Q() | Deprecation -> Running pulse jobs on FakeOpenPulse3Q is deprecated. | qrn_ddbb-31f0ecfd-f398-43e4-8297-263f360dff81 | FakeOpenPulse3Q | backend = GenericBackendV2(num_qubits=3) |
| 6 | with pulse.build(backend) as bell_prep: | API Change -> pulse.u2, pulse.cx are deprecated in pulse. | qrn_ddbb-d3d9d3c0-8f73-43e5-9ae3-617bf0607640 | pulse.u2, pulse.cx |  |
| 7 | pulse.u2(0, math.pi, 0) | Deprecation -> pulse.u2() is deprecated in favor of using circuits and calibration.Schedule | qrn_ddbb-d3d9d3c0-8f73-43e5-9ae3-617bf0607640 | pulse.u2 | See note below |
| 8 | pulse.cx(0, 1) | Deprecation -> pulse.cx() is deprecated in favor of using circuits and calibration.Schedule | qrn_ddbb-d3d9d3c0-8f73-43e5-9ae3-617bf0607640 | pulse.cx | See note below |
| 11 | pulse.barrier(0, 1, 2) | Deprecation -> pulse.barrier() is deprecated, not supported in pulse circuitry | qrn_ddbb-d3d9d3c0-8f73-43e5-9ae3-617bf0607640 | pulse.barrier | (Remove or replace functionality) |
| 12 | registers = pulse.measure_all() | Deprecation -> pulse.measure_all() is deprecated; use circuit and `schedule()` | qrn_ddbb-d3d9d3c0-8f73-43e5-9ae3-617bf0607640 | pulse.measure_all |  | 
| 10 | pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2) | Deprecation -> pulse.Constant() is deprecated; use pulse.Constant.get_waveform() if applicable | qrn_ddbb-18e49d39-25cd-41a4-8e0e-2906dea4fc9f | pulse.Constant | pulse.play(pulse.Constant(bell_prep.duration, 0.02).get_waveform(), d2) |

```python
import math
from qiskit import pulse
from qiskit.providers.fake_provider import GenericBackendV2
from qiskit.circuit import QuantumCircuit
from qiskit.compiler import schedule, transpile

backend = GenericBackendV2(num_qubits=3)
d2 = pulse.DriveChannel(2)

# Instead of using pulse.u2 and pulse.cx, define the equivalent quantum circuit
qc = QuantumCircuit(3)
qc.u(math.pi/2, 0, math.pi, 0)
qc.cx(0, 1)

qc_t = transpile(qc, backend)
bell_prep_sched = schedule(qc_t, backend)

with pulse.build(backend) as bell_prep:
    pulse.call(bell_prep_sched)

with pulse.build(backend) as decoupled_bell_prep_and_measure:
    with pulse.align_right():
        pulse.call(bell_prep)
        pulse.play(pulse.Constant(bell_prep.duration, 0.02).get_waveform(), d2)
        # pulse.barrier is deprecated and removed, manual timing/alignment must be managed
        # pulse.measure_all deprecated, measurement handled via circuit/schedule if needed

decoupled_bell_prep_and_measure.draw()
```
