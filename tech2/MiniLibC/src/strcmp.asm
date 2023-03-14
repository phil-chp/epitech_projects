
; EPITECH PROJECT, 2022
; MiniLibC
; File description:
; strlen

bits 64
section .text
global strcmp
; int strcmp(const char *s1, const char *s2);

strcmp:
    xor rbx, rbx
    xor rcx, rcx
    xor rdx, rdx

_cmp:
    mov byte bl, [rsi + rcx]
    cmp byte [rdi + rcx], bl
    jne _end
    cmp byte bl, 0x0
    je  _end
    inc rcx
    jmp _cmp

_end:
    mov byte dl, [rdi + rcx]
    sub rbx, rdx
    neg rbx
    mov rax, rbx
    ret
