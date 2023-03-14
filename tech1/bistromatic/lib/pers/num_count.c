/*
** EPITECH PROJECT, 2020
** Num Count
** File description:
** Counts the amount of number that come after the positon given
*/

int num_count(char *calc, int i)
{
    int j;

    for (j = 0; calc[i] && ((calc[i] >= '0' && calc[i] <= '9')  \
        || calc[i] == '-'); i++)
        j++;
    return (j);
}