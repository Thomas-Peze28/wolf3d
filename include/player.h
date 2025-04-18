/*
** EPITECH PROJECT, 2023
** include
** File description:
** player.h
*/

#ifndef PLAYER_H
    #define PLAYER_H

    #include "wolf.h"

typedef struct view_field_s {
    sfVertexArray *line;
    sfVector2f start;
    sfVector2f end;
    sfVector2f direction;
    float angle;
    float distance;
} view_field_t;

typedef struct player_s {
    float x;
    float y;
    float angle;
    float view_angle;
    int aim;
    sfCircleShape *avatar;
    view_field_t **view_field;
} player_t;

player_t *init_player(int tile_size);

#endif
