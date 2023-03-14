/*
** EPITECH PROJECT, 2022
** PDG-D5 (Workspace)
** File description:
** ex05
*/

#include "../string.h"

int length(const string_t *this)
{
    if (this && this->str) {
        return (strlen(this->str));
    }
    return (0);
}
