;
; EPITECH PROJECT, 2022
; MiniLibC
; File description:
; strlen
;

bits 64
section .text
global memmove
; void *memmove(void *dest, const void *src, size_t n);

memmove:
    xor    rax, rax
    xor    rcx, rcx
    xor    r8,  r8

    cmp    rdx, 0x0
    je     _end

_loop:
    mov    r8, qword [rsi + rcx]
    mov    byte [rdx + rcx], r8b
    inc    rcx
    cmp    rcx, rdx
    jne    _loop

    mov    rsi, rdx
    xor    rcx, rcx
    mov    rax, rdi

_loop2:
    cmp    rcx, rdx
    je     _end_null
    mov    r8b, byte [rsi + rcx]
    mov    byte [rax + rcx], r8b
    inc    rcx
    jmp    _loop2

_end_null:
    ret

_end:
    mov    rax, rdi
    ret
