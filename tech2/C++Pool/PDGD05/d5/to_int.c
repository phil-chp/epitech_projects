/*
** EPITECH PROJECT, 2022
** PDG-D5 (Workspace)
** File description:
** ex12
*/

#include "../string.h"

int to_int(const string_t *this)
{
    if (!this || !this->str) return (-1);
    for (size_t i = 0; this->str[i]; i++) {
        if (i == 0 && this->str[i] != '-') continue;
        if (this->str[i] < '0' || this->str[i] > '9') return (-1);
    }
    return (atoi(this->str));
}
