/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** my_macros
*/

#ifndef MY_MACROS_H_
#define MY_MACROS_H_

#ifndef MY_RPG_H_

#include <SFML/Graphics.h>

#endif /* MY_RPG_H_ */

#define WIDTH       1920
#define HEIGHT      1080
#define PIXELS      32
#define FPS         60

#define SCREEN      (sfVector2f){ WIDTH, HEIGHT }

#define GET_COLLISION(m_pos, pos_size)      \
(  m_pos.x > pos_size.left                  \
&& m_pos.y > pos_size.top                   \
&& m_pos.x < pos_size.left + pos_size.width \
&& m_pos.y < pos_size.top  + pos_size.height)

#define GET_COLLISION_CENTER(m_pos, pos_size) \
(  m_pos.x >= pos_size.left - 20              \
&& m_pos.y >= pos_size.top - 40               \
&& m_pos.x <= pos_size.left + 84              \
&& m_pos.y <= pos_size.top + 74)

#define WAIT_FOR_BUTTON_RELEASE  while (sfMouse_isButtonPressed(0)) {}

//                       UP        DOWN       LEFT        RIGHT
#define ZQSD_KEYS()   { sfKeyZ,  sfKeyS,    sfKeyQ,    sfKeyD     };
#define ARROW_KEYS()  { sfKeyUp, sfKeyDown, sfKeyLeft, sfKeyRight };

#define GAME_FLOOR  (sfFloatRect){                    \
    320.0f, 188.0f, 1280.0f + 320.0f, 704.0f + 188.0f \
}

#endif /* MY_MACROS_H_ */