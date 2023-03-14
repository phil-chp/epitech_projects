/*
** EPITECH PROJECT, 2022
** PDG-D5 (Workspace)
** File description:
** ex02
*/

#include "../string.h"

void append_s(string_t *this, const string_t *ap)
{
    if (!this || !ap || !ap->str) return;
    if (this->str) {
        int len = strlen(this->str) + strlen(ap->str) + 1;
        this->str = realloc(this->str, sizeof(char) * len);
        strcat(this->str, ap->str);
    } else {
        this->str = strdup(ap->str);
    }
}

void append_c(string_t *this, const char *ap)
{
    if (!this || !ap) return;
    if (this->str) {
        int len = strlen(this->str) + strlen(ap) + 1;
        this->str = realloc(this->str, sizeof(char) * len);
        strcat(this->str, ap);
    } else {
        this->str = strdup(ap);
    }
}
