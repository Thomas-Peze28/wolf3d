/*
** EPITECH PROJECT, 2024
** wolf3D
** File description:
** main
*/

#include "wolf.h"

int free_graphics(graphics_t *graphics)
{
    if (!graphics)
        return 0;
    if (graphics->pokeball)
        sfTexture_destroy(graphics->pokeball);
    if (graphics->menu)
        free_menu(graphics->menu);
    if (graphics->hud)
        free_hud(graphics->hud);
    if (graphics->ceilling)
        sfRectangleShape_destroy(graphics->ceilling);
    if (graphics->floor)
        sfRectangleShape_destroy(graphics->floor);
    if (graphics->cursor)
        sfSprite_destroy(graphics->cursor);
    free(graphics);
    return 0;
}
