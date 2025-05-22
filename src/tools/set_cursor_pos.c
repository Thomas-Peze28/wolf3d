/*
** EPITECH PROJECT, 2024
** wolf3D
** File description:
** main
*/

#include "wolf.h"

void set_cursor_position(game_t *game)
{
    sfVector2u window_size = sfRenderWindow_getSize(game->window->win);
    sfVector2f center = {(float)window_size.x / 2, (float)window_size.y / 2};

    sfMouse_setPositionRenderWindow((sfVector2i){center.x, center.y + 100},
        game->window->win);
}
