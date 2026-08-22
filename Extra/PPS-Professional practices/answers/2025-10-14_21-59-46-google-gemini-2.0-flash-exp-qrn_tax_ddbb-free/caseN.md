| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.providers.fake_provider import FakeManila` | Deprecation -> The qiskit.providers.fake_provider module is deprecated | qrn_tax_ddbb-e98e0e5764e7f11d822a6a499c74ebce | qiskit.providers.fake_provider | `from qiskit.test.mock import FakeManila` |
| 29 | `backend.defaults().instruction_schedule_map.add('h', (0,), hadamard_pulse)` | Deprecation -> The instruction_schedule_map attribute is deprecated | qrn_tax_ddbb-19d541277dd8493f957c84929a5f538b | instruction_schedule_map | `backend.instruction_schedule_map.add('h', (0,), hadamard_pulse)` |
| 30 | `backend.defaults().instruction_schedule_map.add('cx', (0, 1), cnot_pulse)` | Deprecation -> The instruction_schedule_map attribute is deprecated | qrn_tax_ddbb-19d541277dd8493f957c84929a5f538b | instruction_schedule_map | `backend.instruction_schedule_map.add('cx', (0, 1), cnot_pulse)` |

```python
from qiskit import QuantumCircuit, transpile
from qiskit.visualization import plot_histogram
from qiskit_aer import AerSimulator
from qiskit.test.mock import FakeManila
from qiskit import pulse
from qiskit.pulse import Schedule, DriveChannel
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

backend.instruction_schedule_map.add('h', (0,), hadamard_pulse)
backend.instruction_schedule_map.add('cx', (0, 1), cnot_pulse)

transpiled_qc = transpile(qc, backend, optimization_level=3)

simulator = AerSimulator.from_backend(backend)
job = simulator.run(transpiled_qc, shots=1024)

result = job.result()
counts = result.get_counts()

print("Conteos con pulsos personalizados:", counts)
plot_histogram(counts, title="Resultados con pulsos personalizados")
plt.show()
```