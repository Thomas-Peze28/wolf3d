/*
** EPITECH PROJECT, 2023
** include
** File description:
** map.h
*/


#ifndef MAP_H
    #define MAP_H

    #include "wolf.h"

    #define TILE_SIZE 64
    #define MAP_WIDTH 8
    #define MAP_HEIGHT 8
    #define FOV (3.14 / 3)
    #define NUM_RAYS 800

typedef struct map_s {
    int width;
    int height;
    int tile_size;
    int **map;
} map_t;

extern int map[MAP_HEIGHT][MAP_WIDTH];

#endif
