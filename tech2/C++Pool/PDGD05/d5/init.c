/*
** EPITECH PROJECT, 2022
** PDG-D5 (Workspace)
** File description:
** string
*/

#include "../string.h"

void string_init_bis(string_t *this)
{
    (void)this;
}

void string_init(string_t *this, const char *s)
{
    if (!this) return;
    this->str = (s ? strdup(s) : NULL);
    this->assign_c = &assign_c;
    this->assign_s = &assign_s;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at;
    this->clear = &clear;
    this->length = &length;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_s = &find_s;
    this->find_c = &find_c;
    this->insert_s = &insert_s;
    this->insert_c = &insert_c;
    this->to_int = &to_int;
    string_init_bis(this);
}

void string_destroy(string_t *this)
{
    if (!this) return;
    if (this->str) free(this->str);
}
