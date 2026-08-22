1. '''
2. Test code for importing and 
3. using libraries that are not related to Qiskit.
4. '''
5. 
6. 
7. # requeriments imports
8. 
9. # import os funcionalities
10. import os
11. 
12. # import QuantumCircuit funcionalities
13. from qiskit import QuantumCircuit
14. 
15. # import datetime funcionalities
16. from datetime import datetime
17. 
18. # create a Quantum Circuit
19. qc = QuantumCircuit(2, 2)
20. qc.h(0)
21. qc.cx(0, 1)
22. qc.measure(0, 0)
23. qc.measure(1, 1)
24. 
25. # print
26. print("work done !")