/*
** EPITECH PROJECT, 2024
** wold3D
** File description:
** map
*/

#include "wolf.h"

void save_map_to_file(int map[MAP_HEIGHT][MAP_WIDTH], const char *filename)
{
    FILE *file = fopen(filename, "w");

    if (!file)
        return;
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++)
            fprintf(file, "%d", map[y][x]);
        fprintf(file, "\n");
    }
    fclose(file);
}
