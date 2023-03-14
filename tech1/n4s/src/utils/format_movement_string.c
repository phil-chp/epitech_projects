/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** format_movement_string
*/

#include <stdlib.h>
#include "ai.h"
#include "my.h"

bool format_movement_string(char *parameter, float value)
{
    char *value_str;
    char *temp;
    char *res;

    gcvt(value, 1, value_str);
    if (!(temp = my_strcat_malloc(value_str, "\n\0"))) return (1);
    if (!(res = my_strcat_malloc(parameter, temp)))  return (1);
    my_putstr(res);
    free (value_str);
    free (temp);
    free (res);
    return (0);
}
