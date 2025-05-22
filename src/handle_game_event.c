/*
** EPITECH PROJECT, 2024
** wolf3D
** File description:
** main
*/

#include "wolf.h"

int analyze_event(game_t *game, shoot_t *shoot)
{
    if (game->window->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window->win);
    if (game->window->event.type == sfEvtKeyPressed) {
        if (game->window->event.key.code == sfKeyEscape)
            display_menu(game);
    }
    if (game->window->event.type == sfEvtMouseMoved) {
        sfSprite_setPosition(game->graphics->cursor,
            (sfVector2f){game->window->event.mouseMove.x,
                game->window->event.mouseMove.y});
    }
    if (game->window->event.type == sfEvtMouseButtonPressed)
        shoot->shoot = 1;
    return 0;
}

void handle_events(game_t *game, shoot_t *shoot)
{
    while (sfRenderWindow_pollEvent(game->window->win,
        &game->window->event))
        analyze_event(game, shoot);
}
