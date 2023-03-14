/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** free_lidar_type
*/

#include <stdlib.h>
#include "ai.h"

void free_lidar_values(int **values)
{
    if (*values) free(*values);
}
