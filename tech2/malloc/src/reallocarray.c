/*
** EPITECH PROJECT, 2022
** MyMalloc (Workspace)
** File description:
** reallocarray
*/

#include "my_malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return (realloc(ptr, nmemb * size));
}
