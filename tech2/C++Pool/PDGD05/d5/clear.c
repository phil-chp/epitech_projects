/*
** EPITECH PROJECT, 2022
** PDG-D5 (Workspace)
** File description:
** ex04
*/

#include "../string.h"

void clear(string_t *this)
{
    if (!this) return;
    if (this->str) {
        free(this->str);
        this->str = NULL;
    }
}
