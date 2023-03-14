/*
** EPITECH PROJECT, 2021
** antman
** File description:
** assets / prototypes / structure and macros
*/

#ifndef ASSETS_H_
#define ASSETS_H_

typedef struct buff_s
{
    int *rep;
    char **array;
    int check;
    char *file_content;
}   buff_t;

#ifndef MACROS_H_
#define MACROS_H_

#define A_STEP  0
#define G_STEP  1

#define COMPARE             ( my_strcmp(temp, buff->array[j]) != 0 )
#define FILE_EXISTS         ( buff->file_content[i] )

#define IS_NOT_SEPARATOR    (  buff->file_content[i] != ' '  \
                            && buff->file_content[i] != '\n'  )
#define IS_SEPARATOR        (  buff->file_content[i] == ' '  \
                            || buff->file_content[i] == '\n'  )

#endif /* MACROS_H_ */

void bubble_sort_array(int, buff_t *);
void check_word(char *, buff_t *);
void free_content(buff_t *, char *);
char *parse_word(int, int, char *);

int nb_word(char *, int);
buff_t *init_buff(char *, int);
char *read_file(char *);

void add_new_word(char *, buff_t *);
void add_plus_one(char *, buff_t *);

#endif /* ASSETS_H_ */
