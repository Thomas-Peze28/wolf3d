/*
** EPITECH PROJECT, 2024
** init_graphics
** File description:
** main
*/

#include "wolf.h"

void draw_rain_particles(game_t *game, int nb)
{
    float x = 0.0;
    float y = 0.0;
    sfCircleShape *circle = NULL;

    for (int i = 0; i < nb; i++) {
        circle = sfCircleShape_create();
        x = rand() % (int)game->window->mode.width;
        y = rand() % (int)game->window->mode.height;
        sfCircleShape_setRadius(circle, 3);
        sfCircleShape_setFillColor(circle, sfRed);
        sfCircleShape_setPosition(circle, (sfVector2f){x, y});
        sfRenderWindow_drawCircleShape(game->window->win, circle, NULL);
        sfCircleShape_destroy(circle);
    }
}
