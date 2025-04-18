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
    fantominus,
    spectrum,
    ectoplasma,
    mega_ectoplasma
} evolution_t;

typedef struct fantominus_s {
    float x;
    float y;
    int aim;
    int attack;
    evolution_t evolution;
    int shiny;
} fantominus_t;

typedef struct mimiqui_s {
    float x;
    float y;
    int aim;
    int attack;
    int shiny;
} mimiqui_t;

#endif
