/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_structs
*/

#include "wolf.h"

static int fill_map_line(char *buffer, int **map, int line)
{
    int j = 0;

    while (j < MAP_WIDTH) {
        map[line][j] = buffer[j] - '0';
        j++;
    }
    return 0;
}

static int file_to_map(char *filepath, int **map)
{
    FILE *file = fopen(filepath, "r");
    char *buffer = malloc(sizeof(char) * MAP_WIDTH);
    size_t len = 0;
    int line = 0;

    if (!file)
        return -1;
    while (getline(&buffer, &len, file) != -1) {
        fill_map_line(buffer, map, line);
        line++;
    }
    free(buffer);
    fclose(file);
    return 0;
}

map_t *init_map(char *filepath)
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
    file_to_map(filepath, map->map);
    map->tiles = create_tiles(map->width, map->height,
        map->tile_size, map->map);
    return map;
}
