| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 2 | from qiskit.extensions import HGate, XGate, Initialize | Deprecation -> qiskit.extensions gates migrated to qiskit.circuit.library | qrn_tax_ddbb-2ef5f4ab9e1f44ebb2abf3c99a1184b8 | qiskit.extensions.HGate, qiskit.extensions.XGate, qiskit.extensions.Initialize | from qiskit.circuit.library import HGate, XGate, Initialize | 
| 3 | from qiskit.extensions import Barrier | Deprecation -> Barrier should be accessed via qiskit.circuit | qrn_tax_ddbb-5c4f88de7de144628af18c2b00522de9 | qiskit.extensions.Barrier | from qiskit.circuit import Barrier | 
| 4 | from qiskit.extensions import UnitaryGate | Deprecation -> UnitaryGate moved to qiskit.circuit | qrn_tax_ddbb-cab55a74a94743fb9b14b39722ab5e05 | qiskit.extensions.UnitaryGate | from qiskit.circuit import UnitaryGate | 

```python  
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import HGate, XGate, Initialize
from qiskit.circuit import Barrier, UnitaryGate
import numpy as np

qr = QuantumRegister(3)
qc = QuantumCircuit(qr)

qc.append(HGate(), [qr[0]])
qc.append(XGate(), [qr[1]])

custom_matrix = np.array([[0, 1], [1, 0]])
custom_gate = UnitaryGate(custom_matrix, label="Custom")
qc.append(custom_gate, [qr[2]])

psi = [1/np.sqrt(2), 1/np.sqrt(2)]
init_gate = Initialize(psi)
qc.append(init_gate, [qr[0]])

qc.append(Barrier(3), [qr[0], qr[1], qr[2]])
print(qc.draw())
```