| Line | Code | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- |
| 1 | `from qiskit import QuantumCircuit, execute, Aer` | Deprecation -> The qiskit.Aer alias in the root qiskit namespace is deprecated. | qiskit.Aer | `from qiskit.providers import aer` |
| 1 | `from qiskit import QuantumCircuit, execute, Aer` | Deprecation -> The qiskit.execute alias in the root qiskit namespace is deprecated. | qiskit.execute |  |
| 3 | `simulator = Aer.get_backend('qasm_simulator')` | Deprecation -> Use of the `backend_name` argument in `Aer.get_backend` is deprecated. | Aer.get_backend | `simulator = Aer.get_backend('aer_simulator')` |
| 5 | `job = execute(circuit, simulator, shots=1000)` | Deprecation -> The qiskit.execute function is deprecated. | qiskit.execute |  |