/*
** EPITECH PROJECT, 2020
** Secure Zero
** File description:
** Adds a security, in every case it is best
** to add a "0+" in front of our expression
*/

#include "eval_expr_struct.h"

void secure_zero(t_eval *eval)
{
    eval->temp[0] = "0\0";
    eval->temp[1] = "+\0";
    return;
}
