| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :------- | :------- | :---------- |
| 1 | `from qiskit import transpile, pulse` | Update -> Explicit imports for pulse components. Remove `transpile` as it's unused. | IK | `qiskit.pulse`, `qiskit.transpile` | `from qiskit.pulse.channels import DriveChannel`<br>`from qiskit.pulse import build, ScheduleBlock, SymbolicPulse` |
| 2 | `from qiskit.providers.fake_provider import *` | Deprecation -> `qiskit.providers.fake_provider` module migrated to `qiskit_ibm_runtime.fake_provider`; deprecated for pulse jobs. | `qrn_tax_ddbb-27ebf47d-f549-4a4b-ad7c-72ec480eb99d` | `qiskit.providers.fake_provider` | (Remove line as its purpose for pulse is deprecated) |
| 3 | `backend = FakeOpenPulse2Q()` | Deprecation -> `FakeOpenPulse2Q` is deprecated; pulse jobs on `fake_provider` backends are deprecated. | `qrn_tax_ddbb-6ecf0d75-110b-4dc1-8d77-d73f6b1eadb5`<br>`qrn_tax_ddbb-084696d9-2c75-437a-8e84-96506e6766aa` | `FakeOpenPulse2Q` | (Remove line as its purpose for pulse is deprecated) |
| 4 | `d0 = pulse.DriveChannel(0)` | Update -> Use explicit `DriveChannel` import. | IK | `pulse.DriveChannel` | `d0 = DriveChannel(0)` |
| 5 | `with pulse.build() as pulse_prog:` | Deprecation -> Internal pulse instruction addition mechanism within `pulse.build()` changed. | `qrn_tax_ddbb-7bf6a882-1ff2-461f-b97b-9aeaf737333d` | `pulse.build` | `with build() as pulse_prog:` |
| 6 | `    pulse.play(pulse.Constant(100, 0.5), d0)` | Deprecation -> `pulse.Constant` deprecated by `SymbolicPulse.Constant`; `pulse.play` within `pulse.build` context deprecated, use `ScheduleBlock`. | `qrn_tax_ddbb-b5111ded-f178-4354-a8db-f475bdf64d57`<br>`qrn_tax_ddbb-7bf6a882-1ff2-461f-b97b-9aeaf737333d` | `pulse.play`, `pulse.Constant` | `    pulse_prog += ScheduleBlock(SymbolicPulse.Constant(100, 0.5), d0)` |


```python
from qiskit.pulse.channels import DriveChannel
from qiskit.pulse import build, ScheduleBlock, SymbolicPulse

d0 = DriveChannel(0)

with build() as pulse_prog:
    pulse_prog += ScheduleBlock(SymbolicPulse.Constant(100, 0.5), d0)
```