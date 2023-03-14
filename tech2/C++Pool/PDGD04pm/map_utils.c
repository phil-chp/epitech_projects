/*
** EPITECH PROJECT, 2022
** PDG-D4-PM (Workspace)
** File description:
** map_utils
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "map.h"

bool map_add_elem(map_t *map_ptr, void *key, void *value,   \
                            key_comparator_t key_cmp)
{
    node_t *temp = *map_ptr;
    pair_t *pair;
    int cmp = 1;

    pair = malloc(sizeof(pair_t));
    if (!pair)
        return (false);
    pair->key   = key;
    pair->value = value;

    for (unsigned int i = 0; temp; temp = temp->next, i++) {
        pair_t *temp_pair = (pair_t *)temp->value;
        if (temp_pair && (cmp = key_cmp(temp_pair->key, key)) == 0) {
            return (list_add_elem_at_position(map_ptr, (void *)pair, i));
        }
    }
    if (cmp != 0) {
        list_add_elem_at_back(map_ptr, (void *)pair);
    }
    return (true);
}

void *map_get_elem(map_t map, void *key, key_comparator_t key_cmp)
{
    node_t *temp = map;

    for (unsigned int i = 0; temp; temp = temp->next, i++) {
        pair_t *temp_pair = (pair_t *)temp->value;
        int cmp = key_cmp(temp_pair->key, key);

        if (cmp == 0 && temp_pair->value != NULL) {
            return (temp_pair->value);
        } else if (cmp == 0 && temp_pair->value == NULL) {
            return (NULL);
        }
    }
    return (NULL);
}

bool map_del_elem(map_t *map_ptr, void *key, key_comparator_t key_cmp)
{
    node_t *temp = *map_ptr;

    for (unsigned int i = 0; temp; temp = temp->next, i++) {
        pair_t *temp_pair = (pair_t *)temp->value;
        int cmp = key_cmp(temp_pair->key, key);

        if (cmp == 0) {
            free(temp_pair);
            temp_pair = NULL;
            return (list_del_elem_at_position(map_ptr, i));
        }
    }
    return (false);
}
