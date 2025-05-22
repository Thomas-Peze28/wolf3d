/*
** EPITECH PROJECT, 2024
** init_graphics
** File description:
** main
*/

#include "wolf.h"

void handle_game_over_event(game_t *game)
{
    if (game->window->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window->win);
    if (is_key_pressed(game->window->event, sfKeyEscape))
        sfRenderWindow_close(game->window->win);
}

void draw_game_over_screen(game_t *game, sfSprite *sprite)
{
    sfRenderWindow_clear(game->window->win, sfRed);
    sfRenderWindow_drawSprite(game->window->win, sprite, NULL);
    sfRenderWindow_display(game->window->win);
}

void display_game_over(game_t *game)
{
    sfTexture *texture = sfTexture_createFromFile(
        "assets/game_over2.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfClock *clock = sfClock_create();

    if (!texture || !sprite)
        return;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1.2f, 1.2f});
    draw_game_over_screen(game, sprite);
    while (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < 5.0f) {
        while (sfRenderWindow_pollEvent(game->window->win,
            &game->window->event)) {
            handle_game_over_event(game);
        }
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfClock_destroy(clock);
}
