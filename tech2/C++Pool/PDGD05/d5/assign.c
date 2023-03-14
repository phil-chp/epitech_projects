/*
** EPITECH PROJECT, 2022
** PDG-D5 (Workspace)
** File description:
** ex01
*/

#include "../string.h"

void assign_s(string_t *this, const string_t *str)
{
    if (!this || !str || !str->str) return;
    if (this->str) free(this->str);
    this->str = strdup(str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (!this || !s) return;
    if (this->str) free(this->str);
    this->str = strdup(s);
}
