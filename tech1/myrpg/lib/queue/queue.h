/*
** EPITECH PROJECT, 2021
** libqueue
** File description:
** libqueue header file
*/

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stddef.h>

typedef struct queue_s {
    void *obj;
    struct queue_s *next;
} queue_t;

typedef struct queue_man_s {
    int count;
    int max;
    queue_t *front, *rear;
} queue_man_t;

// - - - Queue prototypes - - - //

queue_man_t *q_initialize(int max);

int   q_enqueue(queue_man_t *q, void *obj);
void *q_dequeue(queue_man_t *q);

int   q_isempty(queue_man_t *q);
int   q_isfull(queue_man_t *q);

void  q_flush(queue_man_t *q);
void  q_destroy(queue_man_t *q);

// - - - - - - -  - - - - - - - //

#endif /* QUEUE_H_ */
