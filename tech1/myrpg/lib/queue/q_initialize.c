/*
** EPITECH PROJECT, 2021
** C_PROJECT
** File description:
** q_initialize
*/

#include <stdlib.h>
#include "queue.h"

queue_man_t *q_initialize(int max)
{
    queue_man_t *q;

    if (!(q = malloc(sizeof(queue_man_t))))
        return (NULL);
    q->front = NULL;
    q->rear  = NULL;
    q->max   = max;
    q->count = 0;
    return (q);
}
