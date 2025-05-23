/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** display
*/

#include "wolf.h"

void gastly_attack_player(game_t *game)
{
    gastly_t *gastly = NULL;
    float dx = 0;
    float dy = 0;
    float dist = 0;

    for (int i = 0; game->gastly_tab[i] != NULL; i++) {
        gastly = game->gastly_tab[i];
        if (!gastly->is_alive)
            continue;
        dx = gastly->x - game->player->x;
        dy = gastly->y - game->player->y;
        dist = sqrtf(dx * dx + dy * dy);
        if (dist >= gastly->aim)
            continue;
        game->player->health -= gastly->attack;
    }
}

void mimikyu_attack_player(game_t *game)
{
    mimikyu_t *mimikyu = NULL;
    float dx = 0;
    float dy = 0;
    float dist = 0;

    for (int i = 0; game->mimikyu_tab[i] != NULL; i++) {
        mimikyu = game->mimikyu_tab[i];
        if (!mimikyu->is_alive)
            continue;
        dx = mimikyu->x - game->player->x;
        dy = mimikyu->y - game->player->y;
        dist = sqrtf(dx * dx + dy * dy);
        if (dist >= mimikyu->aim)
            continue;
        game->player->health -= mimikyu->attack;
    }
}

void enemies_attack_player(game_t *game)
{
    gastly_attack_player(game);
    mimikyu_attack_player(game);
}
