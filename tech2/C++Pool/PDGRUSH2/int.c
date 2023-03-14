/*
** EPITECH PROJECT, 2022
** PDG-Rush2 (Workspace)
** File description:
** int
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "int.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     value;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->value = va_arg(args[0], int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

static char *Int_str(IntClass *this)
{
    char *str;

    str = malloc(sizeof(char) * 69);
    if (!str) raise("Out of memory.");
    sprintf(str, "<Int (%d)>", this->value);
    return (str);
}


Object *Int_mul(const IntClass *this, const IntClass *other)
{
    Object *new_int = NULL;

    int value = this->value * other->value;
    new_int = new(Int, value);
    return (new_int);
}

Object *Int_div(const IntClass *this, const IntClass *other)
{
    Object *new_int = NULL;

    if (other->value == 0) raise("Divison by zero");
    int value = this->value / other->value;
    new_int = new(Int, value);
    return (new_int);
}

Object *Int_add(const IntClass *this, const IntClass *other)
{
    Object *new_int = NULL;

    int value = this->value + other->value;
    new_int = new(Int, value);
    return (new_int);
}

Object *Int_sub(const IntClass *this, const IntClass *other)
{
    Object *new_int = NULL;

    int value = this->value - other->value;
    new_int = new(Int, value);
    return (new_int);
}

bool Int_eq(const IntClass *this, const IntClass *other)
{
    return (this->value == other->value);
}

bool Int_gt(const IntClass *this, const IntClass *other)
{
    return (this->value > other->value);
}

bool Int_lt(const IntClass *this, const IntClass *other)
{
    return (this->value < other->value);
}

static const IntClass _description = {
    {
        /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt,
    },
    .value = 0};

const Class *Int = (const Class *)&_description;
