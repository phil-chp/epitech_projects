/*
** EPITECH PROJECT, 2021
** C_PROJECT
** File description:
** q_isempty
*/

#include "queue.h"

int q_isempty(queue_man_t *q)
{
    return (!q->rear);
}
