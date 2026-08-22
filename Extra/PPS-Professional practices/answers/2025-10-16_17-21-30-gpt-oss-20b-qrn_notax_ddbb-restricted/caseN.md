| Line | Code | Scenario | Reference | Artifact | Refactoring |
|------|------|----------|-----------|----------|-------------|
| 4 | `from qiskit.providers.fake_provider import FakeManila` | Deprecation → `FakeManila` import from `qiskit.providers.fake_provider` is deprecated in 1.0.0 | IK | FakeManila | `from qiskit_ibm_runtime.fake_provider import FakeProvider` |
| 11 | `backend = FakeManila()` | Deprecation → Instantiating `FakeManila` directly is deprecated in 1.0.0 | IK | FakeManila | `backend = FakeProvider().get_backend('fake_manila')` |