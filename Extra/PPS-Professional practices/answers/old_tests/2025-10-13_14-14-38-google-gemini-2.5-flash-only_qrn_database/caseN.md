| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `from qiskit.providers.fake_provider import FakeManila` | Deprecation -> `FakeManila` is deprecated. | * | 3e95df91-e1c5-4340-8243-daa95d502170 | qiskit.providers.fake_provider.FakeManila | `from qiskit_ibm_runtime.fake_provider import FakeManila` |
| 23 | `pulse.play(pulse.Gaussian(160, 0.3, 40), pulse.DriveChannel(0))` | Deprecation -> `pulse.Gaussian` is deprecated. | * | 4a85ead9-680f-49b5-b1dc-982401b98f61 | pulse.Gaussian | `pulse.play(pulse.library.Gaussian(160, 0.3, 40), pulse.DriveChannel(0))` |
| 26 | `pulse.play(pulse.Gaussian(320, 0.4, 80), pulse.DriveChannel(0))` | Deprecation -> `pulse.Gaussian` is deprecated. | * | 4a85ead9-680f-49b5-b1dc-982401b98f61 | pulse.Gaussian | `pulse.play(pulse.library.Gaussian(320, 0.4, 80), pulse.DriveChannel(0))` |
| 27 | `pulse.play(pulse.Gaussian(320, 0.2, 80), pulse.DriveChannel(1))` | Deprecation -> `pulse.Gaussian` is deprecated. | * | 4a85ead9-680f-49b5-b1dc-982401b98f61 | pulse.Gaussian | `pulse.play(pulse.library.Gaussian(320, 0.2, 80), pulse.DriveChannel(1))` |
| 30 | `backend.defaults().instruction_schedule_map.add('h', (0,), hadamard_pulse)` | Deprecation -> Injecting circuit gate operations into the pulse builder context is now deprecated. | * | 7e251264-8a81-4e8b-b4b9-c12c40636818 | backend.defaults().instruction_schedule_map.add | `qc.add_calibration('h', (0,), hadamard_pulse)` |
| 31 | `backend.defaults().instruction_schedule_map.add('cx', (0, 1), cnot_pulse)` | Deprecation -> Injecting circuit gate operations into the pulse builder context is now deprecated. | * | 7e251264-8a81-4e8b-b4b9-c12c40636818 | backend.defaults().instruction_schedule_map.add | `qc.add_calibration('cx', (0, 1), cnot_pulse)` |
| 34 | `transpiled_qc = transpile(qc, backend, optimization_level=3)` | Deprecation -> Running pulse jobs on backends from `qiskit.providers.fake_provider` is deprecated. | * | 3e95df91-e1c5-4340-8243-daa95d502170 | transpile | `transpiled_qc = transpile(qc, simulator, optimization_level=3)` |
| 37 | `simulator = AerSimulator.from_backend(backend)` | Deprecation -> Running pulse jobs on backends from `qiskit.providers.fake_provider` is deprecated. | * | 3e95df91-e1c5-4340-8243-daa95d502170 | AerSimulator.from_backend | `simulator = AerSimulator()` |


```python
from qiskit import QuantumCircuit, transpile
from qiskit.visualization import plot_histogram
from qiskit_aer import AerSimulator
from qiskit_ibm_runtime.fake_provider import FakeManila
from qiskit import pulse
from qiskit.pulse import Schedule, DriveChannel
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
with pulse.build(backend, name='custom_hadamard') as hadamard_pulse:
    # Pulso personalizado para Hadamard (diferente al estándar)
    pulse.play(pulse.library.Gaussian(160, 0.3, 40), pulse.DriveChannel(0))  # Amplitud diferente

with pulse.build(backend, name='custom_cnot') as cnot_pulse:
    # Pulso personalizado para CNOT
    pulse.play(pulse.library.Gaussian(320, 0.4, 80), pulse.DriveChannel(0))
    pulse.play(pulse.library.Gaussian(320, 0.2, 80), pulse.DriveChannel(1))

# Simulación del circuito

# Agregar los pulsos personalizados al backend para que se usen en lugar de los estándar
qc.add_calibration('h', (0,), hadamard_pulse)
qc.add_calibration('cx', (0, 1), cnot_pulse)

# Transpilar el circuito con optimización a nivel de pulsos
simulator = AerSimulator()
transpiled_qc = transpile(qc, simulator, optimization_level=3)

# Simular con AerSimulator usando el backend con pulsos personalizados
job = simulator.run(transpiled_qc, shots=1024)

# Obtener resultados
result = job.result()
counts = result.get_counts()

# Visualizar resultados
print("Conteos con pulsos personalizados:", counts)
plot_histogram(counts, title="Resultados con pulsos personalizados")
plt.show()
```