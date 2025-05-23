/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** free_game
*/

#include "wolf.h"

int free_gastly(gastly_t *gastly)
{
    if (gastly->texture)
        sfTexture_destroy(gastly->texture);
    if (gastly->sprite)
        sfSprite_destroy(gastly->sprite);
    free(gastly);
    return 0;
}

int free_mimikyu(mimikyu_t *mimikyu)
{
    if (mimikyu->texture)
        sfTexture_destroy(mimikyu->texture);
    if (mimikyu->sprite)
        sfSprite_destroy(mimikyu->sprite);
    free(mimikyu);
    return 0;
}

int free_gastly_tab(gastly_t **gastly_tab)
{
    for (int i = 0; gastly_tab[i] != NULL; i++)
        free_gastly(gastly_tab[i]);
    free(gastly_tab);
    return 0;
}

int free_mimikyu_tab(mimikyu_t **mimikyu_tab)
{
    for (int i = 0; mimikyu_tab[i] != NULL; i++)
        free_mimikyu(mimikyu_tab[i]);
    free(mimikyu_tab);
    return 0;
}

int free_enemies(game_t *game)
{
    if (game->gastly_tab)
        free_gastly_tab(game->gastly_tab);
    if (game->mimikyu_tab)
        free_mimikyu_tab(game->mimikyu_tab);
    return 0;
}
