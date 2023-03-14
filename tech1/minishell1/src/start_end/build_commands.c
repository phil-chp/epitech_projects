/*
** EPITECH PROJECT, 2021
** minishell1 (Workspace)
** File description:
** build_commands
*/

#include <stdlib.h>
#include "../includes/utils.h"

static char ***set_variables(char ***cmd)
{
    (cmd) && (cmd[0][0] = "ls",       cmd[0][1] = "/bin/ls",  0);
    (cmd) && (cmd[1][0] = "env",      cmd[1][1] = "\0",       0);
    (cmd) && (cmd[2][0] = "cd",       cmd[2][1] = "\0",       0);
    (cmd) && (cmd[3][0] = "exit",     cmd[3][1] = "\0",       0);
    (cmd) && (cmd[4][0] = "pwd",      cmd[4][1] = "/bin/pwd", 0);
    (cmd) && (cmd[5][0] = "setenv",   cmd[5][1] = "\0",       0);
    (cmd) && (cmd[6][0] = "unsetenv", cmd[6][1] = "\0",       0);
    return (cmd);
}

char ***get_commands(void)
{
    char ***cmd;

    cmd = malloc(sizeof(char **) * COMMAND_COUNT);
    if (!cmd) return (NULL);
    for (int i = 0; i < COMMAND_COUNT; i++) {
        cmd[i] = malloc(sizeof(char **) * 2);
        if (!cmd[i]) return (NULL);
    }
    cmd = set_variables(cmd);
    return (cmd);
}
