/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class base;
    int x, y;
} PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(args[0], int);
    this->y = va_arg(args[0], int);
}

static void Point_dtor(PointClass *this)
{
    (void)this;
}

static char *Point_str(PointClass *this)
{
    char *str;

    if (!this) raise("Object doesn't exist");
    str = malloc(sizeof(char) * 69);
    if (!str) raise("Out of memory.");
    sprintf(str, "<Point (%d, %d)>", this->x, this->y);
    return (str);
}

Object *Point_add(const PointClass *this, const PointClass *other)
{
    Object *new_point = NULL;

    int x = this->x + other->x;
    int y = this->y + other->y;
    new_point = new(Point, x, y);
    return (new_point);
}

Object *Point_sub(const PointClass *this, const PointClass *other)
{
    Object *new_point = NULL;

    int x = this->x - other->x;
    int y = this->y - other->y;
    new_point = new(Point, x, y);
    return (new_point);
}

static const PointClass _description = {
    { /* Class struct */
     .__size__ = sizeof(PointClass),
     .__name__ = "Point",
     .__ctor__ = (ctor_t)&Point_ctor,
     .__dtor__ = (dtor_t)&Point_dtor,
     .__str__ = (to_string_t)&Point_str,
     .__add__ = (binary_operator_t)&Point_add,
     .__sub__ = (binary_operator_t)&Point_sub,
     .__mul__ = NULL,
     .__div__ = NULL,
     .__eq__ = NULL,
     .__gt__ = NULL,
     .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;
