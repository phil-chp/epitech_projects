/*
** EPITECH PROJECT, 2022
** strace (Workspace)
** File description:
** strace
*/

#ifndef STRACE_H_
    #define STRACE_H_

// ------------------- Includes ------------------- //

    #include <sys/types.h>
    #include <sys/ptrace.h>
    #include <sys/resource.h>
    #include <sys/types.h>
    #include <sys/time.h>
    #include <sys/user.h>
    #include <sys/wait.h>
    #include <sys/reg.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <stdio.h>

    #include "syscall.h"

// ------------------- Defines -------------------- //

    #define _ERROR_CODE     84
    #define _SUCCESS_CODE   0

    #define _LONG_ORIG_RAX  (sizeof(long) * ORIG_RAX)
    #define _LONG_RAX       (sizeof(long) * RAX)

    #define _MAX_BYTECODE_PRINT  32

    #define _EXIT_SYSCALL        231

typedef long long unsigned _llu;
typedef struct user_regs_struct _uss;

// ------------------ Structures ------------------ //

typedef struct strace_s {
    bool  s;
    bool  p;
    pid_t pid;
} strace_t;

// ----------------- Definitions ------------------ //

// ---> child
size_t handle_child(strace_t *strace, int ac, char **av, char **env);

// ---> display
int display_contents(strace_t *strace, _llu (*params)[6], _uss regs);

// ---> utils
void print_usage(char *name);
char *trace_string(strace_t *strace, size_t addr);
void print_bytecode(char *value);
void get_params(_uss regs, _llu (*params)[6]);

#endif /* !STRACE_H_ */
