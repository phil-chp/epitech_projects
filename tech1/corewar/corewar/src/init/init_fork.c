/*
** EPITECH PROJECT, 2021
** corewar (Workspace)
** File description:
** init_fork
*/

#include "corewar.h"

void init_fork(champs_t *child, champs_t *parent)
{
    champs_t *f_iter;

    child = parent;
    if (!parent->f_head) {
        child->f_next  = NULL;
        child->f_prev  = NULL;
        child->f_head  = child;
        parent->f_head = child;
    } else {
        for (f_iter = parent->f_head; f_iter->next; f_iter = f_iter->next);
        f_iter->next = child;
        child->next = NULL;
        child->prev = f_iter;
        f_iter->head = parent->f_head;
    }
}
