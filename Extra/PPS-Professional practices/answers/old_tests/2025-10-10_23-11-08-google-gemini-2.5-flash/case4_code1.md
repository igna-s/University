| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.providers.aer import AerSimulator` | Migration -> The qiskit.providers.aer module has been moved to qiskit_aer. | internal | qiskit.providers.aer | `from qiskit_aer import AerSimulator` |
| 3 | `from qiskit.utils import algorithm_globals` | Deprecation -> The qiskit.utils.algorithm_globals module is deprecated and has been removed. | internal | qiskit.utils.algorithm_globals | (remove line) |
| 6 | `algorithm_globals.random_seed = 42` | Deprecation -> algorithm_globals.random_seed has been removed. Use numpy.random.default_rng for general seeding or seed_simulator/seed_transpiler for specific Qiskit components. | internal | algorithm_globals.random_seed | `seed = 42` |


```python
from qiskit import QuantumCircuit, transpile
from qiskit_aer import AerSimulator
import numpy as np

seed = 42

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

simulator = AerSimulator()
compiled_circuit = transpile(qc, simulator)

job = simulator.run(compiled_circuit, shots=1024, seed_simulator=seed)
result = job.result()
counts = result.get_counts(compiled_circuit)
print(counts)
```