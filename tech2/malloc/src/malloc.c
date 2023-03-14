/*
** EPITECH PROJECT, 2022
** MyMalloc (Workspace)
** File description:
** malloc
*/

#include "my_malloc.h"

static void init_heap(size_t size)
{
    size_t blocks = 2;

    while (size + sizeof(metadata_t) * 2 > blocks * PAGE_SIZE) {
        blocks += 2;
    }
    _head = sbrk(0 + (PAGE_SIZE * blocks));
    _heap_size = (PAGE_SIZE * blocks);
}

static void *init_metadata(size_t size)
{
    metadata_t *metadata = NULL;

    metadata = ((void *)_head + sizeof(metadata_t) + size);
    _head->state = USED;
    _head->size  = size;
    _head->next  = metadata;
    metadata->state = FREE;
    metadata->size  = _heap_size - sizeof(metadata_t) * 2 - size;
    metadata->next  = NULL;
    return ((void *)((size_t)_head + sizeof(metadata_t)));
}

static void expand_heap(size_t content_of_heap, size_t size)
{
    size_t blocks = 2;

    while (size + sizeof(metadata_t) > content_of_heap - blocks * PAGE_SIZE) {
        blocks += 2;
    }
    printf("%d\n", (PAGE_SIZE * blocks));
    sbrk(0 + (PAGE_SIZE * blocks));
    _heap_size = (PAGE_SIZE * blocks);
}

static void *expand_metadata(size_t size)
{
    metadata_t *metadata = NULL;
    metadata_t *temp = _head;
    size_t content_of_heap;

    for (; temp->next; temp = temp->next) {
        if (temp->state == FREE && temp->size >= size) break;
    }
    metadata = ((void *)temp + sizeof(metadata_t) + size);
    content_of_heap =   \
        (size_t)((void *)metadata - (void *)_head + sizeof(metadata_t));
    if (temp->size < size || content_of_heap > _heap_size) {
        expand_heap(content_of_heap, size);
    }
    temp->state = USED;
    temp->size =  size;
    temp->next =  metadata;
    metadata->state = FREE;
    metadata->size =  _heap_size - content_of_heap;
    metadata->next =  NULL;
    return ((void *)((size_t)temp + sizeof(metadata_t)));
}

void *malloc(size_t size)
{
    void *ptr = NULL;

    if (size == 0)
        return (NULL);
    if (!_head) {
        init_heap(size);
        ptr = init_metadata(size);
    } else {
        ptr = expand_metadata(size);
    }
    return (ptr);
}
