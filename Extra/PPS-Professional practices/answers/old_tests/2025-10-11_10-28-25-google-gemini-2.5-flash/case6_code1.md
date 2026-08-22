| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit.providers.fake_provider import FakeOpenPulse3Q` | Deprecation -> Running pulse jobs on `fake_provider` backends is deprecated. | 1f5a35a2-9fb1-431b-8aec-35c0fe26e1bf | blob | `FakeOpenPulse3Q` | `from qiskit.providers.fake_provider import GenericBackendV2` |
| 5 | `backend = FakeOpenPulse3Q()` | Deprecation -> Using `FakeOpenPulse3Q` for pulse jobs is deprecated. | 1f5a35a2-9fb1-431b-8aec-35c0fe26e1bf | blob | `FakeOpenPulse3Q()` | `backend = GenericBackendV2(num_qubits=3, calibrate_pulse_gates=True)` |
| 7 | `with pulse.build(backend) as bell_prep:` | Deprecation -> Injecting circuit gate operations into pulse builder context is deprecated. `pulse.build()` no longer accepts a `backend` argument for this purpose. | ca8c2398-fc43-4a47-8972-db38e866fa32 | blob | `pulse.build(backend)` | This block is refactored into `QuantumCircuit`, `transpile`, and `schedule` to create `bell_prep_sched`. |
| 8 | `    pulse.u2(0, math.pi, 0)` | Deprecation -> Injecting circuit gate operations (`u2`) into pulse builder context is deprecated, and `u2` gate is removed. | ca8c2398-fc43-4a47-8972-db38e866fa32 | blob | `pulse.u2` | Replaced by `qc_bell_prep.sx(0)` and `qc_bell_prep.rz(math.pi, 0)` within a `QuantumCircuit`. |
| 9 | `    pulse.cx(0, 1)` | Deprecation -> Injecting circuit gate operations (`cx`) into pulse builder context is deprecated. | ca8c2398-fc43-4a47-8972-db38e866fa32 | blob | `pulse.cx` | Replaced by `qc_bell_prep.cx(0, 1)` within a `QuantumCircuit`. |
| 11 | `with pulse.build(backend) as decoupled_bell_prep_and_measure:` | API Change -> The `pulse.build()` function no longer accepts a `backend` argument. | * | internal | `pulse.build(backend)` | `with pulse.build() as decoupled_bell_prep_and_measure:` |
| 12 | `        pulse.call(bell_prep)` | API Change -> The `bell_prep` object is now a `Schedule` derived from a `QuantumCircuit` via `schedule()`. | * | internal | `bell_prep` | `pulse.call(bell_prep_sched)` |
| 13 | `        pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)` | API Change -> The `bell_prep` object is now a `Schedule` derived from a `QuantumCircuit` via `schedule()`. | * | internal | `bell_prep.duration` | `bell_prep_sched.duration` |


```python
import math
from qiskit import pulse, QuantumCircuit
from qiskit.providers.fake_provider import GenericBackendV2
from qiskit.compiler import schedule, transpile

backend = GenericBackendV2(num_qubits=3, calibrate_pulse_gates=True)
d2 = pulse.DriveChannel(2)

# Create a QuantumCircuit for the bell_prep gates
qc_bell_prep = QuantumCircuit(2)
# u2(0, math.pi, 0) is decomposed as sx(0) rz(math.pi, 0) in Qiskit 1.0.0+
qc_bell_prep.sx(0)
qc_bell_prep.rz(math.pi, 0)
qc_bell_prep.cx(0, 1)

# Transpile and schedule the circuit to get a pulse schedule
qc_bell_prep_t = transpile(qc_bell_prep, backend)
bell_prep_sched = schedule(qc_bell_prep_t, backend)

with pulse.build() as decoupled_bell_prep_and_measure:
    with pulse.align_right():
        pulse.call(bell_prep_sched)
        pulse.play(pulse.Constant(bell_prep_sched.duration, 0.02), d2)
        pulse.barrier(0, 1, 2)
        registers = pulse.measure_all()

decoupled_bell_prep_and_measure.draw()
```