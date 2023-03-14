/*
** EPITECH PROJECT, 2020
** read_and_check.c
** File description:
** read and check
*/

#include "asm.h"

int asm_to_cor(asmb_t *asmm, header_t *header, int size, char *path)
{
    //number_u com_size;
    FILE* fdcor;
    int fd;

    //com_size.nb = size;
    path[my_strlen(path) - 1] = 0;
    path = my_strcat(path, "cor");
    fdcor = fopen(path, "w");
    if (fclose(fdcor) < 0)                                 return ERROR_CLOSE;
    if ((fd = open(path, O_WRONLY)) < 0)                   return ERROR_OPEN;
    if (write(fd, header, sizeof(header_t)) < 0)         return ERROR_WRITE;
    /*if (write(fd, &magic, 4) < 0)                        return ERROR_WRITE;
    if (write(fd, asmm->name, PROG_NAME_LENGTH) < 0)       return ERROR_WRITE;
    if (write(fd, "\0\0\0\0", 4)     < 0 || write(fd, &com_size.char4, 1) < 0
    || write(fd, &com_size.char3, 1) < 0 || write(fd, &com_size.char2, 1) < 0
    || write(fd, &com_size.char1, 1) < 0)                  return ERROR_WRITE;
    if (write(fd, asmm->comment, COMMENT_LENGTH - 12) < 0) return ERROR_WRITE;*/
    if (write(fd, asmm->command, size) < 0)   return ERROR_WRITE;
    if (close(fd) < 0)                                     return ERROR_CLOSE;
    return 0;
}

int read_and_check(asmb_t *asmm, char *path)
{
    struct stat info;
    short fd;
    char *buff;

    if (stat(path, &info) == -1) return FILE_NOT_EXIST;
    if (S_ISDIR(info.st_mode) == 1) return IS_DIRECTORY;
    if (info.st_size == 0) return FILE_EMPTY;
    fd = open(path, O_RDONLY & O_ASYNC);
    if (fd < 0) return ERROR_OPEN;
    buff = malloc(sizeof(char) * (info.st_size + 1));
    if (!buff) return ERROR_MEM;
    if ((read(fd, buff, info.st_size)) == -1) return ERROR_READ;
    buff[info.st_size] = '\0';
    if (close(fd) < 0) return ERROR_CLOSE;
    asmm->tab = my_str_to_word_array(buff, "\n");
    if (!asmm->tab) return ERROR_MEM;
    if (buff) free(buff);
    return 0;
}
