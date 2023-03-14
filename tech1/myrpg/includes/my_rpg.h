/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** rpg header
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my_macros.h"
#include "menu_data.h"
#include "game_data.h"

bool enemy_manager(game_t *game, cell_t *cell);
bool obj_manager(obj_t **obj, cell_t *cell);
void add_orb(game_t *game);
bool pnj_manager(game_t *game, cell_t *cell);

bool create_bullet(bullet_t **bullet);
bool create_button(button_t *, char *, sfFloatRect, sfTexture *);
bool create_button_list(button_t **, size_t, char **, sfFloatRect);
int create_info(info_t *info, char *path, sfVector2f *pos, char *nbr);
sfCircleShape *create_circle(sfVector2f pos, float radius, sfTexture *texture);
bool create_door(door_t *door, sfVector2f pos, bool right);
bool create_map(map_t **map, char **);
sfRectangleShape *create_rectangle(sfVector2f, sfVector2f, sfTexture *);
bool create_pop_up(pop_up_t *pop_up, sfVector2f pos, int stair);
bool create_slider(slider_t *, char *, sfFloatRect, sfTexture *);
bool create_slider_list(slider_t **, size_t, char **, sfFloatRect);
bool create_inventory_list( sfRectangleShape ****,       \
                            size_t count,        \
                            char **paths,        \
                            sfFloatRect pos_size);
sfSprite *create_sprite(sfTexture *, sfVector2f*, sfVector2f*, sfBool);
sfText *create_text(char *, sfVector2f, sfColor, unsigned int);
bool create_overlay(overlay_t **overlay);

bool init_game(sfRenderWindow **win, game_t *game, bool *game_mode);
bool init_option(game_t *game);
bool init_hud(hud_t *hud, entity_t *);
bool get_stat_contents(char *file, int **stats_content);
bool init_player(entity_t *pl, int **stat);
int init_settings_menu(menu_t *, sfVector2f, char *);
int init_window(sfRenderWindow **win, char *name);
int start_map(game_t *game);
bool init_sounds(music_t *music);
int update_stat_map(map_t **map);

// - - - - - - - - - - //
// - - - Render  - - - //
// - - - - - - - - - - //

void render_elements(sfRenderWindow **win, menu_t *menu);
void render_map(sfRenderWindow **win, map_t **map);

// - - - - - - - - - - //
// - - -  Utils  - - - //
// - - - - - - - - - - //

bool create_map_file(game_t *game);
bool create_feature(game_t *game);
bool create_minimap(hud_t *hud, sfVector2f pos[], char *path);
void write_file(char *file, char *content, int purge);
void render_inventory_elements( sfRenderWindow **win, \
                                game_t *game,         \
                                inv_t *inv,           \
                                sfSprite **screenshot);
size_t *get_stats_in_order(stats_t *stats);
int my_abs(int n);
double pythagoreas(int a, int b);
void normalize(sfVector2f *vector);
void update_slider(slider_t *slider, int mouse_pos);
void update_inv(slider_t *slider, int mouse_pos);
double get_angle(sfVector2i b, sfVector2i a);
void check_no_more_enemies(game_t *game);
sfVector2f get_advancement(sfVector2f a, sfVector2f b);
double get_anglef(sfVector2f b, sfVector2f a);
bool get_stat_contents(char *file, int **stats_content);
size_t get_time_elapsed(sfClock *clock, size_t divider);
int get_random(unsigned int min, unsigned int max);
void update_button(button_t *, sfVector2f *);
sfTexture **get_textures_for_buttons(char *path, size_t n);
int get_screenshot(sfSprite **screenshot, sfRenderWindow *win);
sfVector2f calculate_text_position(char *, sfVector2f, sfVector2f, size_t);
sfVector2f get_center(sfVector2f size_a, sfVector2f size_b);

void destroy_features(game_t *game);
void sfRectangleShape_destroy(sfRectangleShape *rect);
void sfSprite_destroy(sfSprite *sprite);
void destroy_inventory(inv_t *inv, sfSprite **screenshot);

// - - - - - - - - - - - - //
// - - - - - Menu  - - - - //
// - - - - - - - - - - - - //

int menu_loop(sfRenderWindow **win, bool *game_mode);
void handle_stars_collision(obj_t **iter, entity_t *pl, sfVector2f pos, \
                            sfVector2f size);
int gamemode_chooser(sfRenderWindow **win, bool *game_mode);
void destroy_menu(menu_t *menu);

// - - - - - - - - - - - - //
// - - - -  Other  - - - - //
// - - - - - - - - - - - - //
int other_loop(sfRenderWindow **win, bool *none);
char **create_paths(void);

bool build_map(game_t *game);

// - - - - - - - - - - - - //
// - - -  Settings - - - - //
// - - - - - - - - - - - - //

int settings_loop(sfRenderWindow **win, bool *none);

// - - - - - - - - - - - - //
// - - - - - Game  - - - - //
// - - - - - - - - - - - - //

int game_loop(sfRenderWindow **win, bool *game_mode);
int pause_loop(sfRenderWindow **);
int inventory_loop(sfRenderWindow **win, game_t *game);
void destroy_game(game_t *);
void destroy_hud(hud_t *hud);
void destroy_map(map_t **map);
void destroy_map(map_t **map);
void destroy_player(entity_t *pl);

// - - - - - - - - - - - - //
// - - - - Handlers  - - - //
// - - - - - - - - - - - - //

sfVector2f handle_movement(int keys[4], float);
void handle_inputs(entity_t *, sfMouseMoveEvent *, sfUint64);
int handle_bullet(queue_man_t **bullets, entity_t *pl, sfUint64 s);
int handle_game(sfRenderWindow **win, game_t *game, sfEvent *event);
int handle_inventory_interaction(sfRenderWindow **win, inv_t *inv, entity_t *);
char **get_inventory_paths(void);
bool handle_inventory_sliders(inv_t *inv, sfVector2f pos, stats_t *stats);
bool handle_star_counter(inv_t *inv, size_t star_n);
int handle_slider_interaction(sfRenderWindow **win, menu_t *mn);
int handle_button_interaction(sfRenderWindow **win, menu_t *mn);
bool handle_map(game_t *game);
bool handle_health_bar(entity_t **entity);
void handle_minimap(game_t *game);
void handle_collision(sfVector2f *pos,  \
sfFloatRect game_floor, sfFloatRect area, bool check_doors);
void handle_decoration_collision(sfVector2f *pl_pos, sfFloatRect deco_area);
bool handle_bullet_collision(queue_man_t **bullets, sfVector2f enem_pos);
void handle_player_collision(entity_t *pl, sfVector2f pos, sfVector2f size);
void handle_animation(entity_t **entity);
void handle_pop_up(entity_t *pl, entity_t *pnj);
void update_stats(game_t *game);
void handle_obj_collision(obj_t **iter, game_t *game, sfVector2f pos, \
                            sfVector2f size);
// - - - - - - - - - - - - //
// - - - -  Toggle   - - - //
// - - - - - - - - - - - - //

int toggle_overlay(game_t *game);
int toggle_doors(game_t *game);
int toggle_hud(game_t *game);
int toggle_speed(game_t *game);

// - - - - - - - - - - - - //
// - - - -  Update   - - - //
// - - - - - - - - - - - - //

void render_hud(sfRenderWindow **win, hud_t *hud);
bool init_menu(menu_t *menu, sfVector2f counts, char *music);
void update_position(sfRectangleShape *, sfVector2f);
void update_bar(game_t *game, size_t elapsed);
void update_bullet(sfRenderWindow **win, queue_man_t **bullets, sfUint64 s);
void update_map(sfRenderWindow **win, game_t *game);
void update_enemy(sfRenderWindow **win, game_t *game, queue_man_t **bl);
void update_obj(sfRenderWindow **win, game_t *game);
void update_player(sfRenderWindow **win, entity_t *pl);
void update_pnj(sfRenderWindow **win, entity_t *pnj);
void update_overlay(sfRenderWindow **win, overlay_t **over, game_t *game);
void update_pop_up(sfRenderWindow **win, pop_up_t *pop_up);

#endif /* MY_RPG_H_ */
