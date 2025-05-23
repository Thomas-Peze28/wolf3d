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

void play_game_over_sound(void)
{
    sfSound *mimikyu = init_sound("assets/sound/mimikyu.ogg", 100);

    if (mimikyu) {
        sfSound_play(mimikyu);
        sfSound_destroy(mimikyu);
    }
}

void display_game_over(game_t *game)
{
    sfTexture *texture = sfTexture_createFromFile(
        "assets/game_over1.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfClock *clock = sfClock_create();

    play_game_over_sound();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1.25f, 1.08f});
    draw_game_over_screen(game, sprite);
    while (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < 10.0f) {
        while (sfRenderWindow_pollEvent(game->window->win,
            &game->window->event)) {
            handle_game_over_event(game);
        }
        draw_rain_particles(game, 100);
        sfRenderWindow_display(game->window->win);
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfClock_destroy(clock);
}
