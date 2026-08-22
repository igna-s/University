import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit.qasm import Qasm
from qiskit.algorithms import VQE
from qiskit import qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")