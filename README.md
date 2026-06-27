# IIT Jodhpur Academics & Coursework Repository

Welcome to the IIT Jodhpur coursework archive. This repository serves as a centralized hub for students to access and share question papers, study materials, lecture slides, assignments, and tutorial sheets for various batches and semesters.

> [!IMPORTANT]  
> The contents of this repository are intended strictly for reference, practice, and academic preparation.

---

## 📂 Repository Structure

The repository is organized hierarchically by **Batch**, then by **Semester**, and finally by the official **Course Code**. 

```text
iitjodhpur/
├── B25/                                    # Batch (e.g., B25 for Batch of 2025)
│   ├── Sem-1/                              # Semester (Sem-1, Sem-2, etc.)
│   │   ├── BBL1020/                        # Folder name MUST be the Course Code
│   │   │   ├── Lecture Notes/
│   │   │   ├── Tutorials/
│   │   │   └── ...
│   │   ├── CSL1010/
│   │   └── ...
│   └── Sem-2/
│       ├── MAL1020/
│       ├── PHL1010/
│       └── ...
```

---

## ✍️ Contribution Guidelines

We highly encourage contributions! If you have coursework resources, assignments, tutorial sheets, or exam papers, please contribute to help keep this archive updated.

### ⚠️ Crucial Folder Naming Rule
* **Folder Name = Course Code**: Any new folder created under a semester directory **MUST** be named exactly after its official course code (e.g., `CSL1010`, `MAL1020`, `PHL1010`).
* Do **NOT** use descriptive names for course folders (e.g., do not name a folder `Linear Algebra` or `Mathematics II`). Use the official course code.

### 📄 File Naming Conventions
To keep the archive clean and easily searchable, please follow these naming conventions:

* **Exam Papers**: `<Course_Code>_<Exam_Type>_<Year>.<ext>`
  * *Example*: `MAL1020_Midsem_2026.pdf`
  * *Example*: `CSL1010_Quiz1_2025.jpg`
* **Tutorials / Assignments**: `<Course_Code>_<Type>_<Number>.<ext>`
  * *Example*: `PHL1010_Tutorial_03.pdf`
  * *Example*: `MEL1010_Assignment_02.pdf`
* **Lecture Notes / Slides**: `<Course_Code>_Lecture_<Number_or_Topic>.<ext>`
  * *Example*: `BBL1020_Lecture_12_Bioenergetics.pdf`

---

## 🚀 How to Contribute

To contribute your files to this repository, please follow these steps:

1. **Fork the Repository**
   Click the **Fork** button at the top right of this repository page to create a copy under your GitHub account.

2. **Clone Your Fork**
   ```bash
   git clone https://github.com/YOUR_USERNAME/iitjodhpur.git
   cd iitjodhpur
   ```

3. **Create a New Branch**
   ```bash
   git checkout -b add-coursework-resources
   ```

4. **Add Your Files**
   Ensure your files follow the **Folder Naming Rule** (using exact course codes) and file naming conventions. Place them in the appropriate directory.

5. **Commit Your Changes**
   Write a descriptive commit message:
   ```bash
   git add .
   git commit -m "Add MAL1020 Midsem 2026 paper and Tutorial 3"
   ```

6. **Push and Pull Request**
   Push the changes to your fork and submit a Pull Request (PR) to the main repository.
   ```bash
   git push origin add-coursework-resources
   ```

---

*Thank you for contributing and helping your peers! If you notice any typos or have suggestions for structure improvements, feel free to open an issue or pull request.*
