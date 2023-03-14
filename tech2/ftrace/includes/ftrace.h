/*
** EPITECH PROJECT, 2022
** ftrace (Workspace)
** File description:
** ftrace
*/

#ifndef FTRACE_H_
    #define FTRACE_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <libelf.h>
    #include <sys/types.h>
    #include <sys/ptrace.h>
    #include <sys/wait.h>
    #include <sys/user.h>

typedef struct user_regs_struct _uss;

/* ___________________________ Utils ___________________________ */

int strace(char *file);

#endif /* !FTRACE_H_ */
