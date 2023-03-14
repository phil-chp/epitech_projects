/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** TIME DIVISIONS:
**     1000000 - SECONDS
**     100000  - TENTH OF A SECONDS
**     10000   - HUDRENDS OF A SECONDS
**     1000    - MILLISECONDS
**     100     - TENTH OF A MILLISECONDS
**     10      - HUDRENDS OF A MILLISECONDS
**     1       - MICROSECONDS
*/

#include <SFML/Graphics.h>

size_t get_time_elapsed(sfClock *clock, size_t divider)
{
    return (sfClock_getElapsedTime(clock).microseconds / divider);
}
