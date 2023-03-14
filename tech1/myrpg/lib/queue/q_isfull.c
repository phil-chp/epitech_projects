/*
** EPITECH PROJECT, 2021
** C_PROJECT
** File description:
** q_isfull
*/

#include "queue.h"

int q_isfull(queue_man_t *q)
{
    return (q->max > 0 && q->count >= q->max);
}
