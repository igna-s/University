```markdown
| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------- | :------- | :---------- |
| 1 | `    from qiskit import Aer` | Deprecation -> `from qiskit import Aer` is deprecated in Qiskit 1.0.0 | IK | Aer import | `from qiskit.providers.aer import AerSimulator` |
| 12 | `backend = Aer.get_backend('qasm_simulator')` | Structural change -> Aer simulators replaced by `AerSimulator()` | IK | Aer.get_backend | `backend = AerSimulator()` |
```

```python
from qiskit.providers.aer import AerSimulator
from qiskit.utils import QuantumInstance, algorithm_globals
from qiskit.circuit.library import TwoLocal
from qiskit.opflow import Z, I, X
import numpy as np

hamiltonian = (Z ^ I) + (X ^ X)
num_qubits = 2
ansatz = TwoLocal(num_qubits, rotation_blocks='ry', entanglement_blocks='cz', reps=1)
initial_point = algorithm_globals.random.random(ansatz.num_parameters)

backend = AerSimulator()
quantum_instance = QuantumInstance(
    backend,
    shots=1024,
    seed_simulator=algorithm_globals.random_seed,
    seed_transpiler=algorithm_globals.random_seed
)
```