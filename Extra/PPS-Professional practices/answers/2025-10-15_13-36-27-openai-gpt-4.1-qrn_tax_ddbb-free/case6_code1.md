| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 7 | `pulse.u2(0, math.pi, 0)` | Removal -> pulse.u2() was removed in Qiskit 1.0.0 | qrn_tax_ddbb--8a44d75e-81f4-4a77-87b7-56d0073be9e6 | pulse.u2 | `pulse.play(pulse.Gaussian(duration, amp, sigma), d0)` (update with equivalent schedule) |
| 8 | `pulse.cx(0, 1)` | Removal -> pulse.cx() was removed in Qiskit 1.0.0 | qrn_tax_ddbb--aa12e78f-31c2-4a8b-9026-ac6b7ec3d6e1 | pulse.cx | Use proper pulse/play instructions to implement CX |
| 13 | `pulse.barrier(0, 1, 2)` | Removal -> pulse.barrier() was removed in Qiskit 1.0.0 | qrn_tax_ddbb--4e92a017-ffb9-4a4f-b800-5247b3f81f7d | pulse.barrier | Remove or replace with a scheduling context manager |
| 14 | `registers = pulse.measure_all()` | Removal -> pulse.measure_all() was removed in Qiskit 1.0.0 | qrn_tax_ddbb--8e2aae73-356a-49c2-8952-46ecccfe9608 | pulse.measure_all | Use appropriate measure scheduling with Play/Acquire instructions |

```python
import math
from qiskit import pulse
from qiskit.providers.fake_provider import FakeOpenPulse3Q

backend = FakeOpenPulse3Q()
d2 = pulse.DriveChannel(2)
d0 = pulse.DriveChannel(0)
d1 = pulse.DriveChannel(1)
m0 = pulse.MeasureChannel(0)
m1 = pulse.MeasureChannel(1)
m2 = pulse.MeasureChannel(2)
acq0 = pulse.AcquireChannel(0)
acq1 = pulse.AcquireChannel(1)
acq2 = pulse.AcquireChannel(2)

with pulse.build(backend) as bell_prep:
    # Replace u2 gate with a custom pulse (e.g., Gaussian)
    pulse.play(pulse.Gaussian(duration=128, amp=0.5, sigma=32), d0)
    # Replace cx with custom cross-resonance or two-qubit pulses
    pulse.play(pulse.Gaussian(duration=256, amp=0.3, sigma=64), d1)

with pulse.build(backend) as decoupled_bell_prep_and_measure:
    with pulse.align_right():
        pulse.call(bell_prep)
        pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)
        # Synchronize manually if needed (no barrier)
        pulse.acquire(512, acq0, pulse.MemorySlot(0))
        pulse.acquire(512, acq1, pulse.MemorySlot(1))
        pulse.acquire(512, acq2, pulse.MemorySlot(2))

decoupled_bell_prep_and_measure.draw()
```