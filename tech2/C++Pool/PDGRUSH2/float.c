/*
** EPITECH PROJECT, 2022
** PDG-Rush2 (Workspace)
** File description:
** float
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "float.h"
#include "new.h"

typedef struct
{
    Class base;
    float value;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->value = (float)va_arg(args[0], double);
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

static char *Float_str(FloatClass *this)
{
    char *str;

    str = malloc(sizeof(char) * 69);
    if (!str) raise("Out of memory.");
    sprintf(str, "<Float (%f)>", this->value);
    return (str);
}

Object *Float_add(const FloatClass *this, const FloatClass *other)
{
    Object *new_float = NULL;

    float value = this->value + other->value;
    new_float = new(Float, value);
    return (new_float);
}

Object *Float_sub(const FloatClass *this, const FloatClass *other)
{
    Object *new_float = NULL;

    float value = this->value - other->value;
    new_float = new(Float, value);
    return (new_float);
}

Object *Float_mul(const FloatClass *this, const FloatClass *other)
{
    Object *new_float = NULL;

    float value = this->value * other->value;
    new_float = new(Float, value);
    return (new_float);
}

Object *Float_div(const FloatClass *this, const FloatClass *other)
{
    Object *new_float = NULL;

    if (other->value == 0) raise("Divison by zero.");
    float value = this->value / other->value;
    new_float = new(Float, value);
    return (new_float);
}

bool Float_eq(const FloatClass *this, const FloatClass *other)
{
    return (this->value == other->value);
}

bool Float_gt(const FloatClass *this, const FloatClass *other)
{
    return (this->value > other->value);
}

bool Float_lt(const FloatClass *this, const FloatClass *other)
{
    return (this->value < other->value);
}

static const FloatClass _description = {
    {
        /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt,
    },
    .value = 0.0f
};

const Class *Float = (const Class *)&_description;
