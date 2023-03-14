/*
** EPITECH PROJECT, 2021
** duostumper2
** File description:
** integers functions
*/

int length_array(char **tab)
{
    int i = 0;

    while (tab[i]) i++;
    return (i);
}
