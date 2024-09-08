# 🖥️ MC504 - Operating Systems

Welcome to the **MC504 - Operating Systems** repository. This repository contains the code and documentation for various experiments conducted as part of the MC504 course at University of Campinas. Each experiment explores different aspects of operating systems, from basic shell implementation to more advanced features like process management and bootloaders.

## 📁 Repository Structure

- **`exp1/`**: Contains the code and README for **Simple Shell 1.0**.
- **`exp2/`**: Contains the code and README for **Simple Shell 2.0**.
- **`exp3/`**: Contains the code and README for **Legacy Bootloader**.

Each subdirectory includes the source code and a detailed README explaining the experiment.

## 📚 Course Information

- **Course**: MC504 - Operating Systems
- **Instructor**: [Paulo Lício de Geus](https://lasca.ic.unicamp.br/~paulo/)
- **Semester**: 6o Semester
- **University**: University of Campinas

## 🚀 Experiments Overview

### 🐚 Simple Shell 1.0 (`exp1/`)

The first experiment involves creating a simple shell interpreter called `simpleshell`. It demonstrates the basics of command execution in an operating system environment. Key features include:

- Execution of commands located in specified directories.
- Handling of environment variables.
- Basic error handling for nonexistent commands.

For more details, refer to the [Simple Shell 1.0 README](exp1/README.md).

### 🐚 Simple Shell 2.0 (`exp2/`)

The second experiment extends the simple shell by adding more advanced features like:

- Background command execution using the `&` symbol.
- Process creation using the `fork` system call.
- Continuous command execution until the user exits the shell.

For more details, refer to the [Simple Shell 2.0 README](exp2/README.md).

### 🖥️ Legacy Bootloader (`exp3/`)

The third experiment involves the creation of a **Legacy Bootloader** using Assembly language. This bootloader demonstrates the process of system initialization by displaying a message when loaded in a virtual machine environment. Key features include:

- Real-mode execution (16-bit).
- Displaying a message when the bootloader is executed.
- A proper boot sector signature (`0xAA55`).

For more details, refer to the [Legacy Bootloader README](exp3/README.md).

## 👨‍💻 Author
- **Name:** Gustavo Ferreira Gitzel
- **RA:** 223559
- **Class:** MC504 A