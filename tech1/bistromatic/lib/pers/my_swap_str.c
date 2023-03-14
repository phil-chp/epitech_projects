/*
** EPITECH PROJECT, 2020
** My_Swap_Str
** File description:
** Swaps Two Strings Using Pointers :
** > my_swap_str(&str1, &str2);
** Values of both strings will be swapped.
*/

void my_swap_str(char **a, char **b)
{
    char *memory;

    memory = *a;
    *a = *b;
    *b = memory;
}
