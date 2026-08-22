| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.providers.fake_provider import *` | Deprecation -> Wildcard import from fake_provider is deprecated | qrn_notax_ddbb-548acfe8-db26-45b7-ab5c-c637c63ee4b0 | qiskit.providers.fake_provider | `from qiskit.providers.fake_provider import FakeOpenPulse2Q` |
| 9 | `pulse.play(pulse.Constant(100, 0.5), d0)` | Deprecation -> Constant pulse is deprecated | qrn_notax_ddbb-508fb6f3-cdfc-4b96-ad81-f550801dbe2f | pulse.Constant | `pulse.play(pulse.ConstantPulse(100, 0.5), d0)` |

    from qiskit import transpile, pulse
    from qiskit.providers.fake_provider import FakeOpenPulse2Q

    backend = FakeOpenPulse2Q()

    d0 = pulse.DriveChannel(0)

    with pulse.build() as pulse_prog:
        pulse.play(pulse.ConstantPulse(100, 0.5), d0)