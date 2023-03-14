/*
** EPITECH PROJECT, 2021
** C_PROJECT
** File description:
** q_enqueue
*/

#include <stdlib.h>
#include "queue.h"

int q_enqueue(queue_man_t *q, void *obj)
{
    queue_t *temp;

    if (q_isfull(q))
        return (0);
    if (!(temp = malloc(sizeof(queue_t))))
        return (1);
    temp->obj = obj;
    temp->next = NULL;
    if (q_isempty(q)) {
        q->front = temp;
        q->rear  = temp;
    } else {
        queue_t *mem = q->rear;
        q->rear       = temp;
        q->rear->next = mem;
    }
    q->count++;
    return (0);
}
