/*
** EPITECH PROJECT, 2024
** wolf3D
** File description:
** main
*/

#include "wolf.h"

int toggle_fullscreen(game_t *game)
{
    sfVideoMode mode = {1920, 1080, 32};

    if (game->window->is_fullscreen == false)
        game->window->style = sfFullscreen;
    else
        game->window->style = sfResize | sfClose;
    sfRenderWindow_destroy(game->window->win);
    game->window->win = sfRenderWindow_create(mode, "Wolf3D",
        game->window->style, NULL);
    game->window->is_fullscreen = !game->window->is_fullscreen;
    return 0;
}

int change_volume(game_t *game, sfVector2i mouse)
{
    sfFloatRect slider_bounds = sfRectangleShape_getGlobalBounds(
        OPTION_MENU->sound_slider_bar);
    float rel_x = mouse.x - slider_bounds.left;
    float volume = (rel_x / slider_bounds.width) * 100.0f;
    float cursor_x = (WINDOW_WIDTH / 2 - 150) + (volume / 100.0f) * 300;

    if (!sfFloatRect_contains(&slider_bounds, mouse.x, mouse.y))
        return 0;
    if (volume < 0)
        volume = 0;
    if (volume > 100)
        volume = 100;
    OPTION_MENU->sound_volume = volume;
    sfMusic_setVolume(game->sounds->background_music, volume);
    sfRectangleShape_setPosition(OPTION_MENU->sound_slider_cursor,
        (sfVector2f){cursor_x, 590});
    return 0;
}
