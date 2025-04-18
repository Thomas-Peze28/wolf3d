/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** collision
*/

#include "wolf.h"

static bool condition(map_t *map, int x, int y, sfVector2i index)
{
    sfVector2f pos = {0, 0};
    sfVector2f size = {0, 0};

    if (map->tiles[index.x][index.y] != NULL) {
        pos = sfRectangleShape_getPosition(map->tiles[index.x][index.y]->tile);
        size = sfRectangleShape_getSize(map->tiles[index.x][index.y]->tile);
        if (x >= pos.x && x < pos.x + size.x && y >= pos.y &&
            y < pos.y + size.y && map->tiles[index.x][index.y]->is_wall == 1)
            return true;
    }
    return false;
}

static bool brow_tab(map_t *map, int x, int y, int i)
{
    sfVector2i index = {i, 0};

    for (int j = 0; j < map->width; j++) {
        index.y = j;
        if (condition(map, x, y, index))
            return true;
    }
    return false;
}

bool is_wall(map_t *map, int x, int y)
{
    for (int i = 0; i < map->height; i++) {
        if (brow_tab(map, x, y, i))
            return true;
    }
    return false;
}
