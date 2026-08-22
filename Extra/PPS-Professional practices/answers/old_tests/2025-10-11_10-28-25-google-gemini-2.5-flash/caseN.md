| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.visualization import plot_histogram` | Deprecation -> plot_histogram() for certain data types | 3 | 758465a3-6788-4039-b06e-17b74fae37e6 | plot_histogram() | `from qiskit.visualization import plot_distribution` |
| 3 | `from qiskit.providers.fake_provider import FakeManila` | Deprecation -> The qiskit.providers.fake_provider module has been migrated to the qiskit-ibm-runtime Python package. | 25 | bc39cc74-3382-4b55-bc9c-c44558547f03 | qiskit.providers.fake_provider | `from qiskit_ibm_runtime.fake_provider import FakeManila` |
| 11 | `backend = FakeManila()` | Deprecation -> Running pulse jobs on backends from qiskit.providers.fake_provider is deprecated, and all support will be removed in Qiskit 1.0. | * | 1f5a35a2-9fb1-431b-8aec-35c0fe26e1bf | FakeManila | `backend = GenericBackendV2(num_qubits=2, calibrate_single_qubit_gates=True)` |
| 23 | `with pulse.build(backend, name='custom_hadamard') as hadamard_pulse:` | Deprecation -> Deprecation of injecting circuit gate operations into pulse builder context | 23 | 391e32f3-4a73-4829-92b6-91fecd270deb | pulse.build | `with pulse.build(backend=backend, name='custom_hadamard') as hadamard_pulse:` |
| 27 | `with pulse.build(backend, name='custom_cnot') as cnot_pulse:` | Deprecation -> Deprecation of injecting circuit gate operations into pulse builder context | 23 | 391e32f3-4a73-4829-92b6-91fecd270deb | pulse.build | `with pulse.build(backend=backend, name='custom_cnot') as cnot_pulse:` |
| 34 | `backend.defaults().instruction_schedule_map.add('h', (0,), hadamard_pulse)` | Deprecation -> instruction_schedule_map.add is deprecated | * | internal | instruction_schedule_map.add | `backend.add_calibration('h', (0,), hadamard_pulse)` |
| 35 | `backend.defaults().instruction_schedule_map.add('cx', (0, 1), cnot_pulse)` | Deprecation -> instruction_schedule_map.add is deprecated | * | internal | instruction_schedule_map.add | `backend.add_calibration('cx', (0, 1), cnot_pulse)` |
| 41 | `simulator = AerSimulator.from_backend(backend)` | Deprecation -> AerSimulator.from_backend() is deprecated | * | 1f5a35a2-9fb1-431b-8aec-35c0fe26e1bf | AerSimulator.from_backend | `simulator = AerSimulator()` |
| 48 | `plot_histogram(counts, title="Resultados con pulsos personalizados")` | Deprecation -> plot_histogram() for certain data types | 3 | b35c8051-e880-40da-8588-4640cf64f8f5 | plot_histogram() | `plot_distribution(counts, title="Resultados con pulsos personalizados")` |


```python
from qiskit import QuantumCircuit, transpile
from qiskit.visualization import plot_distribution
from qiskit_aer import AerSimulator
from qiskit_ibm_runtime.fake_provider import FakeManila
from qiskit import pulse
from qiskit.pulse import Schedule, DriveChannel
import numpy as np
import matplotlib.pyplot as plt
from qiskit.providers.fake_provider import GenericBackendV2

# Usar FakeManilla como backend (simula un dispositivo real con calibraciones)
backend = GenericBackendV2(num_qubits=2, calibrate_single_qubit_gates=True)

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
with pulse.build(backend=backend, name='custom_hadamard') as hadamard_pulse:
    # Pulso personalizado para Hadamard (diferente al estándar)
    pulse.play(pulse.Gaussian(160, 0.3, 40), pulse.DriveChannel(0))  # Amplitud diferente

with pulse.build(backend=backend, name='custom_cnot') as cnot_pulse:
    # Pulso personalizado para CNOT
    pulse.play(pulse.Gaussian(320, 0.4, 80), pulse.DriveChannel(0))
    pulse.play(pulse.Gaussian(320, 0.2, 80), pulse.DriveChannel(1))

# Simulación del circuito

# Agregar los pulsos personalizados al backend para que se usen en lugar de los estándar
backend.add_calibration('h', (0,), hadamard_pulse)
backend.add_calibration('cx', (0, 1), cnot_pulse)

# Transpilar el circuito con optimización a nivel de pulsos
transpiled_qc = transpile(qc, backend, optimization_level=3)

# Simular con AerSimulator usando el backend con pulsos personalizados
simulator = AerSimulator()
job = simulator.run(transpiled_qc, shots=1024)

# Obtener resultados
result = job.result()
counts = result.get_counts()

# Visualizar resultados
print("Conteos con pulsos personalizados:", counts)
plot_distribution(counts, title="Resultados con pulsos personalizados")
plt.show()
```