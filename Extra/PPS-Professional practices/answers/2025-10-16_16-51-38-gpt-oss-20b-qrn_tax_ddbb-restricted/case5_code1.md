| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------- | :------- | :---------- |
| 4 | `from qiskit import extensions as ext` | Deprecation -> qiskit.extensions module is deprecated | d7e68a47-8d01-4433-a93c-1aebfca5d9f4 | qiskit.extensions | Replace with `from qiskit.circuit.library import *` and remove usage of `ext`. |
| 19 | `qc.prepare_state(psi, [qr[0]])` | Deprecation -> QuantumCircuit.prepare_state() is deprecated |  | QuantumCircuit.prepare_state | Replace with `qc.initialize(psi, qr[0])`. |
| 21 | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> qiskit.extensions module is deprecated | d7e68a47-8d01-4433-a93c-1aebfca5d9f4 | qiskit.extensions.Barrier | Replace with `qc.barrier([qr[0], qr[1], qr[2]])`. |