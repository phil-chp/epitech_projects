/*
** EPITECH PROJECT, 2022
** PDG-Rush2 (Workspace)
** File description:
** ex04
*/

#include <stdio.h>
#include "new.h"
#include "point.h"
#include "float.h"
#include "char.h"
#include "int.h"

int main(void)
{
    Object *a = new(Float, 0.875821);
    Object *b = new(Float, 2.130386);

    printf ("%s - %s = %s\n", str(a), str(b), str(subtraction(a, b)));
    printf ("%s - %s = %s\n", str(b), str(a), str(subtraction(b, a)));

    delete(a);
    delete(b);
    return (0);
}
