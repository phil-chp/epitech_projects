/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "includes/utils.h"
#include "includes/my.h"

void signal_handler(int sig)
{
    if (sig == SIGSEGV) {
        write(2, "mysh: Segmentation fault\n", 26);
        exit(84);
    } else if (sig == SIGINT) {
        write(2, "mysh: Interrupt\n", 17);
        exit(0);
    }
}

static int mysh(char ***cmd, char **env)
{
    int code = SUCCESS_CODE;
    char *get_input;
    char **user_input;

    signal(SIGSEGV, signal_handler);
    signal(SIGINT, signal_handler);
    for (int i[] = {0, 0}; code == SUCCESS_CODE; ) {
        my_putstr("=> ");
        if ((get_input = term_getline()) == NULL) return (ERROR_CODE);
        if ((user_input = my_str_to_word_array(get_input)) == NULL) return (84);
        for (i[0] = 0; i[0] < COMMAND_COUNT && user_input[0]       \
            && my_strcmp(user_input[0], cmd[i[0]][0]) != 0; i[0]++);
        if (i[0] < COMMAND_COUNT)
            env = my_arraydup(handle_command(cmd, user_input, env, i));
        else
            my_lprintf("%s: Command not found.\n", user_input[0]);
        if (!env) code = ERROR_CODE;
        if (user_input) free_array(user_input, my_arraylen(user_input));
    }
    return (code);
}

static int check_for_pipe(char **env, char ***cmd)
{
    char buff[4096];
    char **result;
    int diff = 0;
    int i[] = {0, 1};

    if (isatty(0) == 1) return (EXIT_CODE);
    for (; (i[0] = read(0, buff + diff, 4096 - diff)) > 0; diff += i[0]);
    buff[diff] = '\0';
    if (i[0] < 0 || my_strlen(buff) == 1) return (ERROR_CODE);
    result = my_str_to_word_array(buff);
    for (i[0] = 0; i[0] < COMMAND_COUNT && result[0]       \
        && my_strcmp(result[0], cmd[i[0]][0]) != 0; i[0]++);
    if (i[0] < COMMAND_COUNT)
        handle_command(cmd, result, env, i);
    else
        my_lprintf("%s: Command not found.\n", result[0]);
    return (SUCCESS_CODE);
}

int main(int ac, char **av, char **env)
{
    char ***cmd;
    char **my_env;
    int return_code = 2;

    if (av && ac != 1) return (ERROR_CODE);
    if ((cmd = get_commands()) == NULL) return (ERROR_CODE);
    return_code = check_for_pipe(env, cmd);
    if (return_code == 84 || return_code == 0) return (return_code);
    my_env = my_arraydup(env);
    if ((return_code = mysh(cmd, my_env)) == 84) return (ERROR_CODE);
    if (return_code == 1) return (SUCCESS_CODE);
    if (cmd) free_dictionary(cmd, COMMAND_COUNT);
    if (env) free_array(env, my_arraylen(env));
    return (SUCCESS_CODE);
}
