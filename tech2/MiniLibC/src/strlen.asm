;
; EPITECH PROJECT, 2022
; MiniLibC
; File description:
; strlen
;

bits 64
section .text
global strlen
; size_t strlen(const char *str);

strlen:
    xor    rax, rax

_loop:
    cmp    byte[rdi], 0x0
    je     _end
    inc    rax
    inc    rdi
    jmp    _loop

_end:
    ret
