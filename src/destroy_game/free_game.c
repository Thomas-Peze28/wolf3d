/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** free_game
*/

#include "wolf.h"

int free_game(game_t *game)
{
    if (!game)
        return 0;
    sfRenderWindow_destroy(game->window->win);
    if (game->map)
        free_map(game->map);
    if (game->graphics)
        free_graphics(game->graphics);
    if (game->gastly_tab)
        free_gastly_tab(game->gastly_tab);
    if (game->mimikyu_tab)
        free_mimikyu_tab(game->mimikyu_tab);
    free(game);
    return 0;
}
