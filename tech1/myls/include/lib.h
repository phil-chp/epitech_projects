/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** Lib
*/

#ifndef LIB_H_
#define LIB_H_

#include <sys/stat.h>

char file_type(mode_t);
void file_perms(mode_t);
void file_hard_link(nlink_t);
void file_uid(uid_t);
void file_gid(gid_t);
void file_size(off_t);
void file_minor(dev_t);
void file_major(dev_t);
void file_date_time(time_t);

void my_ls(char *, int *);
void calculate_total(char *);

#endif  /* LIB_H_ */
