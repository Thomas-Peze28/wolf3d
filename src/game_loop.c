/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** display
*/

#include "wolf.h"

int manage_rays(game_t *game)
{
    cast_all_rays(game);
    calcuate_rays_dist(game);
    display_rays_walls(game);
    return 0;
}

int draw_minimap(game_t *game)
{
    display_fps(game);
    draw_2d_map(game);
    display_player(game);
    return 0;
}

int draw_ceilling_floor(game_t *game)
{
    sfRenderWindow_drawRectangleShape(game->window->win,
        game->graphics->floor, NULL);
    sfRenderWindow_drawRectangleShape(game->window->win,
        game->graphics->ceilling, NULL);
    return 0;
}

int game_loop(game_t *game)
{
    handle_key_pressed(game);
    sfRenderWindow_clear(game->window->win, sfBlack);
    draw_ceilling_floor(game);
    manage_rays(game);
    draw_minimap(game);
    return 0;
}
