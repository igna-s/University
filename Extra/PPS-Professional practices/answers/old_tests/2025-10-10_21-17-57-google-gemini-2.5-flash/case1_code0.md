| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit.pulse.transforms import squash` | Deprecation -> `qiskit.pulse.transforms.squash` has been deprecated. It has been superseded by `qiskit.transpiler.passes.RZXWeylDecomposition` and will be removed in a future release. | internal | `qiskit.pulse.transforms.squash` | `from qiskit.transpiler.passes import RZXWeylDecomposition` |
| 2 | `from qiskit.pulse.transforms import piecewise_waveform` | Deprecation -> `qiskit.pulse.transforms.piecewise_waveform` has been deprecated. It has been superseded by `qiskit.transpiler.passes.RZXWeylDecomposition` and will be removed in a future release. | internal | `qiskit.pulse.transforms.piecewise_waveform` | `from qiskit.transpiler.passes import RZXWeylDecomposition` |


```python
from qiskit.transpiler.passes import RZXWeylDecomposition
from qiskit.transpiler.passes import RZXWeylDecomposition
```