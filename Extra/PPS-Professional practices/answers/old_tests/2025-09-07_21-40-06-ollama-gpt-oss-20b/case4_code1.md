| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 3 | `from qiskit.tools.events import TextProgressBar` | * | Deprecation -> TextProgressBar import deprecated | TextProgressBar | `from qiskit.utils.job_monitoring import job_monitor` |
| 12 | `TextProgressBar().update(job)` | * | Deprecation -> TextProgressBar usage deprecated | TextProgressBar | `job_monitor(job)` |