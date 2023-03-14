/*
** EPITECH PROJECT, 2022
** strace (Workspace)
** File description:
** utils
*/

#include "strace.h"

void print_usage(char *name)
{
    fprintf(stderr, "USAGE\n\t%s program [-s] [-p <pid>|<command>]\n", name);
}

char *trace_string(strace_t *strace, size_t addr)
{
    size_t i = 0;
    char *str;

    str = (char *)malloc(sizeof(char) * (_MAX_BYTECODE_PRINT + 1));
    if (str == NULL) return (NULL);
    for (; i <= _MAX_BYTECODE_PRINT; ++i) {
        str[i] = ptrace(PTRACE_PEEKDATA, strace->pid, addr + i);
        if (str[i] == -1) return (NULL);
        if (str[i] == '\0') break;
    }
    return (str);
}

void print_bytecode(char *value)
{
    size_t i = 0;

    fprintf(stderr, "\"");
    for (; i < _MAX_BYTECODE_PRINT && value[i] != '\0'; ++i) {
        if (value[i] < 32 || value[i] == 127) {
            fprintf(stderr, "\\%01hhx", value[i]);
        } else {
            fprintf(stderr, "%c", value[i]);
        }
    }
    fprintf(stderr, "\"");
    if (i - 1 == _MAX_BYTECODE_PRINT) {
        fprintf(stderr, "...");
    }
}

void get_params(_uss regs, _llu (*params)[6])
{
    (*params)[0] = regs.rdi;
    (*params)[1] = regs.rsi;
    (*params)[2] = regs.rdx;
    (*params)[3] = regs.rcx;
    (*params)[4] = regs.r8;
    (*params)[5] = regs.r9;
}
