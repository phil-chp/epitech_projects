/*
** EPITECH PROJECT, 2022
** PDG-D5 (Workspace)
** File description:
** ex08
*/

#include "../string.h"

const char *c_str(const string_t *this)
{
    char *str = NULL;

    if (!this || !this->str) return (NULL);
    str = strdup(this->str);
    return (str);
}
