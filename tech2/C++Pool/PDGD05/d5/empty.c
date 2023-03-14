/*
** EPITECH PROJECT, 2022
** PDG-D5 (Workspace)
** File description:
** ex09
*/

#include "../string.h"

int empty(const string_t *this)
{
    if (!this || !this->str || strlen(this->str) != 0) return (1);
    return (0);
}
