/*
** EPITECH PROJECT, 2023
** include
** File description:
** player.h
*/

#ifndef PLAYER_H
    #define PLAYER_H

    #include "wolf.h"


typedef struct view_angle_s {
    sfVertexArray *line;
    sfVector2f start;
    sfVector2f end;
    sfVector2f direction;
    float angle;
    float distance;
} view_angle_t;
typedef struct player_s {
    float x;
    float y;
    float angle;
    float view_angle;
    sfCircleShape *avatar;
    view_angle_t **view_angles;
} player_t;

player_t *init_player(int tile_size);

#endif
