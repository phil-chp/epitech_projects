/*
** EPITECH PROJECT, 2020
** B-CPE-201-NCE-2-1-corewar-philippe.cheype
** File description:
** counter.c
*/

int counter(char **res)
{
    int i;

    if (!res) return (0);
    for (i = 0; res[i]; i++);
    return (i);
}
