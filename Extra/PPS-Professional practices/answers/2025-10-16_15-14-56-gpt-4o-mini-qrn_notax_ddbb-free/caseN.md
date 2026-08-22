| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 5 | `from qiskit import QuantumCircuit, transpile` | Deprecated -> Import from qiskit.providers.aer is deprecated | IK | qiskit | `from qiskit import QuantumCircuit, transpile` | 
| 6 | `from qiskit.visualization import plot_histogram` | Updated -> Use plot_distribution() instead of plot_histogram() for QuasiDistribution or ProbDistribution | IK | qiskit.visualization | `from qiskit.visualization import plot_distribution` | 
| 7 | `from qiskit_aer import AerSimulator` | No change | IK | qiskit_aer | `from qiskit_aer import AerSimulator` | 
| 8 | `from qiskit.providers.fake_provider import FakeManila` | Deprecated -> The module qiskit.providers.fake_provider is migrated to qiskit-ibm-runtime | IK | qiskit.providers.fake_provider | `from qiskit_ibm_runtime.fake_provider import FakeManila` | 
| 9 | `from qiskit import pulse` | No change | IK | qiskit | `from qiskit import pulse` | 
| 10 | `from qiskit.pulse import Schedule, DriveChannel` | No change | IK | qiskit.pulse | `from qiskit.pulse import Schedule, DriveChannel` | 
| 11 | `import numpy as np` | No change | IK | numpy | `import numpy as np` | 
| 12 | `import matplotlib.pyplot as plt` | No change | IK | matplotlib | `import matplotlib.pyplot as plt` | 
| 15 | `backend = FakeManila()` | Updated -> The module qiskit.providers.fake_provider is migrated to qiskit-ibm-runtime | IK | FakeManila | `backend = FakeManila()` | 
| 20 | `qc = QuantumCircuit(2, 2)` | No change | IK | QuantumCircuit | `qc = QuantumCircuit(2, 2)` | 
| 22 | `qc.h(0)` | No change | IK | qc.h | `qc.h(0)` | 
| 23 | `qc.cx(0, 1)` | No change | IK | qc.cx | `qc.cx(0, 1)` | 
| 24 | `qc.rz(np.pi/4, 0)` | No change | IK | qc.rz | `qc.rz(np.pi/4, 0)` | 
| 25 | `qc.measure([0, 1], [0, 1])` | No change | IK | qc.measure | `qc.measure([0, 1], [0, 1])` | 
| 27 | `schedule = Schedule()` | No change | IK | Schedule | `schedule = Schedule()` | 
| 28 | `drive_chan = DriveChannel(0)` | No change | IK | DriveChannel | `drive_chan = DriveChannel(0)` | 
| 31 | `with pulse.build(backend, name='custom_hadamard') as hadamard_pulse:` | No change | IK | pulse.build | `with pulse.build(backend, name='custom_hadamard') as hadamard_pulse:` | 
| 33 | `pulse.play(pulse.Gaussian(160, 0.3, 40), pulse.DriveChannel(0))` | No change | IK | pulse.play | `pulse.play(pulse.Gaussian(160, 0.3, 40), pulse.DriveChannel(0))` | 
| 36 | `with pulse.build(backend, name='custom_cnot') as cnot_pulse:` | No change | IK | pulse.build | `with pulse.build(backend, name='custom_cnot') as cnot_pulse:` | 
| 38 | `pulse.play(pulse.Gaussian(320, 0.4, 80), pulse.DriveChannel(0))` | No change | IK | pulse.play | `pulse.play(pulse.Gaussian(320, 0.4, 80), pulse.DriveChannel(0))` | 
| 39 | `pulse.play(pulse.Gaussian(320, 0.2, 80), pulse.DriveChannel(1))` | No change | IK | pulse.play | `pulse.play(pulse.Gaussian(320, 0.2, 80), pulse.DriveChannel(1))` | 
| 43 | `backend.defaults().instruction_schedule_map.add('h', (0,), hadamard_pulse)` | No change | IK | instruction_schedule_map | `backend.defaults().instruction_schedule_map.add('h', (0,), hadamard_pulse)` | 
| 44 | `backend.defaults().instruction_schedule_map.add('cx', (0, 1), cnot_pulse)` | No change | IK | instruction_schedule_map | `backend.defaults().instruction_schedule_map.add('cx', (0, 1), cnot_pulse)` | 
| 47 | `transpiled_qc = transpile(qc, backend, optimization_level=3)` | No change | IK | transpile | `transpiled_qc = transpile(qc, backend, optimization_level=3)` | 
| 50 | `simulator = AerSimulator.from_backend(backend)` | Updated -> Use AerSimulator directly | IK | AerSimulator | `simulator = AerSimulator(backend)` | 
| 52 | `result = job.result()` | No change | IK | job | `result = job.result()` | 
| 55 | `print("Conteos con pulsos personalizados:", counts)` | No change | IK | print | `print("Conteos con pulsos personalizados:", counts)` | 
| 56 | `plot_histogram(counts, title="Resultados con pulsos personalizados")` | Updated -> Use plot_distribution() instead of plot_histogram() | IK | plot_histogram | `plot_distribution(counts, title="Resultados con pulsos personalizados")` | 
| 57 | `plt.show()` | No change | IK | plt | `plt.show()` | 

```python
from qiskit import QuantumCircuit, transpile
from qiskit.visualization import plot_distribution
from qiskit_aer import AerSimulator
from qiskit_ibm_runtime.fake_provider import FakeManila
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