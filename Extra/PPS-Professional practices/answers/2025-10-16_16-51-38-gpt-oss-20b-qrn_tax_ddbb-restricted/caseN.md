**Lines that need to be updated for Qiskit 1.0**

| Line | Original Code | Scenario | Reference | Artifact | Refactoring |
|------|---------------|----------|-----------|----------|-------------|
| 4 | `from qiskit.providers.fake_provider import FakeManila` | Structural change: `FakeProvider` and all fake‑backend classes have been moved from `qiskit.providers.fake_provider` to `qiskit_ibm_runtime.fake_provider`. | 693b5266-a1ce-476c-87b8-c30e824bd87d | `qiskit.providers.fake_provider.FakeManila` | `from qiskit_ibm_runtime.fake_provider import FakeManila` |
| 28 | `pulse.play(pulse.Gaussian(160, 0.3, 40), pulse.DriveChannel(0))  # Amplitud diferente` | Deprecation of `pulse.play` inside a pulse‑builder context; the recommended replacement is `pulse.call`. | 4f791e8e-887c-47d9-80fa-50227b769092 | `pulse.play` | `pulse.call(pulse.Gaussian(160, 0.3, 40))` |
| 32 | `pulse.play(pulse.Gaussian(320, 0.4, 80), pulse.DriveChannel(0))` | Same deprecation as above. | 4f791e8e-887c-47d9-80fa-50227b769092 | `pulse.play` | `pulse.call(pulse.Gaussian(320, 0.4, 80))` |
| 33 | `pulse.play(pulse.Gaussian(320, 0.2, 80), pulse.DriveChannel(1))` | Same deprecation as above. | 4f791e8e-887c-47d9-80fa-50227b769092 | `pulse.play` | `pulse.call(pulse.Gaussian(320, 0.2, 80))` |

**Other lines** in the code are already compatible with Qiskit 1.0 and do not require changes.