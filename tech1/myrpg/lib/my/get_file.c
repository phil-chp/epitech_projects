/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** get_file
*/

#include <stdio.h>

char *my_strdup(char const *src);

char *get_file(char *path, size_t size)
{
    char temp[size];
    char *buff;
    FILE *file;
    int len;

    if (!(file = fopen(path, "r")))
        return (NULL);
    if ((len = fread(&temp, sizeof(char), size, file)) == -1) {
        fclose(file);
        return (NULL);
    }
    temp[len] = '\0';
    buff = my_strdup(temp);
    fclose(file);
    return (buff);
}
