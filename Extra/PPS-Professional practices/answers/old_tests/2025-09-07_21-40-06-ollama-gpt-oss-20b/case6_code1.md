| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 3 | `from qiskit.providers.fake_provider import FakeOpenPulse3Q` | * | Deprecation -> qiskit.providers.fake_provider module deprecated (optional) | qiskit.providers.fake_provider | `from qiskit.providers.fake_backends import FakeOpenPulse3Q` |
| 9 | `pulse.u2(0, math.pi, 0)` | * | Deprecation -> qiskit.pulse.builder.u2() function deprecated | qiskit.pulse.builder.u2 | `pulse.rz(math.pi, 0)`<br>`pulse.sx(0)`<br>`pulse.rz(math.pi, 0)` |