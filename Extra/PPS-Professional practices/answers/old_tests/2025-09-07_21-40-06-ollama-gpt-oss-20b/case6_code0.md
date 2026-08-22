| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 3 | `from qiskit.providers import fake_provider` | * | Deprecation -> `qiskit.providers.fake_provider` module deprecated | `qiskit.providers.fake_provider` | `from qiskit_ibm_provider import fake_provider` |
| 12 | `pulse.measure(0)` | * | Deprecation -> `pulse.measure()` function deprecated | `pulse.measure` | `Measure([0])` |