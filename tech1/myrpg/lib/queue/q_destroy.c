/*
** EPITECH PROJECT, 2021
** queue_test
** File description:
** q_destroy
*/

#include <stdlib.h>
#include "queue.h"

void q_destroy(queue_man_t *q)
{
    q_flush(q);
    if (q) free(q);
    q = NULL;
}
