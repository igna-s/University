# N-Queens Quantum Solver

![Status](https://img.shields.io/badge/Status-Completed-success)
![Python](https://img.shields.io/badge/Python-3.10%2B-blue)
![License](https://img.shields.io/badge/License-Apache_2.0-green)

## 📋 Project Overview

**N-Queens Quantum Solver** is a scientific and educational repository designed to implement, analyze, and compare quantum and classical algorithms for solving the well-known combinatorial **N-Queens Problem**.

The system explores the application of quantum computing to constraint satisfaction problems. It features a modern web platform connected to a serverless backend that runs algorithmic simulations.

🌍 **Live Web App:** [https://thankful-pond-0af99ab10.7.azurestaticapps.net/](https://thankful-pond-0af99ab10.7.azurestaticapps.net/)

---

## 📄 Extended Abstract / Report

This repository includes detailed mathematical reports documenting the theoretical framework, the quantum oracle design, and experimental results of using Grover's Algorithm for the N-Queens problem.

You can view the documents here:
* [**informe_nqueens_grover.pdf (Español)**](data/informe_nqueens_grover.pdf)
* [**informe_nqueens_grover_en.pdf (English)**](data/informe_nqueens_grover_en.pdf)

---

## 🏗 Architecture & Technologies

### Frontend
* **Core:** HTML, CSS, JavaScript (Vanilla).
* **Hosting:** Azure Static Web Apps.
* **Features:** Interactive UI for N-Queens rendering and algorithm execution.

### Backend (API)
* **Framework:** Azure Functions (Serverless).
* **Language:** Python and C.
* **Quantum Libraries:** Qiskit, Azure Quantum.

### Experimental Algorithms
We evaluate three distinct approaches:
* **Grover's Algorithm:** Quantum unstructured search with amplitude amplification.
* **QAOA:** Variational quantum approach (Quantum Approximate Optimization Algorithm).
* **Classical (Takaken):** Highly optimized bitwise classical implementation in C to establish a performance baseline.

---

## ⚙️ Configuration & Parameters

When running the solvers (either via the web platform or locally), you can explore different configurations:

| Parameter | Description |
| :--- | :--- |
| **`N` (Board Size)** | Defines the size of the board and number of queens. Typical values explored are $N=4$ and $N=5$. |
| **`algorithm`** | The solver to use: `'grover'`, `'qaoa'`, or `'classical'`. |
| **`backend`** | (Azure Quantum) Specifies the target quantum hardware or simulator (e.g., `ionq.simulator`, `quantinuum.sim.h1-1sc`). |
| **`shots`** | Number of quantum circuit executions to build the measurement probability distribution (default: 1024-4096). |

---

## 🚀 Usage Example

To test the backend locally via Azure Functions Core Tools:

```bash
# Navigate to the API directory
cd api/

# Install Python requirements
pip install -r requirements.txt

# Start the local function host
func start
```

Once the API is running locally, you can open `app/index.html` in your browser to interact with the solvers. 

For Azure Quantum cloud execution, refer to `Extra/azure_quantum_run.py`, ensuring you configure your `SUBSCRIPTION_ID`, `RESOURCE_GROUP`, and `WORKSPACE_NAME`.

---

## 📂 Repository Structure

```text
NQueens-Quantum-Solver/
├── api/                 # Serverless backend (Azure Functions)
│   ├── function_app.py  # HTTP triggers and routing
│   ├── nqueens_*.py     # Qiskit implementations (Grover, QAOA)
│   └── nreinas.c        # Fast classical solver in C
├── app/                 # Frontend web application
│   └── index.html       # UI interface
├── data/                # LaTeX reports and compiled PDFs
├── Extra/               # Supplementary scripts
│   ├── azure_quantum_run.py       # Job submission to Azure Quantum
│   └── grover_circuit_explorer.html # Circuit visualizer
├── .gitignore           # Git ignore patterns
├── LICENSE              # Apache 2.0 License
└── README.md            # Project documentation
```

---

## 🤝 Contributing

Contributions are welcome! If you want to add support for new quantum algorithms (like VQE) or improve the oracle design:

1. Fork the repository.
2. Create a feature branch (`git checkout -b feature/AmazingFeature`).
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`).
4. Push to the branch (`git push origin feature/AmazingFeature`).
5. Open a Pull Request.

---

## 📄 License

This project is licensed under the Apache 2.0 License - see the [LICENSE](LICENSE) file for details.
