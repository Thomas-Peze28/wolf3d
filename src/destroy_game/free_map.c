/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** free_game
*/

#include "wolf.h"



void free_tile_row(map_t *map, int row)
{
    for (int j = 0; j < map->width; j++) {
        if (map->tiles[row][j])
            sfRectangleShape_destroy(map->tiles[row][j]->tile);
        free(map->tiles[row][j]);
    }
    free(map->tiles[row]);
}

void free_tiles(map_t *map)
{
    for (int i = 0; i < map->height; i++) {
        free_tile_row(map, i);
    }
    free(map->tiles);
}

int free_map(map_t *map)
{
    if (!map)
        return 0;
    if (map->map)
        free(map->map);
    if (map->tiles)
        free_tiles(map);
    free(map);
    return 0;
}
