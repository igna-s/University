| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> `qiskit.tools.visualization` module is deprecated | internal | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 4 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> `qiskit.tools.monitor` module is deprecated | internal | qiskit.tools.monitor | `from qiskit.utils.run_circuits import job_monitor` |
| 23 | `counts = job.result().get_counts(qc)` | Deprecation -> `get_counts()` no longer accepts a circuit argument | internal | get_counts | `counts = job.result().get_counts()` |