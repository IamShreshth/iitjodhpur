# Contributing

You can help by adding course material, fixing existing files, or improving the documentation.

## Add material

- Place files under the matching year and course folder (for example, `1_First_Year/CSL1010/`).
- Check [`legend.txt`](legend.txt) for course codes and search the folder for duplicates.
- Remove personal information from files. Prefer PDFs and keep files under 50 MB where possible; share links to larger materials.

## Submit a pull request

1. Fork and clone the repository.
2. Create a branch using `COURSECODE_ProfName`, for example:

   ```bash
   git checkout -b CSL1010_ProfName
   ```

3. Add your changes. Keep each pull request to one course.
4. Commit, push your branch, and open a pull request:

   ```bash
   git add .
   git commit -m "CSL1010_ProfName: add lecture slides"
   git push origin CSL1010_ProfName
   ```

5. Use `COURSECODE_ProfName` as the pull request title and complete the pull request template.

Use the uppercase course code from [`legend.txt`](legend.txt), followed by one underscore and the professor's name without spaces. Use a hyphen or CamelCase in the name.

## Request material

[Open a resource request](https://github.com/IamShreshth/iitjodhpur/issues/new?template=resource-request.md). Include the course code, professor, material needed, and what you have already checked.
