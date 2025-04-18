/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_enemies
*/

#include "enemy.h"
#include "map.h"

// if shiny is catched then life stat++

fantominus_t *init_fantominus(fantominus_t *fantominus)
{
    fantominus->evolution = rand() / 4;
    fantominus->attack = ((rand() / 5) + 1) * fantominus->evolution;
    fantominus->aim = 250 + (25 * fantominus->evolution);
    fantominus->shiny = (rand() / 10);
    fantominus->x = (rand() / MAP_WIDTH);
    fantominus->y = (rand() / MAP_HEIGHT);
    return fantominus;
}

fantominus_t **init_fantominus_tab(void)
{
    fantominus_t **fantominus_tab = malloc(sizeof(fantominus_t) * 6);

    for (int i = 0; i < 5; i++)
        fantominus_tab[i] = init_fantominus(fantominus_tab[i]);
    fantominus_tab[5] = NULL;
    return fantominus_tab;
}
