# Qiskit Refactoring Project with RAG

![Status](https://img.shields.io/badge/Status-Experimental-orange)
![Python](https://img.shields.io/badge/Python-3.10%2B-blue)
![License](https://img.shields.io/badge/License-Apache_2.0-green)

## 📋 Project Overview

**RAG-LLM-QISKIT** is a scientific repository designed to assist in the **migration and refactoring of Qiskit code** using Retrieval-Augmented Generation (RAG) techniques and Large Language Models (LLMs).

The system automates the update process for legacy quantum code by leveraging official Qiskit release notes and documentation as a knowledge base. It allows for flexible experimentation with various AI agents (local and cloud-based) to detect deprecated scenarios and suggest code updates.

---



## 📄 Extended Abstract

This repository includes the published extended abstract, which documents the theoretical framework, methodology, and initial experimental results of using LLMs for Qiskit code migration.

You can view the document here:
* [**Qiskit_Code_Migration_with_LLMs.pdf**](Qiskit_Code_Migration_with_LLMs.pdf)


---
## 🏗 Architecture & Technologies

### Data Ingestion
* **Source:** Data is ingested from the `/data-ingestion` directory.
* **Content:** Currently focused on processing **Qiskit Release Notes** to build the knowledge base.

### Embedding Model
* **Current Model:** `ollama:nomic-embed-text:v1.5`
* **Vector Database:** Qdrant (Collection: `qrn_ddbb`)

### Experimental LLMs
We are currently validating the pipeline with the following models:
* **Local:** Ollama GPT-oss20B.
* **Cloud (OpenAI):** ChatGPT-4.0 / ChatGPT-4.1.
* **Cloud (Google):** Gemini Flash-2.5.
* **Experimental:** DeepSeek v3 (Integration via n8n is currently under evaluation).

---

## ⚙️ Configuration & Parameters

The execution of the pipeline is controlled via a JSON configuration object. Below is a detailed description of the available parameters:

| Parameter | Description |
| :--- | :--- |
| **`rag_chatbot_step`** | `Boolean`. Indicates whether the execution runs the bot for snippet processing (`true`) or performs a Vector DB load only (`false`). |
| **`is_restricted`** | `Boolean`. Controls whether the processing incorporates the automatic taxonomy of scenarios into the Qiskit release notes. |
| **`no_refactoring_chatbot_step`** | `Boolean`. If `true`, the prompt asks for detected scenarios only. If `false`, it requests the adapted code as well. |
| **`selected-ai-agent`** | Defines the AI agent to use. Possible values: `'gemini'`, `'ollama'`, `'openai'`. |
| **`target-repo-url`** | Base URL of the target web repository. |
| **`target-version`** | The specific Qiskit version being targeted for migration. |
| **`only_qrn_for_data_ingestion`** | Flag to restrict ingestion strictly to Quantum Release Notes (QRN). |
| **`repo-github`** | **Object**. specific configurations associated with the remote repository (see structure below). |

### `repo-github` Structure

| Key | Description |
| :--- | :--- |
| `owner` | Owner of the experimental GitHub repository. |
| `name` | Name of the GitHub project. |
| `data-ingestion-path` | Directory path for data ingestion. |
| `data-rag-chatbot-path` | Directory path for model data sources. |
| `snippets-path` | Directory containing Python code snippets for testing. |
| `prompts-path` | Directory containing System and User prompts. |
| `answers-path` | Output directory for the results of each test. |

---

## 🚀 Usage Example

To trigger a workflow (e.g., via n8n or a direct script), use a JSON payload similar to the following. This example sets up a test using a local **Ollama** model.

```json
[
  {
    "rag_chatbot_step": true,
    "qdrant-collection": "qrn_ddbb",
    "only_qrn_for_data_ingestion": false,
    "selected-ai-agent": "ollama",
    "chat-bot-model": "ollama-gpt-oss-20b",
    "repo-github": {
      "owner": "jose-manuel-suarez",
      "name": "qiskit_rag",
      "data-ingestion-path": "data-ingestion/",
      "data-rag-chatbot-path": "data-rag-chatbot/",
      "snippets-path": "data-rag-chatbot/snippets/",
      "prompts-path": "data-rag-chatbot/prompts/",
      "answers-path": "answers/"
    },
    "target-repo-url": "[https://github.com/](https://github.com/)",
    "target-version": "1.0.0",
    "user_prompt_file": "user_prompt.md",
    "taxonomy-filename": "tax_gpt_1.0.0.md",
    "experimental_mode": "free",
    "system_prompt_file": "system_prompt_free_mode.md",
    "validation_stage": false
  }
]
```


## 📂 Repository Structure

```text
Qiskit-RAG-Migration-Assistant/
├── answers/             # Generated responses from the LLM
├── assets/              # Static assets
├── data-ingestion/      # Release notes and raw documentation
├── data-rag-chatbot/    # Core logic resources
│   ├── prompts/         # Markdown prompt templates (System/User)
│   └── snippets/        # Python snippets for refactoring tests
├── n8n/                 # Workflow configurations
├── workflows/           # Workflow definitions
├── shared/              # Shared utilities
├── docker-compose.yml   # Docker services configuration
├── .env.example         # Environment variables template
├── Qiskit_Code_Migration_with_LLMs.pdf   # Paper
└── README.md            # Project documentation
```



## 🤝 Contributing

Contributions are welcome! If you want to add support for new models (like DeepSeek) or improve the ingestion taxonomy:

1. Fork the repository.
2. Create a feature branch (`git checkout -b feature/AmazingFeature`).
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`).
4. Push to the branch (`git push origin feature/AmazingFeature`).
5. Open a Pull Request.


## 📄 License

This project is licensed under the Apache-2.0 License -  see the [LICENSE](LICENSE) file for details.


