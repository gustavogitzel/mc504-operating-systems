BITS 16                  ; indica que o código será montado em modo de 16 bits
ORG 0x7C00               ; define a origem com o endereço onde o BIOS carrega o setor de boot na memória

start:
    mov ax, 0x0003       ; coloca no modo vídeo 3 (texto 80x25, 16 cores)
    int 0x10             ; chama a interrupção de BIOS para configurar o modo de vídeo

    mov si, msg          ; coloca o endereço da string msg em no si

print_string:
    lodsb                ; pega o próximo byte da string e coloca no al
    cmp al, 0            ; verifica se chegou no fim da string
    je hang              ; se for fim da string (terminador nulo) pula pro loop
    mov ah, 0x0E         ; configura o AH com a função de imprimir o caractere
    int 0x10             ; chama a interrupção de BIOS para imprimir o caractere que está em al
    jmp print_string     ; repete o processo pro próximo caractere

hang:
    jmp hang             ; entra no loop

msg db 'Hello, Boot!', 0 ; definição da string que será printada com final nulo (0)

times 510-($-$$) db 0    ; preenche o restante do setor de 512 bytes com zeros
dw 0xAA55                ; assinatura do boot
