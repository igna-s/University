| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.providers.fake_provider import *` | Module relocation -> The `qiskit.providers.fake_provider` module has been moved. | internal | `qiskit.providers.fake_provider` | `from qiskit.test.mock import FakeOpenPulse2Q` |