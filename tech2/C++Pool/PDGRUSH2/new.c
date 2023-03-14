/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 01
*/

#include <stdlib.h>
#include "new.h"
#include "player.h"

Object *new(const Class *class, ...)
{
    va_list args;
    Object *obj;

    va_start(args, class);
    obj = va_new(class, &args);
    va_end(args);
    return (obj);
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *my_obj = malloc(class->__size__);

    if (!my_obj) raise("Out of memory.");
    memcpy(my_obj, class, class->__size__);
    if (((Class *)my_obj)->__ctor__)
        ((Class *)my_obj)->__ctor__(my_obj, ap);
    return (my_obj);
}

void delete(Object *ptr)
{
    if (ptr != NULL) {
        if (((Class *)ptr)->__dtor__)
            ((Class *)ptr)->__dtor__(ptr);
        free(ptr);
    }
}
