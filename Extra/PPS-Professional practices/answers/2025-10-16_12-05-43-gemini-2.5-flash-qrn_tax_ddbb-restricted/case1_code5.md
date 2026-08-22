| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> Use of the `qiskit.Aer` object is deprecated. | qrn_tax_ddbb-0771d384-706f-40c0-818d-20a4b728e9a2 | qiskit.Aer | `from qiskit_aer import Aer` |
| 11 | `from qiskit import execute` | Deprecation -> The `execute()` function is deprecated. | IK | qiskit.execute | |
| 12 | `job = execute(qc, backend, shots=1000)` | Changed -> Job execution method. | qrn_tax_ddbb-039bc9ef-72bf-4376-9047-3e418906d0e0 | execute | `job = backend.run(qc, shots=1000)` |
| 14 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> The `qiskit.tools.visualization` module is deprecated. | qrn_tax_ddbb-f4566a3d-6928-46a7-a2cb-31cd69741944 | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 15 | `plot_histogram(job.result().get_counts(qc))` | Deprecation -> Passing a distribution dictionary to `plot_histogram()` is deprecated. | qrn_tax_ddbb-8340cefb-6745-41c9-94f1-e220d76e7ab5 | plot_histogram() | `plot_distribution(job.result().get_counts(qc))` |
| 17 | `from qiskit.algorithms import VQE` | Deprecation -> The `qiskit.algorithms` module is deprecated. | IK | qiskit.algorithms | |
| 19 | `from qiskit import SPSA` | Deprecation -> The `qiskit.SPSA` class is deprecated. | IK | qiskit.SPSA | |
| 20 | `vqe = VQE(TwoLocal(rotation_blocks="ry", entanglement_blocks="cz"), SPSA())` | Deprecation -> Usage of deprecated `VQE` and `SPSA` classes. | IK | VQE, SPSA | |