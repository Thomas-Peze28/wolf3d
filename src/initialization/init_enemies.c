/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_enemies
*/

#include "enemy.h"
#include "map.h"

// if shiny is catched then life stat++

gastly_t *init_gastly(gastly_t *gastly)
{
    gastly->evolution = GASTLY;
    gastly->attack = 5 + ((rand() / 5) + 1) * gastly->evolution;
    gastly->aim = 250 + (25 * gastly->evolution);
    gastly->shiny = (rand() / 10);
    gastly->x = (rand() / MAP_WIDTH);
    gastly->y = (rand() / MAP_HEIGHT);
    return gastly;
}

gastly_t **init_gastly_tab(int level)
{
    gastly_t **gastly_tab = malloc(sizeof(gastly_t) * (6 + (level * 3)));

    for (int i = 0; i < 5; i++)
        gastly_tab[i] = init_gastly(gastly_tab[i]);
    gastly_tab[5] = NULL;
    return gastly_tab;
}

mimikyu_t *init_mimikyu(mimikyu_t *mimikyu)
{
    mimikyu->attack = 10;
    mimikyu->aim = 250;
    mimikyu->shiny = (rand() / 10);
    mimikyu->x = (rand() / MAP_WIDTH);
    mimikyu->y = (rand() / MAP_HEIGHT);
    return mimikyu;
}

mimikyu_t **init_mimikyu_tab(int level)
{
    mimikyu_t **mimikyu_tab = malloc(sizeof(mimikyu_t) * (2 + level));

    for (int i = 0; i < 5; i++)
        mimikyu_tab[i] = init_mimikyu(mimikyu_tab[i]);
    mimikyu_tab[5] = NULL;
    return mimikyu_tab;
}
