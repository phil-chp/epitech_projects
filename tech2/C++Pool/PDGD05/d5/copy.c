/*
** EPITECH PROJECT, 2022
** PDG-D5 (Workspace)
** File description:
** ex07
*/

#include "../string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    bool has_null_byte = false;
    size_t j = 0;
    size_t len;

    if (!this || !this->str || pos > n) return (0);
    len = strlen(this->str);
    has_null_byte = (pos + n >= len);
    for (size_t i = pos; has_null_byte == true && i < n && i <= len; i++, j++) {
        s[j] = this->str[i];
    }
    return (has_null_byte == false ? 0 : j);
}
