/*
** EPITECH PROJECT, 2024
** wolf3D
** File description:
** main
*/

#include "wolf.h"

void toggle_light(game_t *game)
{
    if (game->graphics->menu->options_menu->light == 150.0)
        game->graphics->menu->options_menu->light = 30.0;
    else
        game->graphics->menu->options_menu->light = 150.0;
}
