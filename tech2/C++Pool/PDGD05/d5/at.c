/*
** EPITECH PROJECT, 2022
** PDG-D5 (Workspace)
** File description:
** ex03
*/

#include "../string.h"

char at(const string_t *this, size_t pos)
{
    size_t len;

    if (!this || !this->str) return (-1);
    len = strlen(this->str);
    return (pos > len ? -1 : this->str[pos]);
}
