/*
** EPITECH PROJECT, 2021
** minishell1 (Workspace)
** File description:
** command_handling
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/utils.h"
#include "../includes/my.h"

static void handle_child_process(char ***cmd, char **user_input,   \
                                    char **env, int *i)
{
    if (i[0] == 2 || i[0] == 5 || i[0] == 6) {
        (i[1] == 0) && (exit(0), 0);
        return;
    }
    if (user_input[0] != NULL) {
        if (i[0] == 1) {
            my_lprintf("%t", env);
            (i[1] == 0) && (exit(0), 0);
            return;
        } else if (i[0] == 3) {
            final_free(cmd, user_input);
            (i[1] == 0) && (exit(0), 0);
            return;
        }
        if (execve(cmd[i[0]][1], user_input, env) == -1) {
            (i[1] == 0) && (exit(84), 0);
            return;
        }
    }
}

int handle_cd(char **user_input, char **env)
{
    int len = my_arraylen(user_input);
    if (len == 1) {
        char *s_home = my_strdup("HOME=");
        char *home;
        if (!s_home) return (ERROR_CODE);
        for (int i = 0; env[i] && home; i++)
            for (int j = 0; home && env[i][j] && env[i][j] == s_home[j]; j++)
                if (env[i][j] == '=') home = my_getenv(env[i], j + 1);
        if (!s_home) free(s_home);
        if (!home) return (ERROR_CODE);
        len = chdir(home);
        if (!home) free(home);
        if (len == -1) return (ERROR_CODE);
    } else if (len == 2) {
        if (chdir(user_input[len - 1]) == -1)
            perror(my_strcat(user_input[1], ": No such file or director.\n"));
    } else
        write(2, "cd: Too many arguments.\n", 25);
    return (SUCCESS_CODE);
}

char **handle_command(char ***cmd, char **user_input,   \
                        char **env, int *i)
{
    int pid = -2;

    if (i[1] == 0)
        if ((pid = fork()) == -1) return (NULL);
    if (pid == 0) {
        handle_child_process(cmd, user_input, env, i);
    } else {
        if (i[1] == 1) handle_child_process(cmd, user_input, env, i);
        if (i[1] == 0) wait(NULL);
        if (i[0] == 2 && handle_cd(user_input, env) == -1)
            return (NULL);
        (i[0] == 3) && (final_free(cmd, user_input), exit(0), 0);
        char **temp = (i[0] == 5) ? (handle_env(env, user_input[1], 0)) : \
        (i[0] == 6) ? (handle_env(env, user_input[1], 1)) : (env);
        if (!env) free_array(env, my_arraylen(env));
        return (temp);
    }
    return (env);
}
