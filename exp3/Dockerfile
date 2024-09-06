FROM ubuntu:latest

RUN apt-get update && apt-get install -y nasm qemu-system-x86

WORKDIR /bootloader

COPY bootloader.asm .

RUN nasm -f bin bootloader.asm -o bootloader.bin

CMD ["tail", "-f", "/dev/null"]
