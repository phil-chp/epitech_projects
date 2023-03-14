/*
** EPITECH PROJECT, 2022
** strace (Workspace)
** File description:
** child
*/

#include "strace.h"
#include "my.h"

static bool get_args(char **av, char ***args, int arg_count)
{
    size_t k = 0;

    for (int i = 0; i < arg_count + 1 && av[i]; ++i) {
        if (my_strcmp(av[i], "-p") == 0) {
            if (i == arg_count) return (false);
            ++i;
        } else if (my_strcmp(av[i], "-s") != 0) {
            (*args)[k++] = my_strdup(av[i]);
        }
    }
    (*args)[k] = NULL;
    return (true);
}

size_t handle_child(strace_t *strace, int ac, char **av, char **env)
{
    int arg_count;
    char **args;

    arg_count = (ac - 1) - (1 * strace->s) - (2 * strace->p);
    args = (char **)malloc(sizeof(char *) * (arg_count + 1));
    if (!get_args(av, &args, arg_count)) return (_ERROR_CODE);
    ptrace(PTRACE_TRACEME, 0, NULL, NULL);
    if (execve(args[0], args, env) == -1) {
        perror("execve");
    }
    return (_ERROR_CODE);
}
