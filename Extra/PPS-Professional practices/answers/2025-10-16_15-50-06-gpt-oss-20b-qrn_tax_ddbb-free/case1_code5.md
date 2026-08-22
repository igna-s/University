| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------:| :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> The Aer import from qiskit is deprecated | IK | Aer | `from qiskit.providers.aer import Aer` |
| 11 | `from qiskit import execute` | Deprecation -> The execute import from qiskit is deprecated | IK | execute | `from qiskit.execute import execute` |
| 14 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> plot_histogram import from qiskit.tools.visualization is deprecated | IK | plot_histogram | `from qiskit.visualization import plot_histogram` |
| 19 | `from qiskit import SPSA` | Deprecation -> The SPSA import from qiskit is deprecated | IK | SPSA | `from qiskit.algorithms.optimizers import SPSA` |