/*
** EPITECH PROJECT, 2022
** PDG-D5 (Workspace)
** File description:
** ex10
*/

#include "../string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    size_t i = pos;
    size_t len_t;
    size_t len_s;

    if (!this || !str || !this->str || !str->str) return (-1);
    len_t = strlen(this->str);
    len_s = strlen(str->str);
    if (pos > len_t) return (-1);
    for (size_t j = 0; i < len_t; i++) {
        for (; j < len_s && i < len_t && this->str[i] == str->str[j]; i++, j++);
    }
    return (i - len_s - 1);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    size_t i = pos;
    size_t len_t;
    size_t len_s;

    if (!this || !str || !this->str) return (-1);
    len_t = strlen(this->str);
    len_s = strlen(str);
    if (pos > len_t) return (-1);
    for (size_t j = 0; i < len_t; i++) {
        for (; j < len_s && i < len_t && this->str[i] == str[j]; i++, j++);
    }
    return (i - len_s - 1);
}
