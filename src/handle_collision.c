/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** collision
*/

#include "wolf.h"

bool is_wall(map_t *map, int x, int y)
{
    if (map->map[y / TILE_SIZE][x / TILE_SIZE] == 1)
        return true;
    return false;
}
