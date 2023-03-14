/*
** EPITECH PROJECT, 2020
** navy (Workspace)
** File description:
** deterline
*/

#include "../lib.h"

int deterline(plan_t *plan)
{
    int count = 0;

    for (int i = 0; plan->buff[i]; i++)
        if (plan->buff[i] == '\n')
            count++;
    return (count);
}
