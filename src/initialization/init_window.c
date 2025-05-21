/*
** EPITECH PROJECT, 2024
** day_13
** File description:
** main
*/

#include "wolf.h"

window_t *init_window(sfUint32 style)
{
    window_t *win = malloc(sizeof(window_t));
    sfContextSettings settings = {0};

    if (!win)
        return NULL;
    win->win = NULL;
    win->event = (sfEvent){0};
    win->mode = (sfVideoMode){0};
    win->mode.bitsPerPixel = 32;
    win->mode.width = WINDOW_WIDTH;
    win->mode.height = WINDOW_HEIGHT;
    win->style = style;
    settings.antialiasingLevel = 4;
    win->win = sfRenderWindow_create(win->mode, "WOLF",
        style, &settings);
    sfRenderWindow_setFramerateLimit(win->win, 60);
    win->is_fullscreen = false;
    return win;
}
