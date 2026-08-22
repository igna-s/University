| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 5 | `from qiskit import pulse` | Deprecation -> The `qiskit.pulse` module has been reorganized. `build` and `play` functionality moved to `qiskit.pulse.builder`. | 20 | Internal Knowledge | `qiskit.pulse` | |
| 6 | `from qiskit.pulse import Schedule, DriveChannel` | Deprecation -> `Schedule` is deprecated in favor of `ScheduleBlock` for composing schedules. | 16 | Internal Knowledge | `Schedule` | `from qiskit.pulse import ScheduleBlock, DriveChannel, Gaussian` |
| 22 | `schedule = Schedule()` | Deprecation -> `Schedule` is deprecated in favor of `ScheduleBlock` for composing schedules. | 16 | Internal Knowledge | `Schedule` | `schedule = ScheduleBlock()` |
| 26 | `with pulse.build(backend, name='custom_hadamard') as hadamard_pulse:` | Moved -> `pulse.build` functionality moved to `qiskit.pulse.builder.build`. | 20 | Internal Knowledge | `pulse.build` | `with build(backend, name='custom_hadamard') as hadamard_pulse:` |
| 28 | `    pulse.play(pulse.Gaussian(160, 0.3, 40), pulse.DriveChannel(0))` | Moved -> `pulse.play` functionality moved to `qiskit.pulse.builder.play`. `pulse.Gaussian` and `pulse.DriveChannel` should be imported directly. | 20 | Internal Knowledge | `pulse.play`, `pulse.Gaussian`, `pulse.DriveChannel` | `    play(Gaussian(160, 0.3, 40), DriveChannel(0))` |
| 30 | `with pulse.build(backend, name='custom_cnot') as cnot_pulse:` | Moved -> `pulse.build` functionality moved to `qiskit.pulse.builder.build`. | 20 | Internal Knowledge | `pulse.build` | `with build(backend, name='custom_cnot') as cnot_pulse:` |
| 32 | `    pulse.play(pulse.Gaussian(320, 0.4, 80), pulse.DriveChannel(0))` | Moved -> `pulse.play` functionality moved to `qiskit.pulse.builder.play`. `pulse.Gaussian` and `pulse.DriveChannel` should be imported directly. | 20 | Internal Knowledge | `pulse.play`, `pulse.Gaussian`, `pulse.DriveChannel` | `    play(Gaussian(320, 0.4, 80), DriveChannel(0))` |
| 33 | `    pulse.play(pulse.Gaussian(320, 0.2, 80), pulse.DriveChannel(1))` | Moved -> `pulse.play` functionality moved to `qiskit.pulse.builder.play`. `pulse.Gaussian` and `pulse.DriveChannel` should be imported directly. | 20 | Internal Knowledge | `pulse.play`, `pulse.Gaussian`, `pulse.DriveChannel` | `    play(Gaussian(320, 0.2, 80), DriveChannel(1))` |
| 38 | `backend.defaults().instruction_schedule_map.add('h', (0,), hadamard_pulse)` | Changed -> Accessing the instruction schedule map from `backend.defaults()` is deprecated. | 12 | Internal Knowledge | `backend.defaults().instruction_schedule_map` | `backend.instruction_schedule_map.add('h', (0,), hadamard_pulse)` |
| 39 | `backend.defaults().instruction_schedule_map.add('cx', (0, 1), cnot_pulse)` | Changed -> Accessing the instruction schedule map from `backend.defaults()` is deprecated. | 12 | Internal Knowledge | `backend.defaults().instruction_schedule_map` | `backend.instruction_schedule_map.add('cx', (0, 1), cnot_pulse)` |


```python
from qiskit import QuantumCircuit, transpile
from qiskit.visualization import plot_histogram
from qiskit_aer import AerSimulator
from qiskit.providers.fake_provider import FakeManila
from qiskit.pulse import ScheduleBlock, DriveChannel, Gaussian
from qiskit.pulse.builder import build, play
import numpy as np
import matplotlib.pyplot as plt

# Usar FakeManilla como backend (simula un dispositivo real con calibraciones)
backend = FakeManila()

# Crear un circuito cuántico simple
qc = QuantumCircuit(2, 2)

# Aplicar compuertas cuánticas
qc.h(0)
qc.cx(0, 1)
qc.rz(np.pi/4, 0)
qc.measure([0, 1], [0, 1])

schedule = ScheduleBlock()
drive_chan = DriveChannel(0)

# Definir pulsos personalizados que reemplazarán las compuertas estándar
with build(backend, name='custom_hadamard') as hadamard_pulse:
    # Pulso personalizado para Hadamard (diferente al estándar)
    play(Gaussian(160, 0.3, 40), DriveChannel(0))  # Amplitud diferente

with build(backend, name='custom_cnot') as cnot_pulse:
    # Pulso personalizado para CNOT
    play(Gaussian(320, 0.4, 80), DriveChannel(0))
    play(Gaussian(320, 0.2, 80), DriveChannel(1))

# Simulación del circuito

# Agregar los pulsos personalizados al backend para que se usen en lugar de los estándar
backend.instruction_schedule_map.add('h', (0,), hadamard_pulse)
backend.instruction_schedule_map.add('cx', (0, 1), cnot_pulse)

# Transpilar el circuito con optimización a nivel de pulsos
transpiled_qc = transpile(qc, backend, optimization_level=3)

# Simular con AerSimulator usando el backend con pulsos personalizados
simulator = AerSimulator.from_backend(backend)
job = simulator.run(transpiled_qc, shots=1024)

# Obtener resultados
result = job.result()
counts = result.get_counts()

# Visualizar resultados
print("Conteos con pulsos personalizados:", counts)
plot_histogram(counts, title="Resultados con pulsos personalizados")
plt.show()
```