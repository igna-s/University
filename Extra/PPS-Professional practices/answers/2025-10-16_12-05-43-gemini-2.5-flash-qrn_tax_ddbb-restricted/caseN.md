| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :------- | :------- | :---------- |
| 2 | `from qiskit.visualization import plot_histogram` | Deprecation -> `plot_histogram()` for distribution dictionaries is deprecated. | qrn_tax_ddbb-8340cefb-6745-41c9-94f1-e220d76e7ab5 | `plot_histogram()` | `from qiskit.visualization import plot_distribution` |
| 4 | `from qiskit.providers.fake_provider import FakeManila` | Deprecation -> `qiskit.providers.fake_provider` module has been migrated. | qrn_tax_ddbb-27ebf47d-f549-4a4b-ad7c-72ec480eb99d | `qiskit.providers.fake_provider.FakeManila` | `from qiskit_ibm_runtime.fake_provider import FakeManila` |
| 5 | `from qiskit import pulse` | Deprecation -> Running pulse jobs on backends from `qiskit.providers.fake_provider` is deprecated. | qrn_tax_ddbb-084696d9-2c75-437a-8e84-96506e6766aa | `qiskit.pulse` | |
| 6 | `from qiskit.pulse import Schedule, DriveChannel` | Deprecation -> Running pulse jobs on backends from `qiskit.providers.fake_provider` is deprecated. | qrn_tax_ddbb-084696d9-2c75-437a-8e84-96506e6766aa | `qiskit.pulse.Schedule`, `qiskit.pulse.DriveChannel` | |
| 22 | `schedule = Schedule()` | Deprecation -> Running pulse jobs on backends from `qiskit.providers.fake_provider` is deprecated. | qrn_tax_ddbb-084696d9-2c75-437a-8e84-96506e6766aa | `Schedule()` | |
| 23 | `drive_chan = DriveChannel(0)` | Deprecation -> Running pulse jobs on backends from `qiskit.providers.fake_provider` is deprecated. | qrn_tax_ddbb-084696d9-2c75-437a-8e84-96506e6766aa | `DriveChannel` | |
| 26 | `with pulse.build(backend, name='custom_hadamard') as hadamard_pulse:` | Deprecation -> Running pulse jobs on backends from `qiskit.providers.fake_provider` is deprecated. | qrn_tax_ddbb-084696d9-2c75-437a-8e84-96506e6766aa | `pulse.build()` | |
| 28 | `pulse.play(pulse.Gaussian(160, 0.3, 40), pulse.DriveChannel(0))` | Deprecation -> `ParametricPulse` base class and pulses are deprecated, including `Gaussian`. Running pulse jobs on `fake_provider` backends is deprecated. | qrn_tax_ddbb-b5111ded-f178-4354-a8db-f475bdf64d57 | `pulse.Gaussian` | |
| 30 | `with pulse.build(backend, name='custom_cnot') as cnot_pulse:` | Deprecation -> Running pulse jobs on backends from `qiskit.providers.fake_provider` is deprecated. | qrn_tax_ddbb-084696d9-2c75-437a-8e84-96506e6766aa | `pulse.build()` | |
| 32 | `pulse.play(pulse.Gaussian(320, 0.4, 80), pulse.DriveChannel(0))` | Deprecation -> `ParametricPulse` base class and pulses are deprecated, including `Gaussian`. Running pulse jobs on `fake_provider` backends is deprecated. | qrn_tax_ddbb-b5111ded-f178-4354-a8db-f475bdf64d57 | `pulse.Gaussian` | |
| 33 | `pulse.play(pulse.Gaussian(320, 0.2, 80), pulse.DriveChannel(1))` | Deprecation -> `ParametricPulse` base class and pulses are deprecated, including `Gaussian`. Running pulse jobs on `fake_provider` backends is deprecated. | qrn_tax_ddbb-b5111ded-f178-4354-a8db-f475bdf64d57 | `pulse.Gaussian` | |
| 36 | `backend.defaults().instruction_schedule_map.add('h', (0,), hadamard_pulse)` | Deprecation -> Running pulse jobs on backends from `qiskit.providers.fake_provider` is deprecated. | qrn_tax_ddbb-084696d9-2c75-437a-8e84-96506e6766aa | `instruction_schedule_map.add()` | |
| 37 | `backend.defaults().instruction_schedule_map.add('cx', (0, 1), cnot_pulse)` | Deprecation -> Running pulse jobs on backends from `qiskit.providers.fake_provider` is deprecated. | qrn_tax_ddbb-084696d9-2c75-437a-8e84-96506e6766aa | `instruction_schedule_map.add()` | |
| 46 | `plot_histogram(counts, title="Resultados con pulsos personalizados")` | Deprecation -> `plot_histogram()` for distribution dictionaries is deprecated. | qrn_tax_ddbb-8340cefb-6745-41c9-94f1-e220d76e7ab5 | `plot_histogram()` | `plot_distribution(counts, title="Resultados de simulación de circuito")` |


```python
from qiskit import QuantumCircuit, transpile
from qiskit.visualization import plot_distribution
from qiskit_aer import AerSimulator
from qiskit_ibm_runtime.fake_provider import FakeManila
import numpy as np
import matplotlib.pyplot as plt

backend = FakeManila()

qc = QuantumCircuit(2, 2)

qc.h(0)
qc.cx(0, 1)
qc.rz(np.pi/4, 0)
qc.measure([0, 1], [0, 1])

transpiled_qc = transpile(qc, backend, optimization_level=3)

simulator = AerSimulator.from_backend(backend)
job = simulator.run(transpiled_qc, shots=1024)

result = job.result()
counts = result.get_counts()

print("Conteos de simulación de circuito:", counts)
plot_distribution(counts, title="Resultados de simulación de circuito")
plt.show()

```