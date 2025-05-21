/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_enemies
*/

#include "wolf.h"

gastly_t **init_gastly_tab(int level, int **map)
{
    gastly_t **gastly_tab = malloc(sizeof(gastly_t) * (6 + (level * 3)));

    for (int i = 0; i < 5 + (level * 3); i++)
        gastly_tab[i] = init_gastly(gastly_tab[i], map);
    gastly_tab[5 + (level * 3)] = NULL;
    return gastly_tab;
}

mimikyu_t **init_mimikyu_tab(int level, int **map)
{
    mimikyu_t **mimikyu_tab = malloc(sizeof(mimikyu_t) * (2 + level));

    for (int i = 0; i < 1 + level; i++)
        mimikyu_tab[i] = init_mimikyu(mimikyu_tab[i], map);
    mimikyu_tab[1 + level] = NULL;
    return mimikyu_tab;
}
