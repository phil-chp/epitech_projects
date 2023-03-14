/*
** EPITECH PROJECT, 2021
** minishell1 (Workspace)
** File description:
** free_handling
*/

#include <stdlib.h>
#include "../includes/utils.h"
#include "../includes/my.h"

void free_array(char **array, int count)
{
    for (int i = 0; i < count; i++)
        if (array[i]) free(array[i]);
    if (array) free(array);
}

void free_dictionary(char ***dict, int count)
{
    for (int i = 0; i < count; i++)
        if (dict[i]) free(dict[i]);
    if (dict) free(dict);
}

void final_free(char ***cmd, char **user_input)
{
    if (!cmd) free_dictionary(cmd, COMMAND_COUNT);
    if (!user_input) free_array(user_input, my_arraylen(user_input));
}
