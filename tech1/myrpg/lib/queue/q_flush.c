/*
** EPITECH PROJECT, 2021
** queue_test
** File description:
** q_flush
*/

#include "queue.h"

void q_flush(queue_man_t *q)
{
    for (int i = 0; !q_isempty(q); i++)
        q_dequeue(q);
}
