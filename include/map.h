/*
** EPITECH PROJECT, 2023
** include
** File description:
** map.h
*/


#ifndef MAP_H
    #define MAP_H

    #include "wolf.h"

    #define M_PI 3.14159265358979323846
    #define TILE_SIZE 64
    #define MAP_WIDTH 8
    #define MAP_HEIGHT 8
    #define FOV (M_PI / 3)
    #define NUM_RAYS 500

typedef struct tile_s {
    sfRectangleShape *tile;
    sfVector2f pos;
    sfVector2f size;
    sfColor color;
    int is_wall;
} tile_t;
typedef struct map_s {
    int width;
    int height;
    int tile_size;
    int **map;
    tile_t ***tiles;
} map_t;

extern int map[MAP_HEIGHT][MAP_WIDTH];

map_t *init_map(void);
bool is_wall(map_t *map, int x, int y);
tile_t ***create_tiles(int width, int height, int tile_size, int **map);

#endif
