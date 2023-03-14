/*
** EPITECH PROJECT, 2022
** PDG-D4-PM (Workspace)
** File description:
** queue_misc
*/

#include "queue.h"

unsigned int queue_get_size(queue_t queue)
{
    return (list_get_size(queue));
}

bool queue_is_empty(queue_t queue)
{
    return (list_is_empty(queue));
}
