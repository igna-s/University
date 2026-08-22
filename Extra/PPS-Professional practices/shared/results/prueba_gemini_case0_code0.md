| Line | Code | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- |
| 1 | `from qiskit import QuantumCircuit, transpile, assemble, Aer` | Deprecation -> The qiskit.Aer alias in the root qiskit namespace is deprecated. | qiskit.Aer | `from qiskit.providers import aer` |
| 4 | `simulator = Aer.get_backend('qasm_simulator')` | Deprecation -> Use of the `backend_name` argument in `Aer.get_backend` is deprecated. | Aer.get_backend | `simulator = Aer.get_backend('aer_simulator')` |
| 6 | `compiled_circuit = transpile(circuit, simulator)` | Deprecation -> Passing a backend instance to `transpile` is deprecated. | transpile |  |
| 7 | `qobj = assemble(compiled_circuit, shots=1024)` | Deprecation -> The qiskit.assemble function is deprecated. | qiskit.assemble |  |
| 8 | `job = simulator.run(qobj)` | Deprecation -> Passing a qobj to `backend.run` is deprecated. | backend.run |  |