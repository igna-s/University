| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `from qiskit.providers.fake_provider import FakeManila` | Deprecation -> `qiskit.providers.fake_provider` has moved to `qiskit.test.mock`. | 2 | 22d99d34-b2b8-4081-91a6-f138c23789ce | qiskit.providers.fake_provider | `from qiskit.test.mock import FakeManila` |
| 5 | `from qiskit import pulse` | Update -> The pulse builder interface has moved from `qiskit.pulse` to `qiskit.pulse.builder`. | 3 | 5a484c2f-8700-47e9-a311-667793d56a29 | qiskit.pulse | `from qiskit.pulse import Schedule, DriveChannel` <br> `from qiskit.pulse import library` <br> `from qiskit.pulse.builder import build, play` |
| 5 | `from qiskit import pulse` | Update -> The pulse builder interface has moved from `qiskit.pulse` to `qiskit.pulse.builder`. | 4 | 5a484c2f-8700-47e9-a311-667793d56a29 | pulse.build | `from qiskit.pulse.builder import build` |
| 5 | `from qiskit import pulse` | Update -> The pulse builder interface has moved from `qiskit.pulse` to `qiskit.pulse.builder`. | 5 | 5a484c2f-8700-47e9-a311-667793d56a29 | pulse.play | `from qiskit.pulse.builder import play` |
| 5 | `from qiskit import pulse` | Update -> Pulse library functions like `Gaussian` are now found in `qiskit.pulse.library`. | * | Internal Knowledge | pulse.Gaussian | `from qiskit.pulse.library import Gaussian` |
| 23 | `with pulse.build(backend, name='custom_hadamard') as hadamard_pulse:` | Update -> The pulse builder interface has moved from `qiskit.pulse` to `qiskit.pulse.builder`. | 4 | 5a484c2f-8700-47e9-a311-667793d56a29 | pulse.build | `with build(backend, name='custom_hadamard') as hadamard_pulse:` |
| 25 | `pulse.play(pulse.Gaussian(160, 0.3, 40), pulse.DriveChannel(0))` | Update -> The pulse builder interface has moved from `qiskit.pulse` to `qiskit.pulse.builder`. | 5 | 5a484c2f-8700-47e9-a311-667793d56a29 | pulse.play | `play(Gaussian(160, 0.3, 40), DriveChannel(0))` |
| 25 | `pulse.play(pulse.Gaussian(160, 0.3, 40), pulse.DriveChannel(0))` | Update -> Pulse library functions like `Gaussian` are now found in `qiskit.pulse.library`. | * | Internal Knowledge | pulse.Gaussian | `play(Gaussian(160, 0.3, 40), DriveChannel(0))` |
| 27 | `with pulse.build(backend, name='custom_cnot') as cnot_pulse:` | Update -> The pulse builder interface has moved from `qiskit.pulse` to `qiskit.pulse.builder`. | 4 | 5a484c2f-8700-47e9-a311-667793d56a29 | pulse.build | `with build(backend, name='custom_cnot') as cnot_pulse:` |
| 29 | `pulse.play(pulse.Gaussian(320, 0.4, 80), pulse.DriveChannel(0))` | Update -> The pulse builder interface has moved from `qiskit.pulse` to `qiskit.pulse.builder`. | 5 | 5a484c2f-8700-47e9-a311-667793d56a29 | pulse.play | `play(Gaussian(320, 0.4, 80), DriveChannel(0))` |
| 29 | `pulse.play(pulse.Gaussian(320, 0.4, 80), pulse.DriveChannel(0))` | Update -> Pulse library functions like `Gaussian` are now found in `qiskit.pulse.library`. | * | Internal Knowledge | pulse.Gaussian | `play(Gaussian(320, 0.4, 80), DriveChannel(0))` |
| 30 | `pulse.play(pulse.Gaussian(320, 0.2, 80), pulse.DriveChannel(1))` | Update -> The pulse builder interface has moved from `qiskit.pulse` to `qiskit.pulse.builder`. | 5 | 5a484c2f-8700-47e9-a311-667793d56a29 | pulse.play | `play(Gaussian(320, 0.2, 80), DriveChannel(1))` |
| 30 | `pulse.play(pulse.Gaussian(320, 0.2, 80), pulse.DriveChannel(1))` | Update -> Pulse library functions like `Gaussian` are now found in `qiskit.pulse.library`. | * | Internal Knowledge | pulse.Gaussian | `play(Gaussian(320, 0.2, 80), DriveChannel(1))` |
| 33 | `backend.defaults().instruction_schedule_map.add('h', (0,), hadamard_pulse)` | Deprecation -> `instruction_schedule_map` is deprecated. Use `backend.target.add_instruction` instead. | 13 | c5dd597c-9b48-4223-8c46-9d0d343c5b81 | instruction_schedule_map | `backend.target.add_instruction('h', (0,), hadamard_pulse)` |
| 34 | `backend.defaults().instruction_schedule_map.add('cx', (0, 1), cnot_pulse)` | Deprecation -> `instruction_schedule_map` is deprecated. Use `backend.target.add_instruction` instead. | 13 | c5dd597c-9b48-4223-8c46-9d0d343c5b81 | instruction_schedule_map | `backend.target.add_instruction('cx', (0, 1), cnot_pulse)` |


```python
from qiskit import QuantumCircuit, transpile
from qiskit.visualization import plot_histogram
from qiskit_aer import AerSimulator
from qiskit.test.mock import FakeManila
from qiskit.pulse import Schedule, DriveChannel
from qiskit.pulse import library
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

schedule = Schedule()
drive_chan = DriveChannel(0)

# Definir pulsos personalizados que reemplazarán las compuertas estándar
with build(backend, name='custom_hadamard') as hadamard_pulse:
    # Pulso personalizado para Hadamard (diferente al estándar)
    play(library.Gaussian(160, 0.3, 40), DriveChannel(0))  # Amplitud diferente

with build(backend, name='custom_cnot') as cnot_pulse:
    # Pulso personalizado para CNOT
    play(library.Gaussian(320, 0.4, 80), DriveChannel(0))
    play(library.Gaussian(320, 0.2, 80), DriveChannel(1))

# Simulación del circuito

# Agregar los pulsos personalizados al backend para que se usen en lugar de los estándar
backend.target.add_instruction('h', (0,), hadamard_pulse)
backend.target.add_instruction('cx', (0, 1), cnot_pulse)

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