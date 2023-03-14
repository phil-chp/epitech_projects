/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#define ERROR       84
#define PL_W        1
#define AI_W        2

typedef struct game_s {
    char **map;
    int *counts;
    int h;
    int max;
} game_t;

// - - -  ERROR  - - - //
void usage(void);
int error_handling(int ac, char **av);

// - - -  GAME   - - - //
game_t *init_game(char *h, char *max);
int check_win(game_t *game, int turn);
void print_win(int return_code);
int total_matches_left(game_t *game);

// - - -   MAP   - - - //
char **create_map(int h);
void update_map(game_t *game, int line, int match);

// - - - DESTROY - - - //
void destroy(game_t *game);

// - - -  TURN  - - - //
int player_turn(game_t *game);
int ai_turn(game_t *game);

#endif /* MATCHSTICK_H_ */
