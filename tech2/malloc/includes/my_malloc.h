/*
** EPITECH PROJECT, 2022
** MyMalloc (Workspace)
** File description:
** my_malloc
*/

#ifndef MY_MALLOC_H_
# define MY_MALLOC_H_

# include <stddef.h>
# include <unistd.h>

typedef enum state_e {
    FREE,
    USED
} state_t;

typedef struct metadata_s {
    state_t            state;
    size_t             size;
    struct metadata_s *next;
} metadata_t;

extern metadata_t *_head;
extern size_t _heap_size;

# define MIN_BLOCK_SIZE  128
# define PAGE_SIZE       getpagesize()
# define METADATA_SIZE   sizeof(metadata_t)

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif /* MY_MALLOC_H_ */
