# 🖥️ Legacy Bootloader

## 📄 Description

The **Legacy Bootloader** is a simple bootloader written in Assembly, designed to be executed in a virtual machine using QEMU. Its purpose is to demonstrate the basic booting process by displaying a message on the screen when the bootloader is loaded. This project is an introduction to low-level programming and operating system development.

## 🚀 Usage

### ⚙️ Compilation

To compile the bootloader, use the following command:

```bash
nasm -f bin bootloader.asm -o bootloader.bin
```

### 🏃‍♂️ Execution

To run the bootloader in a QEMU virtual machine, use the following command:

```bash
qemu-system-x86_64 -drive format=raw,file=bootloader.bin
```

This will start QEMU and load the bootloader, displaying the configured message on the screen.

## 📂 File Structure

- **bootloader.asm:** Contains all the Assembly code for the bootloader.

## 💻 Features

- **Display Message:** Shows a message upon bootloader initialization.
- **Real Mode (16-bit) Support:** The code operates in 16-bit real mode, compatible with legacy boot environments.
- **Boot Signature:** The boot sector ends with the 0xAA55 signature, required for bootloaders.

## 🧹 Cleaning

To remove the generated binary file, use:

```bash
make clean
```

## 🔄 Rebuilding
To recompile the bootloader from the source code:

```bash
make rebuild
```

## 👨‍💻 Author
- **Name:** Gustavo Ferreira Gitzel
- **RA:** 223559
- **Class:** MC504 A