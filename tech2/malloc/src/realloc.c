/*
** EPITECH PROJECT, 2022
** MyMalloc (Workspace)
** File description:
** realloc
*/

#include "my_malloc.h"

static int check_size(metadata_t *metadata, size_t new_size)
{
    size_t current_size;

    if (!metadata) {
        return (1);
    }
    current_size = metadata->size;
    return (new_size >= current_size);
}

static void *handle_realloc(void *ptr, size_t size)
{
    metadata_t *metadata;
    void *new_ptr;

    metadata = (metadata_t *)((size_t)ptr - METADATA_SIZE);
    if (check_size(metadata, size) == 0) {
        return (ptr);
    }
    new_ptr = malloc(size);
    if (!new_ptr) {
        return (NULL);
    }
    memcpy(new_ptr, ptr, size);
    free(ptr);
    return (new_ptr);
}

void *realloc(void *ptr, size_t size)
{
    if (ptr == NULL) {
        return (malloc(size));
    } else if (size == 0) {
        free(ptr);
        return (NULL);
    }
    return (handle_realloc(ptr, size));
}
