| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.providers.fake_provider import FakeManila` | Deprecation -> `qiskit.providers.fake_provider` module moved | Internal Knowledge | `qiskit.providers.fake_provider` | `from qiskit.providers.fake_backends import FakeManila` |
| 22 | `with pulse.build(backend, name='custom_hadamard') as hadamard_pulse:` | Deprecation -> `pulse.build` context manager | Internal Knowledge | `pulse.build` | `hadamard_pulse = pulse.ScheduleBlock(name='custom_hadamard')` |
| 24 | `    pulse.play(pulse.Gaussian(160, 0.3, 40), pulse.DriveChannel(0))` | Update -> `pulse.play` should be `pulse.Play` and appended to `ScheduleBlock` | Internal Knowledge | `pulse.play` | `hadamard_pulse.append(pulse.Play(pulse.Gaussian(160, 0.3, 40), pulse.DriveChannel(0)))` |
| 26 | `with pulse.build(backend, name='custom_cnot') as cnot_pulse:` | Deprecation -> `pulse.build` context manager | Internal Knowledge | `pulse.build` | `cnot_pulse = pulse.ScheduleBlock(name='custom_cnot')` |
| 28 | `    pulse.play(pulse.Gaussian(320, 0.4, 80), pulse.DriveChannel(0))` | Update -> `pulse.play` should be `pulse.Play` and appended to `ScheduleBlock` | Internal Knowledge | `pulse.play` | `cnot_pulse.append(pulse.Play(pulse.Gaussian(320, 0.4, 80), pulse.DriveChannel(0)))` |
| 29 | `    pulse.play(pulse.Gaussian(320, 0.2, 80), pulse.DriveChannel(1))` | Update -> `pulse.play` should be `pulse.Play` and appended to `ScheduleBlock` | Internal Knowledge | `pulse.play` | `cnot_pulse.append(pulse.Play(pulse.Gaussian(320, 0.2, 80), pulse.DriveChannel(1)))` |
| 32 | `backend.defaults().instruction_schedule_map.add('h', (0,), hadamard_pulse)` | Deprecation -> `backend.defaults()` and `instruction_schedule_map.add()` | Internal Knowledge | `backend.defaults().instruction_schedule_map` | `backend.set_instruction_schedule("h", (0,), hadamard_pulse)` |
| 33 | `backend.defaults().instruction_schedule_map.add('cx', (0, 1), cnot_pulse)` | Deprecation -> `backend.defaults()` and `instruction_schedule_map.add()` | Internal Knowledge | `backend.defaults().instruction_schedule_map` | `backend.set_instruction_schedule("cx", (0, 1), cnot_pulse)` |
| 39 | `simulator = AerSimulator.from_backend(backend)` | Deprecation -> `AerSimulator.from_backend()` | Internal Knowledge | `AerSimulator.from_backend` | `simulator = AerSimulator()` |


```python
from qiskit import QuantumCircuit, transpile
from qiskit.visualization import plot_histogram
from qiskit_aer import AerSimulator
from qiskit.providers.fake_backends import FakeManila
from qiskit import pulse
from qiskit.pulse import Schedule, DriveChannel, Play
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

hadamard_pulse = pulse.ScheduleBlock(name='custom_hadamard')
hadamard_pulse.append(pulse.Play(pulse.Gaussian(160, 0.3, 40), pulse.DriveChannel(0)))

cnot_pulse = pulse.ScheduleBlock(name='custom_cnot')
cnot_pulse.append(pulse.Play(pulse.Gaussian(320, 0.4, 80), pulse.DriveChannel(0)))
cnot_pulse.append(pulse.Play(pulse.Gaussian(320, 0.2, 80), pulse.DriveChannel(1)))

backend.set_instruction_schedule("h", (0,), hadamard_pulse)
backend.set_instruction_schedule("cx", (0, 1), cnot_pulse)

transpiled_qc = transpile(qc, backend, optimization_level=3)

simulator = AerSimulator()
job = simulator.run(transpiled_qc, shots=1024)

result = job.result()
counts = result.get_counts()

print("Conteos con pulsos personalizados:", counts)
plot_histogram(counts, title="Resultados con pulsos personalizados")
plt.show()
```