/*
** EPITECH PROJECT, 2024
** wolf3D
** File description:
** main
*/

#include "wolf.h"

void manage_btn(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window->win);
    sfFloatRect slider_bounds = sfRectangleShape_getGlobalBounds(
        OPTION_MENU->sound_slider_bar);

    if (is_mouse_clicked(game->window->event, sfMouseLeft)
        && is_button_clicked_rect(
            sfText_getGlobalBounds(OPTION_MENU->fullscreen_btn),
            sfMouse_getPositionRenderWindow(game->window->win))) {
        toggle_fullscreen(game);
    }
    if (is_mouse_clicked(game->window->event, sfMouseLeft)
        && is_button_clicked_rect(
            sfText_getGlobalBounds(OPTION_MENU->aiming_btn),
            sfMouse_getPositionRenderWindow(game->window->win))) {
        OPTION_MENU->aiming_move = !OPTION_MENU->aiming_move;
    }
    if (is_mouse_clicked(game->window->event, sfMouseLeft)
        && sfFloatRect_contains(&slider_bounds, mouse.x, mouse.y)) {
        change_volume(game, mouse);
    }
}

int analyze_option_event(game_t *game)
{
    if (game->window->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window->win);
    if (is_key_pressed(game->window->event, sfKeyEscape))
        return 0;
    manage_btn(game);
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
    sfRenderWindow_drawText(game->window->win,
        OPTION_MENU->aiming_btn, NULL);
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
        if (OPTION_MENU->aiming_move == true)
            sfText_setString(OPTION_MENU->aiming_btn, "Aim mode : Mouse");
        else
            sfText_setString(OPTION_MENU->aiming_btn, "Aim mode : Center");
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
