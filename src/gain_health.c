/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** display
*/

#include "wolf.h"

void check_gain_gastly_health(game_t *game, gastly_t *gastly)
{
    if (gastly->shiny == 1) {
        game->player->health += 2;
        if (game->player->health > 100)
            game->player->health = 100;
    }
}

void check_gain_mimikyu_health(game_t *game, mimikyu_t *mimikyu)
{
    if (mimikyu->shiny == 1) {
        game->player->health += 2;
        if (game->player->health > 100)
            game->player->health = 100;
    }
}
