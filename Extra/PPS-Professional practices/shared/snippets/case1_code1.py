import os
from qiskit import QuantumCircuit 
from qiskit import Aer
from qiskit import qasm
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")