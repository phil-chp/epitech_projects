/*
** EPITECH PROJECT, 2021
** n4s (Workspace)
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

int my_strlen(char const *str);
int my_putstr(char const *str);
int my_getnbr(char const *str);
int my_strcmp(char const *s1 , char const *s2);

char **my_str_to_word_array_div(char const *str, char div);
bool my_str_to_int_array(int **dest, char *src, char split);
char *my_strcat_malloc(char *dest, char const *src);

#endif /* MY_H_ */
