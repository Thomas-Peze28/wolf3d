/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_structs
*/

#include "wolf.h"

void set_rectangle_style(tile_t ***tiles, int **map, sfVector2i tupple,
    int tile_size)
{
    if (map[tupple.x][tupple.y] == 1)
        tiles[tupple.x][tupple.y]->color = sfColor_fromRGB(128, 128, 128);
    else
        tiles[tupple.x][tupple.y]->color = sfColor_fromRGB(192, 192, 192);
    tiles[tupple.x][tupple.y]->is_wall = map[tupple.x][tupple.y];
    sfRectangleShape_setSize(tiles[tupple.x][tupple.y]->tile,
        (sfVector2f){tile_size, tile_size});
    sfRectangleShape_setPosition(tiles[tupple.x][tupple.y]->tile,
        (sfVector2f){tiles[tupple.x][tupple.y]->pos.x,
            tiles[tupple.x][tupple.y]->pos.y});
    sfRectangleShape_setFillColor(tiles[tupple.x][tupple.y]->tile,
        tiles[tupple.x][tupple.y]->color);
}

tile_t ***create_tiles(int width, int height, int tile_size, int **map)
{
    tile_t ***tiles = malloc(sizeof(tile_t **) * height);

    if (!tiles)
        return NULL;
    for (int i = 0; i < height; i++) {
        tiles[i] = malloc(sizeof(tile_t *) * width);
        if (!tiles[i])
            return NULL;
        for (int j = 0; j < width; j++) {
            tiles[i][j] = malloc(sizeof(tile_t));
            tiles[i][j]->tile = sfRectangleShape_create();
            tiles[i][j]->pos.x = j * tile_size;
            tiles[i][j]->pos.y = i * tile_size;
            tiles[i][j]->size.x = tile_size;
            tiles[i][j]->size.y = tile_size;
            set_rectangle_style(tiles, map, (sfVector2i){i, j}, tile_size);
        }
    }
    return tiles;
}
