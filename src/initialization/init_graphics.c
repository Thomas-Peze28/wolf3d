/*
** EPITECH PROJECT, 2024
** day_13
** File description:
** main
*/

#include "wolf.h"

void init_floor_and_ceiling(graphics_t *graphics, game_t *game)
{
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
}

void init_wall(graphics_t *graphics)
{
    graphics->wall_rect = (sfIntRect){0, 0, 64, 64};
    graphics->wall_texture = sfTexture_createFromFile(
        "assets/stone_wall.jpg", NULL);
    graphics->wall_sprite = sfSprite_create();
    sfSprite_setTexture(graphics->wall_sprite, graphics->wall_texture, sfTrue);
    sfSprite_setTextureRect(graphics->wall_sprite, graphics->wall_rect);
}

graphics_t *init_graphics(game_t *game)
{
    graphics_t *graphics = malloc(sizeof(graphics_t));

    if (!graphics)
        return NULL;
    init_floor_and_ceiling(graphics, game);
    init_wall(graphics);
    return graphics;
}
