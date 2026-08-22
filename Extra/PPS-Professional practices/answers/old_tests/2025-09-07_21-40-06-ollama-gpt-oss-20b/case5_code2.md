| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 17 | `result = execute(qc, simulator).result()` | * | Deprecation -> `execute()` function deprecated | execute | `result = simulator.run(qc).result()` |