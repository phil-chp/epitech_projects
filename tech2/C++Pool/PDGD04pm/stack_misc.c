/*
** EPITECH PROJECT, 2022
** PDG-D4-PM (Workspace)
** File description:
** stack_get
*/

#include "stack.h"

unsigned int stack_get_size(stack_t stack)
{
    return (list_get_size(stack));
}

bool stack_is_empty(stack_t stack)
{
    return (list_is_empty(stack));
}
