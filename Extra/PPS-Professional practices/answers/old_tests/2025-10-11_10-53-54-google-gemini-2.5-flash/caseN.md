| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `from qiskit.providers.fake_provider import FakeManila` | Deprecation -> FakeManila is pending deprecation and will be replaced by GenericBackendV2 for new code. | * | cc691dc8-fc12-43ef-bc84-57c209f58c87 | FakeManila | `from qiskit.providers.fake_provider import GenericBackendV2` |
| 8 | `import matplotlib.pyplot as plt` | Deprecation -> `matplotlib` is no longer a core dependency of Qiskit. | * | internal | matplotlib.pyplot | |
| 11 | `backend = FakeManila()` | Deprecation -> FakeManila is pending deprecation and will be replaced by GenericBackendV2 for new code. | * | cc691dc8-fc12-43ef-bc84-57c209f58c87 | FakeManila | `backend = GenericBackendV2(num_qubits=backend.num_qubits, calibrate_instructions=True)` |


```python
from qiskit import QuantumCircuit, transpile
from qiskit.visualization import plot_histogram
from qiskit_aer import AerSimulator
from qiskit.providers.fake_provider import GenericBackendV2
from qiskit import pulse
from qiskit.pulse import Schedule, DriveChannel
import numpy as np


# Usar GenericBackendV2 como backend (simula un dispositivo real con calibraciones)
backend = GenericBackendV2(num_qubits=5, calibrate_instructions=True) # FakeManila has 5 qubits

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
    pulse.play(pulse.Gaussian(160, 0.3, 40), pulse.DriveChannel(0))  # Amplitud diferente

with pulse.build(backend, name='custom_cnot') as cnot_pulse:
    # Pulso personalizado para CNOT
    pulse.play(pulse.Gaussian(320, 0.4, 80), pulse.DriveChannel(0))
    pulse.play(pulse.Gaussian(320, 0.2, 80), pulse.DriveChannel(1))

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
# Matplotlib is no longer a core dependency, so we omit plt.show()
```