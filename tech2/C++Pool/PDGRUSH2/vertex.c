/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(args[0], int);
    this->y = va_arg(args[0], int);
    this->z = va_arg(args[0], int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

static char *Vertex_str(VertexClass *this)
{
    char *str;

    str = malloc(sizeof(char) * 69);
    if (!str) raise("Out of memory.");
    sprintf(str, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return (str);
}

Object *Vertex_add(const VertexClass *this, const VertexClass *other)
{
    Object *new_vertex = NULL;

    int x = this->x + other->x;
    int y = this->y + other->y;
    int z = this->z + other->z;
    new_vertex = new(Vertex, x, y, z);
    return (new_vertex);
}

Object *Vertex_sub(const VertexClass *this, const VertexClass *other)
{
    Object *new_vertex = NULL;

    int x = this->x - other->x;
    int y = this->y - other->y;
    int z = this->z - other->z;
    new_vertex = new(Vertex, x, y, z);
    return (new_vertex);
}

static const VertexClass _description = {
    { /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;
