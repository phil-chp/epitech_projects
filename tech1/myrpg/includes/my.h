/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

int my_putstr(char const *str);
int my_strlen(const char *str);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_strcat(char *dest, char *src);

int **my_str_to_int_array(int **dest, char *src, char split);

char *my_getstr(int nb);
char *my_get_str_m(int nb, char **str);
char **my_str_to_word_array_div(char const *str, char div);
char *get_file(char *path, size_t size);

#endif /* MY_H_ */
