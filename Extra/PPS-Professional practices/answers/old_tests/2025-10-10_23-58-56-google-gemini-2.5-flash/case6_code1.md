| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 6 | `d2 = pulse.DriveChannel(2)` | Deprecation -> `DriveChannel` moved to `qiskit.transpiler.Target` or `qiskit.providers.backend.BackendV2` | internal | pulse.DriveChannel | `d2 = backend.system_schedule.channels[2]` |
| 9 | `pulse.u2(0, math.pi, 0)` | Deprecation -> `u2` instruction is deprecated | internal | pulse.u2 | `pulse.rz(0, 0)`<br>`pulse.sx(0)`<br>`pulse.rz(math.pi, 0)` |
| 10 | `pulse.cx(0, 1)` | Deprecation -> `cx` instruction is deprecated | internal | pulse.cx | `pulse.s(0)`<br>`pulse.s(1)`<br>`pulse.ecr(0, 1)`<br>`pulse.s(0)`<br>`pulse.s(1)` |
| 14 | `with pulse.align_right():` | Deprecation -> `align_right` is deprecated | internal | pulse.align_right | `with pulse.align_seq.right():` |
| 15 | `pulse.call(bell_prep)` | Deprecation -> `call` is deprecated | internal | pulse.call | `pulse.add(bell_prep)` |
| 16 | `pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)` | Deprecation -> `pulse.Constant` is deprecated | internal | pulse.Constant | `pulse.play(pulse.Constant(bell_prep.duration, 0.02, d2), d2)` |
| 17 | `pulse.barrier(0, 1, 2)` | Deprecation -> `barrier` is deprecated | internal | pulse.barrier | `pulse.add_barrier(0, 1, 2)` |
| 18 | `registers = pulse.measure_all()` | Deprecation -> `measure_all` is deprecated | internal | pulse.measure_all | `registers = pulse.add_measure_all()` |
| 20 | `decoupled_bell_prep_and_measure.draw()` | Deprecation -> `draw` is deprecated | internal | QuantumCircuit.draw | `decoupled_bell_prep_and_measure.draw()` |