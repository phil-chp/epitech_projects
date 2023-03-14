/*
** EPITECH PROJECT, 2022
** strace (Workspace)
** File description:
** display
*/

#include "strace.h"

static void handle_bytecode(strace_t *strace, _llu params)
{
    char *str;

    str = trace_string(strace, params);
    if (!str) {
        return;
    }
    print_bytecode(str);
    free(str);
}

static void print_param(strace_t *strace, _llu params, size_t arg_type)
{
    if (strace->s == false) {
        fprintf(stderr, "%lld", params);
        return;
    }
    switch (arg_type) {
        case NUM:
            fprintf(stderr, "%lld", params);
            break;
        case STRING:
            handle_bytecode(strace, params);
            break;
        case UNSIGNED:
            fprintf(stderr, "%u", (unsigned)params);
            break;
        default:
            fprintf(stderr, "0x%llx", params);
            break;
    }
}

static int print_return(strace_t *strace, _llu params, _llu syscall)
{
    fprintf(stderr, ") = ");
    if (table[syscall].id == _EXIT_SYSCALL) {
        fprintf(stderr, "?\n+++ exited with %d +++\n", (int)params);
        return (1);
    } else {
        print_param(strace, params, table[syscall].arg_type[0]);
        fprintf(stderr, "\n");
    }
    return (0);
}

int display_contents(strace_t *strace, _llu (*params)[6], _uss regs)
{
    _llu syscall = regs.rax;
    int status;

    fprintf(stderr, "%s(", table[syscall].name);
    for (int i = 0; i != table[syscall].arg_count; i++) {
        if (i != 0) fprintf(stderr, ", ");
        print_param(strace, (*params)[i], table[syscall].arg_type[i]);
    }
    ptrace(PTRACE_SINGLESTEP, strace->pid, 0, 0);
    waitpid(strace->pid, &status, 0);
    ptrace(PTRACE_GETREGS, strace->pid, NULL, &regs);
    return (print_return(strace, (*params)[0], syscall));
}
