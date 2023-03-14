/*
** EPITECH PROJECT, 2022
** PDG-D5 (Workspace)
** File description:
** ex06
*/

#include "../string.h"

int compare_s(const string_t *this, const string_t *str)
{
    if (!this || !str) return (0);
    if (!this->str) return (-1);
    if (!str->str) return (1);
    return (strcmp(this->str, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    if (!this) return (0);
    if (!this->str && !str) return (0);
    if (!this->str) return (-1);
    if (!str) return (1);
    return (strcmp(this->str, str));
}
