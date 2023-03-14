;
; EPITECH PROJECT, 2022
; MiniLibC
; File description:
; strlen
;

bits 64
section .text
global strchr
; char *strchr(const char *s, int c);

strchr:
    xor    rax, rax
    mov    rax, rdi

    cmp    rdi, 0x0
    je     _end_null

_loop:
    cmp    byte[rax], sil
    je     _end
    cmp    byte[rax], 0x0
    je     _end_null
    inc    rax
    jmp    _loop

_end:
    ret

_end_null:
    xor    rax, rax
    ret
