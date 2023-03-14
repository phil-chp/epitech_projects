/*
** EPITECH PROJECT, 2022
** MyMalloc (Workspace)
** File description:
** globals
*/

#include "my_malloc.h"

// Points to the first element in the heap accross calls.
metadata_t *_head = NULL;

// Stores the size of the heap accross calls.
size_t _heap_size = 0;
