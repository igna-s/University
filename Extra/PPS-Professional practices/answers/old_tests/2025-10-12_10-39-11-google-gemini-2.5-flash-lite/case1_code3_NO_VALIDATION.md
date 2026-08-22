| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :---: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> `execute` is deprecated and removed in Qiskit 1.0. | * | Internal Knowledge | execute | `from qiskit import QuantumCircuit, Aer, qasm` |
| 4 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> `qasm` is deprecated and removed in Qiskit 1.0. | * | Internal Knowledge | qasm | `from qiskit import QuantumCircuit, Aer` |
| 11 | `job = getJob(qc, backend, 1000)` | `execute` is removed. Use `backend.run()` instead. | 8 | 79a044a5-61b0-452c-ab14-33d17081d970 | execute | `job = backend.run(qc, number_of_shots=1000)` |
| 12 | `result = job.result().get_counts(qc)` | `job.result()` is deprecated and removed. Call `result()` directly on the job object. | 24 | f27c7582-4211-497b-a32d-01b58378e0d7 | job.result() | `result = job.result.get_counts(qc)` |


```python
    import os
    from datetime import datetime
    from qiskit import QuantumCircuit, Aer
    import matplotlib.pyplot as plt
    from utils import getJob

    qc = QuantumCircuit(2, 2)
    qc.h(0)
    qc.cx(0, 1)
    qc.measure(0, 0)
    qc.measure(1, 1)

    backend = Aer.get_backend('aer_simulator')
    job = backend.run(qc, number_of_shots=1000)
    result = job.result.get_counts(qc)
    plt.show()
```