| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 4 | `from qiskit.providers.fake_provider import FakeManila` | Deprecation -> FakeManila is deprecated | qrn_notax_ddbb-aa6cda1f-af91-4940-8d4c-1897f9a56701 | qiskit.providers.fake_provider | `from qiskit_ibm_runtime.fake_provider import FakeProvider` |
| 37 | `backend = FakeManila()` | Deprecation -> FakeManila is deprecated | qrn_notax_ddbb-aa6cda1f-af91-4940-8d4c-1897f9a56701 | qiskit.providers.fake_provider | `backend = FakeProvider().get_backend("fake_dublin")` |
| 57 | `simulator = AerSimulator.from_backend(backend)` | Updated -> AerSimulator.from_backend() will no longer receive updates | IK | qiskit | `simulator = AerSimulator(backend)` |
| 75 | `plot_histogram(counts, title="Resultados con pulsos personalizados")` | Deprecation -> plot_histogram() with distribution dictionary is deprecated | qrn_notax_ddbb-4194776d-c578-4b79-8dc6-9c5e286bc808 | qiskit.visualization | `plot_distribution(counts, title="Resultados con pulsos personalizados")` |

```python  
from qiskit import QuantumCircuit, transpile
from qiskit.visualization import plot_distribution
from qiskit_aer import AerSimulator
from qiskit_ibm_runtime.fake_provider import FakeProvider
from qiskit import pulse
from qiskit.pulse import Schedule, DriveChannel
import numpy as np
import matplotlib.pyplot as plt

backend = FakeProvider().get_backend("fake_dublin")

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

simulator = AerSimulator(backend)
job = simulator.run(transpiled_qc, shots=1024)

result = job.result()
counts = result.get_counts()

print("Conteos con pulsos personalizados:", counts)
plot_distribution(counts, title="Resultados con pulsos personalizados")
plt.show()
```