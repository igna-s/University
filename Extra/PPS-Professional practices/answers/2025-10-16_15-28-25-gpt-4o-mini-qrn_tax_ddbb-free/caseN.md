| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- |  
| 3 | `from qiskit.providers.fake_provider import FakeManila` | Deprecation -> Running pulse jobs on backends from qiskit.providers.fake_provider is deprecated | qrn_tax_ddbb-693b5266-a1ce-476c-87b8-c30e824bd87d | qiskit.providers.fake_provider | `from qiskit_aer import AerSimulator` (remove FakeManila) |  
| 34 | `backend = FakeManila()` | Deprecation -> Running pulse jobs on backends from qiskit.providers.fake_provider is deprecated | qrn_tax_ddbb-693b5266-a1ce-476c-87b8-c30e824bd87d | qiskit.providers.fake_provider | (remove) |  
| 25 | `from qiskit import pulse` | Deprecation -> The qiskit.pulse module is deprecated | IK | qiskit.pulse | (remove) |  
| 30 | `schedule = Schedule()` | Deprecation -> ScheduleBlock methods are deprecated | IK | Schedule | (remove) |  
| 38 | `from qiskit.pulse import Schedule, DriveChannel` | Deprecation -> The qiskit.pulse module is deprecated | IK | qiskit.pulse | (remove) |  
| 43 | `with pulse.build(backend, name='custom_hadamard') as hadamard_pulse:` | Deprecation -> Running pulse jobs on backends from qiskit.providers.fake_provider is deprecated | qrn_tax_ddbb-693b5266-a1ce-476c-87b8-c30e824bd87d | qiskit.providers.fake_provider | (remove) |  
| 55 | `backend.defaults().instruction_schedule_map.add('h', (0,), hadamard_pulse)` | Deprecated -> Registering pulses to the backend directly for execution is deprecated | IK | backend.defaults() | (remove) |  
| 57 | `backend.defaults().instruction_schedule_map.add('cx', (0, 1), cnot_pulse)` | Deprecated -> Registering pulses to the backend directly for execution is deprecated | IK | backend.defaults() | (remove) |  
| 60 | `simulator = AerSimulator.from_backend(backend)` | Deprecation -> Use of qiskit.Aer is deprecated | qrn_tax_ddbb-4e1a7f69-eeb4-4a93-9f27-322819438bf4 | qiskit.Aer | `simulator = AerSimulator()` |  
| 63 | `result = job.result()` | Deprecation -> Using result from Deprecated API | IK | job.result() | (remains) |  
| 66 | `plot_histogram(counts, title="Resultados con pulsos personalizados")` | Deprecation -> Support for plotting histogram from QuasiDistribution will be removed | qrn_tax_ddbb-4e1a7f69-eeb4-4a93-9f27-322819438bf4 | plot_histogram |  `plot_distribution(counts, title="Resultados con pulsos personalizados")` |  

```python
from qiskit import QuantumCircuit, transpile
from qiskit.visualization import plot_distribution
from qiskit_aer import AerSimulator
import numpy as np
import matplotlib.pyplot as plt

# Crear un circuito cuántico simple
qc = QuantumCircuit(2, 2)

# Aplicar compuertas cuánticas
qc.h(0)
qc.cx(0, 1)
qc.rz(np.pi/4, 0)
qc.measure([0, 1], [0, 1])

# Simulación del circuito

# Transpilar el circuito con optimización a nivel de pulsos
transpiled_qc = transpile(qc, optimization_level=3)

# Simular con AerSimulator utilizando el backend correcto
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