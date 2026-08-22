| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> plot_histogram function deprecated | IK | qiskit.tools.visualization.plot_histogram | `from qiskit.visualization import plot_histogram` |
| 4 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> job_monitor function deprecated | IK | qiskit.tools.monitor.job_monitor | `from qiskit.providers.job import job_monitor` |