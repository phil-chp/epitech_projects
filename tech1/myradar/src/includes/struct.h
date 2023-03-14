/*
** EPITECH PROJECT, 2020
** my_radar (Workspace)
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>
#include <unistd.h>

#define BAD_FILE    write(2, "Error: File Not Found\n", 23);

#define HEIGHT      1080
#define WIDTH       1920
#define PIXELS      32
#define FPS         25

#define PLANE_SIZE  20

typedef struct framebuffer_s {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

typedef struct vars_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite, *background;
    sfEvent event;
} vars_t;

typedef struct pos_s {
    sfSprite **planes;
    sfVector2f *p_dest;
    int *p_speed;
    int *p_delay;

    sfSprite **towers;
    sfCircleShape **towers_area;
    float *t_radius;

    int p_count;
    int t_count;
} pos_t;

void screen_end(framebuffer_t *fb, vars_t *va, pos_t *pos);
void framebuffer_destroy(framebuffer_t *fb);

framebuffer_t *framebuffer_create(void);
vars_t *vars_create(framebuffer_t *fb);
pos_t *get_positions(char *path);

#endif /* STRUCT_H_ */
