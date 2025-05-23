/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** free_game
*/

#include "wolf.h"

void free_tiles(map_t *map)
{
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            sfDestroyRectangleShape(map->tiles[i][j]->tile);
            free(map->tiles[i][j]);
        }
        free(map->tiles[i]);
    }
    free(map->tiles);
}

int free_map(map_t *map)
{
    if (map->map)
        free(map->map);
    if (map->tiles)
        free_tiles(map);
    free(map);
    return 0;
}
