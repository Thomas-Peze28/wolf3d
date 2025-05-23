/*
** EPITECH PROJECT, 2024
** wolf3D
** File description:
** main
*/

#include "wolf.h"

int count_ennemies(gastly_t **gastly_tab, mimikyu_t **mimikyu_tab)
{
    int count = 0;

    for (int i = 0; gastly_tab[i]; i++)
        if (gastly_tab[i]->is_alive == true)
            count++;
    for (int i = 0; mimikyu_tab[i]; i++)
        if (mimikyu_tab[i]->is_alive == true)
            count++;
    return count;
}
