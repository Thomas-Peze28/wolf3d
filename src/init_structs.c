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
    game->window = init_window();
    game->map = init_map();
    game->player = init_player(game->map->tile_size);
    return game;
}

window_t *init_window(void)
{
    window_t *win = malloc(sizeof(window_t));

    if (!win)
        return NULL;
    win->win = NULL;
    win->event = (sfEvent){0};
    win->mode = (sfVideoMode){0};
    win->mode.bitsPerPixel = 32;
    win->mode.width = 800;
    win->mode.height = 600;
    win->win = sfRenderWindow_create(win->mode, "WOLF", sfResize | sfClose, NULL);
    return win;
}

static void wall_map(map_t *map)
{
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
                map->map[i][j] = 1;
            else
                map->map[i][j] = 0;
        }
    }
}

map_t *init_map(void)
{
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        return NULL;
    map->width = MAP_WIDTH;
    map->height = MAP_HEIGHT;
    map->tile_size = TILE_SIZE;
    map->map = malloc(sizeof(int *) * map->height);
    if (!map->map)
        return NULL;
    for (int i = 0; i < map->height; i++)
        map->map[i] = malloc(sizeof(int) * map->width);
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++)
            map->map[i][j] = 0;
    }
    wall_map(map);
    return map;
}

player_t *init_player(int tile_size)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->x = 0;
    player->y = 0;
    player->angle = 0;
    player->avatar = sfCircleShape_create();
    sfCircleShape_setRadius(player->avatar, tile_size / 2);
    sfCircleShape_setOrigin(player->avatar, (sfVector2f){0, 0});
    sfCircleShape_setFillColor(player->avatar, sfGreen);
    sfCircleShape_setPosition(player->avatar, (sfVector2f){player->x * tile_size, player->y * tile_size});
    return player;
}
