| Line | Code                                                                                         | Scenario                                                      | Reference                                           | Artifact                                  | Refactoring                                                                                                      |
| :--: | :------------------------------------------------------------------------------------------ | :----------------------------------------------------------- | :-------------------------------------------------| :----------------------------------------- | :---------------------------------------------------------------------------------------------------------------- |
| 5    | `from qiskit.providers.fake_provider import FakeManila`                                    | Deprecation -> FakeProvider is deprecated                    | qrn_tax_ddbb-6ecf0d75-110b-4dc1-8d77-d73f6b1eadb5 | qiskit.providers.fake_provider            | `from qiskit_ibm_runtime.fake_provider import FakeProvider`                                                      |
| 6    | `backend = FakeManila()`                                                                   | Deprecation -> FakeBackend is deprecated                      | qrn_tax_ddbb-6ecf0d75-110b-4dc1-8d77-d73f6b1eadb5 | FakeManila                                 | `backend = GenericBackendV2(num_qubits=5)`                                                                       |
| 26   | `from qiskit import pulse`                                                                 | Deprecation -> pulse.gaussian() is deprecated                | qrn_tax_ddbb-2c75-437a-8e84-96506e6766aa         | qiskit.pulse                             | `from qiskit.pulse import SymbolicPulse`                                                                          |
| 27   | `pulse.play(pulse.Gaussian(160, 0.3, 40), pulse.DriveChannel(0))`                       | Deprecation -> pulse.Gaussian() is deprecated                | qrn_tax_ddbb-2c75-437a-8e84-96506e6766aa         | pulse.Gaussian                            | `pulse.play(SymbolicPulse(160, 0.3, 40).get_waveform(), DriveChannel(0))`                                      |
| 29   | `result = job.result()`                                                                     | Deprecation -> BasicAer.get_backend() is deprecated           | qrn_tax_ddbb-09db4543-63a6-47dd-9cd7-097a6f9fe1a8 | BasicAer                                  | `from qiskit.quantum_info import Operator` and use operator instead of BasicAer                                  |
| 36   | `plot_histogram(counts, title="Resultados con pulsos personalizados")`                  | Deprecation -> plot_histogram() with specific datatypes      | qrn_tax_ddbb-8340cefb-6745-41c9-94f1-e220d76e7ab5| plot_histogram                            | `plot_distribution(counts, title="Resultados con pulsos personalizados")`                                       |

```python
from qiskit import QuantumCircuit, transpile
from qiskit.visualization import plot_distribution
from qiskit_aer import AerSimulator
from qiskit_ibm_runtime.fake_provider import FakeProvider
from qiskit import pulse
from qiskit.pulse import Schedule, DriveChannel
import numpy as np
import matplotlib.pyplot as plt

# Usar FakeProvider como backend (simula un dispositivo real con calibraciones)
backend = GenericBackendV2(num_qubits=2)

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
    pulse.play(pulse.Gaussian(160, 0.3, 40).get_waveform(), DriveChannel(0))  # Amplitud diferente

with pulse.build(backend, name='custom_cnot') as cnot_pulse:
    pulse.play(pulse.Gaussian(320, 0.4, 80).get_waveform(), DriveChannel(0))
    pulse.play(pulse.Gaussian(320, 0.2, 80).get_waveform(), DriveChannel(1))

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
plot_distribution(counts, title="Resultados con pulsos personalizados")
plt.show()
```