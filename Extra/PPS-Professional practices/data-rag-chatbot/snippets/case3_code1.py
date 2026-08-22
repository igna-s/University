from qiskit.qasm import Qasm
from utils import getJob, getBackend

qasm_file="C:/qasm_file.qasm"
circuit2 = Qasm(filename=qasm_file)
program2 = circuit2.parse()
qc2 = program2.get_circuit()

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)