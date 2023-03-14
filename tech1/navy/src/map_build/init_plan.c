/*
** EPITECH PROJECT, 2020
** navy (Workspace)
** File description:
** init_plan
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "../lib.h"

plan_t *init_plan(int n)
{
    plan_t *plan = malloc(sizeof(*plan));
    if (plan == NULL)
        return (NULL);
    if (n == 0)
        plan->pid1 = getpid();
    else
        plan->pid2 = getpid();
    plan->end = 0;
    return (plan);
}
