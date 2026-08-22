from qiskit import QuantumCircuit, Aer, execute
from qiskit import qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm()

qasm_qc = qasm.Qasm(data=qasm_str)
program = qasm_qc.parse()
circuit = program.get_circuit()

simulator = Aer.get_backend('qasm_simulator')
job = execute(qasm_qc, simulator, shots=1024)
result = job.result()
counts = result.get_counts(qasm_qc)
print(counts)