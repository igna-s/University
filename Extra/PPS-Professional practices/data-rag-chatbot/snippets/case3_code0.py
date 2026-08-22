from qiskit import qasm
from utils import getJob, getBackend

qasm_str = """
OPENQASM 2.0;
include "qelib1.inc";
qreg q[2];
creg c[2];
h q[0];
cx q[0], q[1];
measure q -> c;
"""
circuit1 = qasm.Qasm(data=qasm_str)
program1 = circuit1.parse()
qc1 = program1.get_circuit()

simulator = getBackend()
job = getJob(qc1)
result = job.result()
counts = result.get_counts()
print(counts)