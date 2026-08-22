from qiskit import QuantumCircuit, transpile
from qiskit.visualization import plot_histogram
from qiskit_aer import AerSimulator
from qiskit.providers.fake_provider import FakeManila
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
plt.show()