/*
** EPITECH PROJECT, 2021
** minishell1 (Workspace)
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_

#ifndef MACROS_H_
#define MACROS_H_

#define ERROR_CODE     84
#define EXIT_CODE      1
#define SUCCESS_CODE   0

#define COMMAND_COUNT  7

#endif /* MACROS_H_ */

char *term_getline(void);

void free_array(char **, int);
void free_dictionary(char ***, int);
void final_free(char ***, char **);

char ***get_commands(void);
char **handle_command(char ***, char **, char **, int *);

char **handle_env(char **, char *, int);

#endif /* UTILS_H_ */
