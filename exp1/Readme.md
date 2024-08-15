# 🐚 Simple Shell 1.0

## 📄 Description

**Simple Shell** is a minimalist command interpreter called `simpleshell`. It accepts a parameter containing a set of directories separated by the `:` delimiter. The shell waits for a command from the user, and if the command is found in one of the specified directories, it executes the command using the `execv` system call. If the command is not found, it prints an error message.

## 🚀 Usage

### ⚙️ Compilation

To compile the program, use the following command:

```sh
make
```

### 🏃‍♂️ Execution

To run the shell, use the following command:

```sh
./simpleshell <directories>
```

For example:

```sh
./simpleshell /usr:/usr/bin
```

### 💻 Supported Commands

- **Simple Command:** Executes a command without parameters.

  ```sh
  simpleshell$: whoami
  ```

- **Command with Parameters:** Executes a command with parameters.

  ```sh
  simpleshell$: ls -l
  ```

- **Command with Environment Variables:** Executes a command using environment variables.

  ```sh
  simpleshell$: echo $HOME
  ```

- **Command with Absolute Path:** Executes a command using its absolute path.

  ```sh
  simpleshell$: /bin/ls -l
  ```

- **Command with Redirection:** Redirects the output of a command to a file.

  ```sh
  simpleshell$: ls > output.txt
  ```

- **Nonexistent Command:** Prints an error message if the command is not found.

  ```sh
  simpleshell$: nonexistentcommand
  ```

### 🧹 Cleaning

To clean the compiled files, use:

```sh
make clean
```

### 🔄 Rebuilding

To rebuild the program from scratch, use:

```sh
make rebuild
```

## 👨‍💻 Author
- **Name:** Gustavo Ferreira Gitzel
- **RA:** 223559
- **Class:** MC504 A
