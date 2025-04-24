/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_structs
*/

#include "wolf.h"

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->level = 1;
    game->window = init_window();
    game->map = init_map();
    game->player = init_player(game->map->tile_size);
    game->graphics = init_graphics(game);
    game->map->tiles = create_tiles(game->map->width, game->map->height,
        game->map->tile_size, game->map->map);
    return game;
}
