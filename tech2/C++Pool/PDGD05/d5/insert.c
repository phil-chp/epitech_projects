/*
** EPITECH PROJECT, 2022
** PDG-D5 (Workspace)
** File description:
** ex11
*/

#include "../string.h"

void insert_c(string_t *this, size_t pos, const char *str)
{
    size_t i = pos;
    size_t len_t;
    size_t len_s;

    if (!this || !str || !this->str) return;
    len_t = strlen(this->str);
    len_s = strlen(str);
    if (pos > len_t) {
        this->str = realloc(this->str, sizeof(char) * (len_t + len_s + 1));
        this->str = strcat(this->str, str);
        return;
    }
    if (len_s + pos > len_t) {
        this->str = realloc(this->str, sizeof(char) * (pos + len_s + 1));
    }
    for (size_t j = 0; i < len_s + pos; i++, j++) {
        this->str[i] = str[j];
    }
    this->str[i] = '\0';
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    size_t i = pos;
    size_t len_t;
    size_t len_s;

    if (!this || !str || !this->str || !str->str) return;
    len_t = strlen(this->str);
    len_s = strlen(str->str);
    if (pos > len_t) {
        this->str = realloc(this->str, sizeof(char) * (len_t + len_s + 1));
        this->str = strcat(this->str, str->str);
        return;
    }
    if (len_s + pos > len_t) {
        this->str = realloc(this->str, sizeof(char) * (pos + len_s + 1));
    }
    for (size_t j = 0; i < len_s + pos; i++, j++) {
        this->str[i] = str->str[j];
    }
    this->str[i] = '\0';
}
