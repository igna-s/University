| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------:| :------- | :---------- |
| 3 | `    from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> Importing from qiskit.providers.aer is deprecated | 548acfe8-db26-45b7-ab5c-c637c63ee4b0 | Aer | `    from qiskit import QuantumCircuit`<br>`    from qiskit_aer import Aer` |
| 13 | `    backend = Aer.get_backend('aer_simulator')` | Deprecation -> Importing from qiskit.providers.aer is deprecated | 548acfe8-db26-45b7-ab5c-c637c63ee4b0 | Aer.get_backend |  |

```python
    import os
    from datetime import datetime
    from qiskit import QuantumCircuit
    from qiskit_aer import Aer
    import matplotlib.pyplot as plt
    from utils import getJob

    qc = QuantumCircuit(2, 2)
    qc.h(0)
    qc.cx(0, 1)
    qc.measure(0, 0)
    qc.measure(1, 1)

    backend = Aer.get_backend('aer_simulator')
    job = getJob(qc, backend, 1000)
    result = job.result().get_counts(qc)
    plt.show()
```