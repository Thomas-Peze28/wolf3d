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

int analyze_option_event(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window->win);
    sfFloatRect slider_bounds = sfRectangleShape_getGlobalBounds(
        OPTION_MENU->sound_slider_bar);

    if (game->window->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window->win);
    if (is_key_pressed(game->window->event, sfKeyEscape))
        return 0;
    if (is_mouse_clicked(game->window->event, sfMouseLeft)
        && is_button_clicked_rect(
            sfText_getGlobalBounds(OPTION_MENU->fullscreen_btn),
            sfMouse_getPositionRenderWindow(game->window->win))) {
        toggle_fullscreen(game);
    }
    if (is_mouse_clicked(game->window->event, sfMouseLeft)
        && sfFloatRect_contains(&slider_bounds, mouse.x, mouse.y)) {
        change_volume(game, mouse);
    }
    return 1;
}

void draw_options_menu(game_t *game)
{
    sfRenderWindow_clear(game->window->win, sfBlack);
    sfRenderWindow_drawText(game->window->win,
        OPTION_MENU->fullscreen_btn, NULL);
    sfRenderWindow_drawRectangleShape(game->window->win,
        OPTION_MENU->sound_slider_bar, NULL);
    sfRenderWindow_drawRectangleShape(game->window->win,
        OPTION_MENU->sound_slider_cursor, NULL);
    sfRenderWindow_drawText(game->window->win,
        OPTION_MENU->sound_text, NULL);
    sfRenderWindow_display(game->window->win);
}

int display_options_menu(game_t *game)
{
    int status = 0;

    while (sfRenderWindow_isOpen(game->window->win)) {
        if (game->window->is_fullscreen == true)
            sfText_setString(OPTION_MENU->fullscreen_btn, "Plein ecran : ON");
        else
            sfText_setString(OPTION_MENU->fullscreen_btn, "Plein ecran : OFF");
        while (sfRenderWindow_pollEvent(game->window->win,
            &game->window->event)) {
            status = analyze_option_event(game);
        }
        if (status == 0)
            return 0;
        draw_options_menu(game);
    }
    return 0;
}
