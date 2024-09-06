; bootloader.asm
BITS 16
ORG 0x7C00

start:
    ; Limpa a tela
    mov ax, 0x0003
    int 0x10

    ; Configura o modo de vídeo
    mov ah, 0x0E
    mov al, 'H'
    int 0x10
    mov al, 'e'
    int 0x10
    mov al, 'l'
    int 0x10
    mov al, 'l'
    int 0x10
    mov al, 'o'
    int 0x10
    mov al, ','
    int 0x10
    mov al, ' '
    int 0x10
    mov al, 'B'
    int 0x10
    mov al, 'o'
    int 0x10
    mov al, 'o'
    int 0x10
    mov al, 't'
    int 0x10
    mov al, '!'
    int 0x10

hang:
    jmp hang

times 510-($-$$) db 0
dw 0xAA55
