/*
** EPITECH PROJECT, 2023
** include
** File description:
** player.h
*/

#ifndef ENEMY_H
    #define ENEMY_H

    #include "wolf.h"

typedef enum evolution_s {
    GASTLY,
    HAUNTER,
    GENGAR,
    MEGA_GENGAR,
} evolution_t;

typedef struct gastly_s {
    float x;
    float y;
    int aim;
    int attack;
    evolution_t evolution;
    int shiny;
} gastly_t;

typedef struct mimikyu_s {
    float x;
    float y;
    int aim;
    int attack;
    int shiny;
} mimikyu_t;

mimikyu_t **init_mimikyu_tab(int level);
gastly_t **init_gastly_tab(int level);

#endif
