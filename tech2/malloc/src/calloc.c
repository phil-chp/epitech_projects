/*
** EPITECH PROJECT, 2022
** MyMalloc (Workspace)
** File description:
** calloc
*/

#include "my_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *ptr;

    if (nmemb == 0 || size == 0)
        return (NULL);
    ptr = malloc(nmemb * size);
    for (size_t i = 0; i < size; ++i) {
        ((char *)ptr)[i] = 0;
    }
    return (ptr);
}
