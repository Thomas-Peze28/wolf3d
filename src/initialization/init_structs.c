/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_structs
*/

#include "wolf.h"

game_t *init_game(char *filepath)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->level = 1;
    game->ennmies_alive = 0;
    game->score = 0;
    game->window = init_window(sfResize | sfClose);
    game->map = init_map(filepath);
    game->player = init_player(game->map->tile_size);
    game->graphics = init_graphics(game);
    game->graphics->menu = init_menu();
    game->sounds = init_sounds();
    game->map->tiles = create_tiles(game->map->width, game->map->height,
        game->map->tile_size, game->map->map);
    game->gastly_tab = init_gastly_tab(3, game->map->map);
    game->mimikyu_tab = init_mimikyu_tab(3, game->map->map);
    return game;
}
