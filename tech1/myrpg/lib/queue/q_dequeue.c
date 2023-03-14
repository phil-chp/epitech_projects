/*
** EPITECH PROJECT, 2021
** C_PROJECT
** File description:
** q_dequeue
*/

#include <stdlib.h>
#include "queue.h"

void *q_dequeue(queue_man_t *q)
{
    void *obj;
    queue_t *temp;
    queue_t *mem;

    obj = q->front->obj;
    temp = q->front;
    mem = q->rear;
    q->count--;
    for (int i = 0; i < q->count - 1; i++, mem = mem->next);
    mem->next = NULL;
    q->front = mem;
    if (q->count == 0) {
        q->rear = NULL;
        q->front = NULL;
    }
    if (temp) free(temp);
    temp = NULL;
    return (obj);
}
