;
; EPITECH PROJECT, 2022
; MiniLibC
; File description:
; strlen
;

bits 64
section .text
global memcpy
; void *memcpy(void *dest, const void *src, size_t n);

memcpy:
    xor    rax, rax
    xor    rcx, rcx

    cmp    rdi, 0
    je     _end
    cmp    rsi, 0
    je     _end

_loop:
    cmp    rcx, rdx
    je     _end
    mov    r8b, byte[rsi + rcx] ; You can apparently bypass these two by using
    mov    byte[rdi + rcx], r8b ; movzx instead. Couldn't make it work though :/
    inc    rcx                  ; Ref: https://stackoverflow.com/q/22621340/
    jmp    _loop

_end:
    mov    rax, rdi
    ret
