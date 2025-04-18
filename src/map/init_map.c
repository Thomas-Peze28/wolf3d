/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_structs
*/

#include "wolf.h"

void make_wall(map_t *map, int i, int j)
{
    if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
        map->map[i][j] = 1;
    else
        map->map[i][j] = 0;
}

void wall_map(map_t *map)
{
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            make_wall(map, i, j);
        }
    }
}

void fill_map_with_test(map_t *map)
{
    map->map[4][2] = 1;
    map->map[1][3] = 1;
    map->map[2][3] = 1;
    map->map[4][4] = 1;
    map->map[8][4] = 1;
    map->map[9][4] = 1;
    map->map[4][5] = 1;
    map->map[1][6] = 1;
    map->map[6][6] = 1;
    map->map[7][6] = 1;
    map->map[8][6] = 1;
    map->map[6][8] = 1;
    map->map[3][9] = 1;
    map->map[3][10] = 1;
    map->map[3][11] = 1;
    map->map[7][11] = 1;
    map->map[7][12] = 1;
    map->map[4][13] = 1;
    map->map[6][13] = 1;
    map->map[7][13] = 1;
    map->map[8][13] = 1;
    map->map[1][14] = 1;
    map->map[2][14] = 1;
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
    for (int i = 0; i < map->height; i++)
        for (int j = 0; j < map->width; j++)
            map->map[i][j] = 0;
    wall_map(map);
    fill_map_with_test(map);
    map->tiles = create_tiles(map->width, map->height,
        map->tile_size, map->map);
    return map;
}
