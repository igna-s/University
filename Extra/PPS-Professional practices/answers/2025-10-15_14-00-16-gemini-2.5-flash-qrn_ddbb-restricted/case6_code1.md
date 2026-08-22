| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :------- | :------- | :---------- |
| 3 | `from qiskit.providers.fake_provider import FakeOpenPulse3Q` | Deprecation -> `qiskit.providers.fake_provider` module is deprecated. | qrn_notax_ddbb-aa6cda1f-af91-4940-8d4c-1897f9a56701 | qiskit.providers.fake_provider.FakeOpenPulse3Q | `from qiskit.providers.fake_provider import GenericBackendV2` |
| 5 | `backend = FakeOpenPulse3Q()` | Deprecation -> Running pulse jobs on backends from `qiskit.providers.fake_provider` is deprecated. `FakeOpenPulse3Q` is superseded by `GenericBackendV2` for testing. | qrn_notax_ddbb-548acfe8-db26-45b7-ab5c-c637c63ee4b0 | FakeOpenPulse3Q | `backend = GenericBackendV2(num_qubits=3)` |
| 9 | `    pulse.u2(0, math.pi, 0)` | Deprecation -> Injecting circuit gate operations (`u2`) directly into the pulse builder context is deprecated. | qrn_notax_ddbb-40b23f17-56a0-470c-b53e-f33e2e193b17 | pulse.u2 | These circuit operations should be defined within a `QuantumCircuit`, which is then transpiled and scheduled. The resulting schedule can then be called using `pulse.call()` inside the pulse builder. |
| 10 | `    pulse.cx(0, 1)` | Deprecation -> Injecting circuit gate operations (`cx`) directly into the pulse builder context is deprecated. | qrn_notax_ddbb-40b23f17-56a0-470c-b53e-f33e2e193b17 | pulse.cx | These circuit operations should be defined within a `QuantumCircuit`, which is then transpiled and scheduled. The resulting schedule can then be called using `pulse.call()` inside the pulse builder. |
| 14 | `        pulse.call(bell_prep)` | Changed -> `bell_prep` refers to the `ScheduleBlock` from a context manager. When replacing direct gate injections, `bell_prep` should now refer to a scheduled `QuantumCircuit`. | IK | bell_prep | `pulse.call(bell_prep_schedule)` |
| 15 | `        pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)` | Deprecation -> `ParametricPulse` base class and pulses like `Constant` are deprecated. Replace with `SymbolicPulse` and its `amp` keyword argument. | qrn_notax_ddbb-508fb6f3-cdfc-4b96-ad81-f550801dbe2f | pulse.Constant | `pulse.play(pulse.Constant(bell_prep_schedule.duration, amp=0.02), d2)` |


```python
import math
from qiskit import pulse, QuantumCircuit
from qiskit.providers.fake_provider import GenericBackendV2
from qiskit.compiler import schedule, transpile

backend = GenericBackendV2(num_qubits=3)
d2 = pulse.DriveChannel(2)

# Create a QuantumCircuit for the gates
qc_bell_prep = QuantumCircuit(3)
qc_bell_prep.u2(0, math.pi, 0)
qc_bell_prep.cx(0, 1)

# Transpile and schedule the QuantumCircuit
transpiled_qc_bell_prep = transpile(qc_bell_prep, backend)
scheduled_bell_prep = schedule(transpiled_qc_bell_prep, backend)

with pulse.build(backend) as bell_prep_schedule:
    pulse.call(scheduled_bell_prep)

with pulse.build(backend) as decoupled_bell_prep_and_measure:
    with pulse.align_right():
        pulse.call(bell_prep_schedule)
        pulse.play(pulse.Constant(bell_prep_schedule.duration, amp=0.02), d2)
        pulse.barrier(0, 1, 2)
        registers = pulse.measure_all()

decoupled_bell_prep_and_measure.draw()
```