/*
** EPITECH PROJECT, 2023
** include
** File description:
** player.h
*/

#ifndef PLAYER_H
    #define PLAYER_H

    #include "wolf.h"

typedef struct player_s {
    float x;
    float y;
    float angle;
    sfCircleShape *avatar;
} player_t;

player_t *init_player(int tile_size);

#endif
