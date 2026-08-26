# 📚 IIT Jodhpur B.Tech Wiki & Knowledge Base

Welcome to the central academic wiki for **IIT Jodhpur B.Tech (B25 / B24)**! This knowledge base is curated to provide a unified reference for courses, study materials, tutorial problems, reference books, lab guides, and exam preparation tips.

---

## 🧭 Quick Navigation

- [📖 Course Index (B25)](#-course-index-b25)
- [📦 Archive (B24)](#-archive-b24)
- [🎯 Exam & Evaluation Structure](#-exam--evaluation-structure)
- [💡 Subject-wise Preparation Guide](#-subject-wise-preparation-guide)
- [💻 Software & Tools Setup](#-software--tools-setup)
- [🤝 How to Contribute](#-how-to-contribute)
- [👥 Credits & Acknowledgments](#-credits--acknowledgments)

---

## 📖 Course Index (B25)

The repository is organized by subject codes. Below is the complete catalog of first-year courses:

| Course Code | Course Name | Resources Available | Semester |
| :--- | :--- | :--- | :--- |
| **`MAL1010`** | Mathematics I (Calculus & Linear Algebra) | Slides, Tutorials, Important Points, Books | Semester 1 |
| **`CSL1010`** | Computer Programming | Fall 2025 / Spring 2026 Slides, Problem Sets | Sem 1 / Sem 2 |
| **`PHL1010`** | Physics for Engineers | Lecture Slides, Tutorials, Reference Texts | Sem 1 / Sem 2 |
| **`CYL1010`** | Chemistry | Lecture Notes, Slides, Practice Problems | Sem 1 / Sem 2 |
| **`CY-LaB`** | Chemistry Laboratory | Lab Manuals, Guidelines, Observation Formats | Sem 1 / Sem 2 |
| **`EEL1010`** | Introduction to Electrical Engineering | Circuit Theory, Notes, Problem Sets | Sem 1 / Sem 2 |
| **`MEL1010`** | Engineering Mechanics | Statics, Dynamics, Problem Sheets, Books | Sem 1 / Sem 2 |
| **`BBL1020`** | Introduction to Biology | Biology for Engineers Slides, Notes | Sem 1 / Sem 2 |
| **`CS`** | Communication Skills | Presentation Slides, Grammar & Report Writing | Sem 1 / Sem 2 |

---

## 📦 Archive (B24)

For additional problem sets, past tutorial sheets, and previous year question styles, refer to the **B24 archive**:

- `B24/MAL1020-B24`: Mathematics II (Multivariable Calculus, ODEs/PDEs)
- `B24/PHL1010-B24`: Previous batch Physics tutorials & notes
- `B24/CY-B24`: Previous batch Chemistry question sets
- `B24/Tut-B24`: Consolidated tutorial problem archive

---

## 🎯 Exam & Evaluation Structure

At IIT Jodhpur, courses typically follow a continuous evaluation pattern:

```
Total (100 Marks)
├── Continuous Assessment (20% - 30%)
│   ├── Quizzes (Surprise / Announced)
│   ├── Assignments & Homework
│   └── Tutorial Participation
├── Mid-Semester / Minor Examination (25% - 30%)
└── End-Semester / Major Examination (40% - 50%)
```

> **Tip:** Do not ignore tutorial sheets! In subjects like `MAL1010`, `PHL1010`, and `MEL1010`, tutorial questions or close variants frequently appear in Quizzes and Mid-Sem exams.

---

## 💡 Subject-wise Preparation Guide

### 1. 🧮 Mathematics (`MAL1010` / `MAL1020`)
* **Core Focus:** Limits, Continuity, Single & Multivariable Calculus, Sequences & Series, Linear Algebra (Matrices, Eigenvalues, Vector Spaces).
* **Strategy:**
  1. Solve every single question from the assigned **Tutorial Sheets**.
  2. Refer to standard textbooks (e.g., *Thomas' Calculus*, *Erwin Kreyszig - Advanced Engineering Mathematics*).
  3. Write down formulas and theorem conditions in a summary sheet before quizzes.

### 2. 💻 Computer Programming (`CSL1010`)
* **Core Focus:** Control structures, loops, functions, arrays, pointers, memory allocation, recursion, and basic data structures.
* **Strategy:**
  1. Hand-tracing code with sample inputs is crucial for written quizzes.
  2. Implement every lab problem from scratch without relying on AI code generators during practice.
  3. Pay close attention to edge cases: null pointers, off-by-one errors, and boundary values.

### 3. ⚛️ Physics (`PHL1010`)
* **Core Focus:** Classical mechanics/oscillations, electromagnetic theory, optics, and introductory quantum mechanics.
* **Strategy:**
  1. Focus deeply on derivations and the physical interpretation of boundary conditions.
  2. Solve previous year tutorial problems from both `B25` and `B24` folders.

### 4. ⚙️ Engineering Mechanics (`MEL1010`)
* **Core Focus:** Free Body Diagrams (FBD), equilibrium equations, friction, trusses, virtual work, kinematics and dynamics of particles and rigid bodies.
* **Strategy:**
  1. **Master the FBD first** — 80% of mistakes happen due to incorrect coordinate axes or missing reaction forces.
  2. Textbook reference: *J.L. Meriam & L.G. Kraige* or *Beer & Johnston*.

### 5. 🧪 Chemistry & Lab (`CYL1010` / `CY-LaB`)
* **Core Focus:** Physical chemistry concepts, spectroscopy, polymers, electrochemistry, and organic reaction mechanisms.
* **Strategy:**
  1. Keep lab records up-to-date with error analysis and neat calculations.
  2. Review the slide summaries in the repository before Minor/Major exams.

---

## 💻 Software & Tools Setup

Quick setup commands for local development tools:

### macOS
```bash
# Install Homebrew (if not present)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install essential compilers and tools
brew install git gcc python cmake
```

### Ubuntu / Debian Linux
```bash
sudo apt update
sudo apt install -y build-essential git python3 python3-pip gdb
```

### Windows
1. Install [Git for Windows](https://git-scm.com/download/win).
2. Install [Visual Studio Code](https://code.visualstudio.com/).
3. Install **MinGW-w64** or use **WSL2 (Windows Subsystem for Linux)** for a native Linux environment:
   ```powershell
   wsl --install
   ```

---

## 🤝 How to Contribute

To add missing notes, new tutorial solutions, or previous exam papers:

1. **Fork the Repository**: Click the **Fork** button at the top right of the [GitHub Repo](https://github.com/IamShreshth/iitjodhpur).
2. **Clone your fork**:
   ```bash
   git clone https://github.com/<your-username>/iitjodhpur.git
   ```
3. **Add your materials** under the appropriate course folder:
   - Make sure PDFs are well-scanned (use tools like CamScanner / Adobe Scan).
   - Use clean filenames (e.g., `Tutorial_03_Solutions.pdf`, `Midsem_2025_Paper.pdf`).
4. **Commit & Push**:
   ```bash
   git add .
   git commit -m "Add: MAL1010 Tutorial 3 solutions"
   git push origin main
   ```
5. **Open a Pull Request (PR)** on GitHub with a brief description.

---

## 👥 Credits & Acknowledgments

- **Maintainer:** [Shreshth Dhimole](https://github.com/IamShreshthDhimole)
- **Contributors & Material Sources:** [Abhishek Reddy](https://github.com/abhishekreddy22) and batchmates across IIT Jodhpur B25 & B24.

---

<p align="center">
  <i>Maintained for the IIT Jodhpur Student Community • Good luck with your academics! 🚀</i>
</p>
