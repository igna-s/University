| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> FakeVigo import moved | * | Internal Knowledge | FakeVigo | `from qiskit.providers.fake_provider import FakeVigo` |

```python
    from mylib import getJob, getCount
    from qiskit.providers.fake_provider import FakeVigo
    from qiskit.test.reference_circuits import ReferenceCircuits

    qc = ReferenceCircuits.bell()
    backend = FakeVigo()

    job = getJob(qc, backend)
    counts = getCount(job)

    print("Resultados del circuito Bell:")
    print(counts)
```
