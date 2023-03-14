
; EPITECH PROJECT, 2022
; MiniLibC
; File description:
; strlen


bits 64
section .text
global memset
; void *memset(void *s, int c, size_t n);

memset:
    xor    rax, rax
    xor    rcx, rcx
    mov    rax, rdi

    cmp    rdi, 0
    je     _end

_loop:
    cmp    rcx, rdx
    je     _end
    mov    byte[rax + rcx], sil
    inc    rcx
    jmp    _loop

_end:
    ret
