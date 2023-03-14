/*
** EPITECH PROJECT, 2021
** antman (Workspace)
** File description:
** create_decompressed
*/

#include <stdlib.h>
#include "../../include/assets.h"
#include "../../include/my.h"

char *r_parse_word(int start, int end, char *src);

char *my_strncpyn(char const *src, int beg, int end)
{
    char *dest;
    int i;

    dest = malloc(sizeof(char) * (end - beg + 1));
    for (i = 0; i + beg < end; i++)
        dest[i] = src[i + beg];
    dest[i] = '\0';
    return (dest);
}

int *check_multiple(char *temp)
{
    int *result;
    int i = 0;
    int a = 0;

    result = malloc(sizeof(int) * 2);
    result[1] = 1;
    for (; temp[i] && temp[i] != 'x'; i++);
    if (i == my_strlen(temp)) {
        result[0] = my_getnbr(temp);
        return (result);
    }
    for (int n = 0; n < 2; n++, a = i + 1, i = my_strlen(temp)) {
        char *mem = my_strncpyn(temp, a, i);
        result[n] = my_getnbr(mem);
        free(mem);
    }
    return (result);
}

void create_decompressed(buff_t *buff)
{
    int start;
    int i;

    i = buff->rep[0];
    start = i;
    for (; buff->file_content[i]; i++) {
        for (; IS_NOT_SEPARATOR && FILE_EXISTS; i++);
        for (; IS_SEPARATOR; i++);
        char *temp = parse_word(start, i - 1, buff->file_content);
        int *get_multiple = check_multiple(temp);
        for (int j = 0; j < get_multiple[1]; j++)
            my_lprintf("%s", buff->array[get_multiple[0]]);
        start = i;
        free(get_multiple);
        free(temp);
    }
}
