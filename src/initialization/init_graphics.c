/*
** EPITECH PROJECT, 2024
** day_13
** File description:
** main
*/

#include "wolf.h"

graphics_t *init_graphics(game_t *game)
{
    graphics_t *graphics = malloc(sizeof(graphics_t));

    if (!graphics)
        return NULL;
    graphics->floor = sfRectangleShape_create();
    graphics->ceilling = sfRectangleShape_create();
    sfRectangleShape_setFillColor(graphics->floor,
        sfColor_fromRGB(96, 96, 96));
    sfRectangleShape_setFillColor(graphics->ceilling,
        sfColor_fromRGB(64, 64, 64));
    sfRectangleShape_setSize(graphics->floor,
        (sfVector2f){game->window->mode.width, game->window->mode.height / 2});
    sfRectangleShape_setSize(graphics->ceilling,
        (sfVector2f){game->window->mode.width, game->window->mode.height / 2});
    sfRectangleShape_setPosition(graphics->floor,
        (sfVector2f){0, game->window->mode.height / 2});
    sfRectangleShape_setPosition(graphics->ceilling, (sfVector2f){0, 0});
    return graphics;
}
