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
        game->score += 200;
        game->player->health += 2;
        if (game->player->health > 100)
            game->player->health = 100;
    } else {
        game->score += 50;
    }
}

void check_gain_mimikyu_health(game_t *game, mimikyu_t *mimikyu)
{
    if (mimikyu->shiny == 1) {
        game->score += 250;
        game->player->health += 2;
        if (game->player->health > 100)
            game->player->health = 100;
    } else {
        game->score += 100;
    }
}
