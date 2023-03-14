/*
** EPITECH PROJECT, 2020
** pushswap (Workspace)
** File description:
** Adds a node to the beggining of a linked list
*/

#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

int link_add(sort_t **list, int value)
{
    sort_t *link = malloc(sizeof(*link));
    link->n = value;
    link->next = *list;
    int i = 0;

    if (*list != NULL) {
        sort_t *temp = *list;
        for (; temp->next != *list; temp = temp->next);
        temp->next = link;
        (*list)->prev = link;
    } else {
        link->next = link;
        i = 1;
    }
    *list = link;
    return (i);
}
