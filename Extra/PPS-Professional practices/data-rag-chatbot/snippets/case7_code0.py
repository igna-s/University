from mylib import getJob, getCount
from qiskit.test.mock import FakeVigo
from qiskit.test.reference_circuits import ReferenceCircuits

qc = ReferenceCircuits.bell()
backend = FakeVigo()

job = getJob(qc, backend)
counts = getCount(job)

print("Resultados del circuito Bell:")
print(counts)