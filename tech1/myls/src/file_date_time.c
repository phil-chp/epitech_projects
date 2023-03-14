/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** File Date and time
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include "my.h"

void file_date_time(time_t file)
{
    char *dt = ctime(&file);
    int i = my_strlen(dt);
    int j = 0;

    for (; dt[i] != ':'; i--);
    dt[i] = '\0';
    for (i = 0; dt[i] != ' '; i++);
    i++;
    for (j = 0; dt[i]; j++, i++)
        dt[j] = dt[i];
    dt[j] = '\0';
    my_putstr(dt);
    my_putstr(" ");
    return;
}
