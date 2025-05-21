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
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    int nb_frame;
    int frame;
} gastly_t;

typedef struct mimikyu_s {
    float x;
    float y;
    int aim;
    int attack;
    int shiny;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    int nb_frame;
    int frame;
} mimikyu_t;

typedef struct pokemon_s {
    gastly_t **gastly;
    mimikyu_t **mimikyu;
} pokemon_t;

void set_mimukyu(mimikyu_t *mimikyu, int **map);
void set_gastly(gastly_t *gastly, int **map);
mimikyu_t *init_mimikyu(mimikyu_t *mimikyu, int **map);
gastly_t *init_gastly(gastly_t *gastly, int **map);
mimikyu_t **init_mimikyu_tab(int level, int **map);
gastly_t **init_gastly_tab(int level, int **map);

#endif
