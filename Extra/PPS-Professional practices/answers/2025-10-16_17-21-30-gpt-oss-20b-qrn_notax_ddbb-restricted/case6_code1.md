| Line | Code | Scenario | Reference | Artifact | Refactoring |
|------|------|----------|-----------|----------|-------------|
| 14 | `pulse.play(pulse.Constant(bell_prep.duration, 0.02), d2)` | Deprecation -> Constant pulse is deprecated | qrn_notax_ddbb-508fb6f3-cdfc-4b96-ad81-f550801dbe2f | Constant | `pulse.play(pulse.library.Constant(bell_prep.duration, 0.02), d2)`