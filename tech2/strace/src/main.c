/*
** EPITECH PROJECT, 2022
** strace (Workspace)
** File description:
** main
*/

#include "strace.h"
#include "my.h"

static size_t trace(strace_t *strace)
{
    _llu params[6];
    size_t opcode;
    int status;
    _uss regs;

    while (true) {
        waitpid(strace->pid, &status, 0);
        if (WIFEXITED(status)) break;
        ptrace(PTRACE_GETREGS, strace->pid, NULL, &regs);
        opcode = ptrace(PTRACE_PEEKTEXT, strace->pid, regs.rip, NULL);
        if ((opcode & 0xFFFF) == 0x050F) {
            get_params(regs, &params);
            if (display_contents(strace, &params, regs) == 1) break;
        }
        if (WIFEXITED(status)) break;
        ptrace(PTRACE_SINGLESTEP, strace->pid, 0, 0);
    }
    return (0);
}

static bool init_strace(strace_t *strace, int ac, char **av)
{
    for (int i = 0; i < ac; ++i) {
        if (my_strcmp(av[i], "-p") == 0) {
            strace->p = true;
            if (!av[i + 1]) return (false);
            strace->pid = my_getnbr(av[i + 1]);
            if (strace->pid == -1) continue;
        } else if (my_strcmp(av[i], "-s") == 0) {
            strace->s = true;
        }
    }
    if (!strace->p) {
        strace->pid = fork();
    } else if (strace->pid < 0) {
        return (false);
    }
    return (strace->pid != -1);
}

int main(int ac, char **av, char **env)
{
    strace_t strace = { false, false, (pid_t)0 };

    if (ac < 2) {
        print_usage(av[0]);
        return (_ERROR_CODE);
    }
    if (!init_strace(&strace, ac, av)) {
        return (_ERROR_CODE);
    }
    if (strace.pid == 0 && !strace.p) {
        return (handle_child(&strace, ac, av + 1, env));
    } else {
        return (trace(&strace));
    }
}
