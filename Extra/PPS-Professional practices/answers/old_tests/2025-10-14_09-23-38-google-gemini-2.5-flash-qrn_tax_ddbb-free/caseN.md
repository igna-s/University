| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.providers.fake_provider import FakeManila` | Deprecation -> The `qiskit.providers.fake_provider` module has been deprecated. | Internal Knowledge | `qiskit.providers.fake_provider` | `from qiskit.utils.optionals import HAS_TWEEDLEDUM` |
| 5 | `from qiskit import pulse` | Deprecation -> The `qiskit.pulse` module has been deprecated. | Internal Knowledge | `qiskit.pulse` | `import qiskit.pulse as qp` |
| 6 | `from qiskit.pulse import Schedule, DriveChannel` | Deprecation -> The `qiskit.pulse` module has been deprecated. | Internal Knowledge | `qiskit.pulse` | `from qiskit.pulse import Schedule, DriveChannel` |
| 19 | `with pulse.build(backend, name='custom_hadamard') as hadamard_pulse:` | Deprecation -> `pulse.build` has moved to `qiskit.build`. | Internal Knowledge | `pulse.build` | `with qp.build(backend, name='custom_hadamard') as hadamard_pulse:` |
| 21 | `pulse.play(pulse.Gaussian(160, 0.3, 40), pulse.DriveChannel(0))` | Deprecation -> `pulse.play` and `pulse.Gaussian` have moved to `qiskit.play` and `qiskit.Gaussian` respectively. | Internal Knowledge | `pulse.play`, `pulse.Gaussian`, `pulse.DriveChannel` | `qp.play(qp.Gaussian(160, 0.3, 40), qp.DriveChannel(0))` |
| 23 | `with pulse.build(backend, name='custom_cnot') as cnot_pulse:` | Deprecation -> `pulse.build` has moved to `qiskit.build`. | Internal Knowledge | `pulse.build` | `with qp.build(backend, name='custom_cnot') as cnot_pulse:` |
| 25 | `pulse.play(pulse.Gaussian(320, 0.4, 80), pulse.DriveChannel(0))` | Deprecation -> `pulse.play` and `pulse.Gaussian` have moved to `qiskit.play` and `qiskit.Gaussian` respectively. | Internal Knowledge | `pulse.play`, `pulse.Gaussian`, `pulse.DriveChannel` | `qp.play(qp.Gaussian(320, 0.4, 80), qp.DriveChannel(0))` |
| 26 | `pulse.play(pulse.Gaussian(320, 0.2, 80), pulse.DriveChannel(1))` | Deprecation -> `pulse.play` and `pulse.Gaussian` have moved to `qiskit.play` and `qiskit.Gaussian` respectively. | Internal Knowledge | `pulse.play`, `pulse.Gaussian`, `pulse.DriveChannel` | `qp.play(qp.Gaussian(320, 0.2, 80), qp.DriveChannel(1))` |


```python
from qiskit import QuantumCircuit, transpile
from qiskit.visualization import plot_histogram
from qiskit_aer import AerSimulator
from qiskit.utils.optionals import HAS_TWEEDLEDUM
import qiskit.pulse as qp
from qiskit.pulse import Schedule, DriveChannel
import numpy as np
import matplotlib.pyplot as plt

# Usar FakeManilla como backend (simula un dispositivo real con calibraciones)
backend = HAS_TWEEDLEDUM()

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
with qp.build(backend, name='custom_hadamard') as hadamard_pulse:
    # Pulso personalizado para Hadamard (diferente al estándar)
    qp.play(qp.Gaussian(160, 0.3, 40), qp.DriveChannel(0))  # Amplitud diferente

with qp.build(backend, name='custom_cnot') as cnot_pulse:
    # Pulso personalizado para CNOT
    qp.play(qp.Gaussian(320, 0.4, 80), qp.DriveChannel(0))
    qp.play(qp.Gaussian(320, 0.2, 80), qp.DriveChannel(1))

# Simulación del circuito

# Agregar los pulsos personalizados al backend para que se usen en lugar de los estándar
backend.defaults().instruction_schedule_map.add('h', (0,), hadamard_pulse)
backend.defaults().instruction_schedule_map.add('cx', (0, 1), cnot_pulse)

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