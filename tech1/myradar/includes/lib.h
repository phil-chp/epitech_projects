/*
** EPITECH PROJECT, 2020
** my_radar (Workspace)
** File description:
** lib
*/

#ifndef LIB_H_
#define LIB_H_

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>

typedef struct pos_s pos_t;
typedef struct vars_s vars_t;

#endif /* STRUCT_H_ */

sfCircleShape *show_tower_area(sfVector2f pos, sfColor outline, float radius);
sfSprite *create_tower(sfVector2f pos, float scale);
sfSprite *create_plane(sfVector2f pos, float size);
sfVector2f define_move(pos_t *pos, sfVector2f c, int i);
void move_planes(vars_t *va, pos_t *pos);
void set_orientation(pos_t *pos);
void check_collision(pos_t *pos);

#endif /* LIB_H_ */
