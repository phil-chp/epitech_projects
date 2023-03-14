/*
** EPITECH PROJECT, 2022
** PDG-Rush2 (Workspace)
** File description:
** char
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class base;
    char value;
} CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->value = va_arg(args[0], int);
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

static char *Char_str(CharClass *this)
{
    char *str;

    str = malloc(sizeof(char) * 69);
    if (!str) raise("Out of memory.");
    sprintf(str, "<Char (%c)>", this->value);
    return (str);
}

Object *Char_mul(const CharClass *this, const CharClass *other)
{
    Object *new_char = NULL;

    char value = this->value * other->value;
    new_char = new (Char, value);
    return (new_char);
}

Object *Char_div(const CharClass *this, const CharClass *other)
{
    Object *new_char = NULL;

    if (other->value == 0) raise("Divison by zero.");
    char value = this->value / other->value;
    new_char = new (Char, value);
    return (new_char);
}

Object *Char_add(const CharClass *this, const CharClass *other)
{
    Object *new_char = NULL;

    char value = this->value + other->value;
    new_char = new (Char, value);
    return (new_char);
}

Object *Char_sub(const CharClass *this, const CharClass *other)
{
    Object *new_char = NULL;

    char value = this->value - other->value;
    new_char = new (Char, value);
    return (new_char);
}

bool Char_eq(const CharClass *this, const CharClass *other)
{
    return (this->value == other->value);
}

bool Char_gt(const CharClass *this, const CharClass *other)
{
    return (this->value > other->value);
}

bool Char_lt(const CharClass *this, const CharClass *other)
{
    return (this->value < other->value);
}

static const CharClass _description = {
    {
        /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt,
    },
    .value = 0
};

const Class *Char = (const Class *)&_description;
