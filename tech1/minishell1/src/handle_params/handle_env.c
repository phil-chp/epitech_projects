/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** handle_env
*/

#include <stdlib.h>
#include <unistd.h>
#include "../includes/utils.h"
#include "../includes/my.h"

static char *get_name_from_var(char *user_input, int *mode)
{
    int j, i, len;
    char *name, *value;

    len = my_strlen(user_input);
    for (i = 0; user_input[i] && user_input[i] != '='; i++);
    if (i == len || user_input[i + 1] == user_input[len] || i == 0) {
        (*mode == 0) && (write(2, "setenv: Bad arguements.\n", 25),     \
                                                            *mode = -1, 0);
        return (user_input);
    }
    if (*mode == 0) value = my_getenv(user_input, i);
    name = malloc(sizeof(char) * (++i + 1));
    if (!name) return (NULL);
    for (j = 0; j < i - 1; j++)
        name[j] = user_input[j];
    name[j] = '\0';
    name = my_strupcase(name);
    if (*mode == 0) name = my_strdup(my_strcat(name, value));
    return (name);
}

static char **my_setenv(char **env, char *user_input)
{
    char **temp;
    int i;

    i = my_arraylen(env);
    temp = malloc(sizeof(char *) * (i + 1));
    if (!temp) return (NULL);
    for (int j = 0; j < i; j++)
        temp[j] = my_strdup(env[j]);
    if (!env) free_array(env, my_arraylen(env));
    temp[i] = user_input;
    temp[i + 1] = NULL;
    return (temp);
}

static char **my_unsetenv(char **env, char *name)
{
    int len, i = 0;

    len = my_strlen(name);
    for (int j = 0; len != -1 && env[i]; i++) {
        for (j = 0; len != -1 && j < len; j++)
            (env[i] && env[i][j] != name[j]) && (j = 0, i++, 0);
        (j == len) && (len = -1);
    }
    if (len == - 1) {
        int k = i - 1;
        for (; env[i]; k++, i++)
            env[k] = env[i];
        env[k] = NULL;
    }
    return (env);
}

char **handle_env(char **env, char *user_input, int mode)
{
    char **my_env = NULL;
    char *name;

    if (!user_input) return (env);
    if ((name = get_name_from_var(user_input, &mode)) == NULL) return (NULL);
    if (mode == 0)
        my_env = my_setenv(env, name);
    else if (mode == 1)
        my_env = my_unsetenv(env, name);
    if (!name) free(name);
    if (mode == -1) return (env);
    return (my_env);
}
