/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** collision
*/

#include "wolf.h"

bool is_wall(map_t *map, int x, int y)
{
    if (x < 0 || x >= map->width || y < 0 || y >= map->height)
        return false;
    return map->map[y][x] == 1;
}
