/*
** EPITECH PROJECT, 2022
** MyMalloc (Workspace)
** File description:
** free
*/

#include "my_malloc.h"

static char verify_metadata(metadata_t *metadata)
{
    for (metadata_t *temp = _head; temp->next; temp = temp->next) {
        if ((void *)temp == (void *)metadata) {
            return (1);
        }
    }
    return (0);
}

static void merge_metadata(void)
{
    metadata_t *temp;

    temp = _head;

    while (temp->next) {
        if (temp->state + temp->next->state == 0) {
            temp->size += temp->next->size + sizeof(metadata_t);
            temp->next = temp->next->next;
            continue;
        }
        temp = temp->next;
    }
}

void free(void *ptr)
{
    metadata_t *metadata = NULL;

    if (ptr == NULL) {
        return;
    }
    metadata = ptr - 24;
    if (verify_metadata(metadata) == 0) {
        return;
    }
    metadata->state = FREE;
    merge_metadata();
}
