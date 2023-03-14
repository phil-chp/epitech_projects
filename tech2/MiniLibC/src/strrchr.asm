;
; EPITECH PROJECT, 2022
; MiniLibC
; File description:
; strlen
;

bits 64
section .text
global strrchr
; char *strrchr(const char *s, int c);

strrchr:
    xor    rax, rax
    xor    rcx, rcx

    cmp    rdi, 0x0
    je     _end_null

_loop_to_end:
    cmp    byte[rdi + rcx], 0x0
    je     _loop
    inc    rcx
    jmp    _loop_to_end

_loop:
    cmp    byte[rdi + rcx], sil
    je     _end
    cmp    rcx, 0x0
    je     _end_null
    dec    rcx
    jmp    _loop

_end:
    add    rdi, rcx
    mov    rax, rdi
    ret

_end_null:
    xor    rax, rax
    ret
