/*
** EPITECH PROJECT, 2022
** Panoramix (Workspace)
** File description:
** trains
*/

#ifndef TRAINS_H_
    #define TRAINS_H_

    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>

    #include <pthread.h>
    #include <semaphore.h>

    #define ERROR_CODE      84
    #define ERROR_VALUE     1
    #define SUCCESS_CODE    0
    #define SUCCESS_VALUE   0

    #define THREAD_SHARED   0

typedef struct args_s {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
} args_t;

typedef struct villager_s {
    pthread_t thread;
    int       nb_fights;
    bool      has_drunk;
} villager_t;

typedef struct druid_s {
    pthread_t thread;
    bool alive;
} druid_t;

typedef struct pano_s {
    args_t          args;
    int             nb_servings_left;

    villager_t     *villagers;
    sem_t           refill_sem;
    pthread_mutex_t villager_mutex;

    druid_t        *druid;
    sem_t           confirm_sem;
} pano_t;

typedef struct current_villager_s {
    pano_t *pano;
    int     vid;
} current_villager_t;

// _________________ General _________________ //
int  init_panoramix(pano_t *pano, char *name);
int  start_panoramix(pano_t *pano, char *name);
void destroy_panoramix(pano_t *pano);

// __________________ NPCs ___________________ //
void *run_villager(void *data);
void *run_druid(void *data);

// __________________ Utils __________________ //
void print_usage(FILE *stream, char *name);
void print_error(char *name, char *message);

int  check_arguments(int ac, char **av);
int  init_arguments(pano_t *pano, char **av);

#endif /* !TRAINS_H_ */
