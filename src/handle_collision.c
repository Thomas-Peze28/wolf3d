/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** collision
*/

#include "wolf.h"

bool is_wall(map_t *map, int x, int y)
{
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            if (map->tiles[i][j] != NULL) {
                sfVector2f pos = sfRectangleShape_getPosition(map->tiles[i][j]->tile);
                sfVector2f size = sfRectangleShape_getSize(map->tiles[i][j]->tile);
                if (x >= pos.x && x < pos.x + size.x && y >= pos.y && y < pos.y + size.y && map->tiles[i][j]->is_wall == 1)
                    return true;
            }
        }
    }
    return false;
}
