| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | from qiskit.providers.fake_provider import FakeManila | Update -> Fake backends moved to qiskit.providers.fake_backend | qrn_tax_ddbb--53248bfa-121c-4d1f-a9c4-06d41ce2be93 | qiskit.providers.fake_provider | from qiskit.providers.fake_backend import FakeManila |
| 6 | from qiskit import pulse | Deprecation -> High-level import of pulse deprecated | qrn_tax_ddbb--64c46e59-d84e-42da-ad24-2527d7ec1b85 | qiskit.pulse | from qiskit import pulse_v1 as pulse |
| 7 | from qiskit.pulse import Schedule, DriveChannel | Deprecation -> Schedule and DriveChannel moved to qiskit.pulse_v1 | qrn_tax_ddbb--64c46e59-d84e-42da-ad24-2527d7ec1b85 | qiskit.pulse | from qiskit.pulse_v1 import Schedule, DriveChannel |

```python
from qiskit import QuantumCircuit, transpile
from qiskit.visualization import plot_histogram
from qiskit_aer import AerSimulator
from qiskit.providers.fake_backend import FakeManila
from qiskit import pulse_v1 as pulse
from qiskit.pulse_v1 import Schedule, DriveChannel
import numpy as np
import matplotlib.pyplot as plt

backend = FakeManila()

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.rz(np.pi/4, 0)
qc.measure([0, 1], [0, 1])

schedule = Schedule()
drive_chan = DriveChannel(0)

with pulse.build(backend, name='custom_hadamard') as hadamard_pulse:
    pulse.play(pulse.Gaussian(160, 0.3, 40), pulse.DriveChannel(0))

with pulse.build(backend, name='custom_cnot') as cnot_pulse:
    pulse.play(pulse.Gaussian(320, 0.4, 80), pulse.DriveChannel(0))
    pulse.play(pulse.Gaussian(320, 0.2, 80), pulse.DriveChannel(1))

backend.defaults().instruction_schedule_map.add('h', (0,), hadamard_pulse)
backend.defaults().instruction_schedule_map.add('cx', (0, 1), cnot_pulse)

transpiled_qc = transpile(qc, backend, optimization_level=3)

simulator = AerSimulator.from_backend(backend)
job = simulator.run(transpiled_qc, shots=1024)

result = job.result()
counts = result.get_counts()

print("Conteos con pulsos personalizados:", counts)
plot_histogram(counts, title="Resultados con pulsos personalizados")
plt.show()
```