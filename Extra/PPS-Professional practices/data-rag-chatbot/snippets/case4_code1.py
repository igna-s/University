from qiskit import QuantumCircuit
from utils import createBackendAndrunJob
from qiskit.tools.events import TextProgressBar

qc = QuantumCircuit(2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

job = createBackendAndrunJob()

TextProgressBar().update(job)
result = job.result()
counts = result.get_counts()