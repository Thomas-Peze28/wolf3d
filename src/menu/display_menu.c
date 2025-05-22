/*
** EPITECH PROJECT, 2024
** wolf3D
** File description:
** main
*/

#include "wolf.h"

void display_button(sfRenderWindow *win, menu_t *menu)
{
    sfRenderWindow_drawSprite(win,
        menu->main_menu->background_sprite, NULL);
    sfRenderWindow_drawSprite(win,
        menu->main_menu->play_button_sprite, NULL);
    sfRenderWindow_drawSprite(win,
        menu->main_menu->settings_button_sprite, NULL);
    sfRenderWindow_drawSprite(win,
        menu->main_menu->exit_button_sprite, NULL);
}

int analyze_menu_event(game_t *game)
{
    if (game->window->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window->win);
    if (is_button_clicked(MAIN_MENU->play_button_sprite, game->window->event))
        return 0;
    if (is_button_clicked(MAIN_MENU->exit_button_sprite, game->window->event))
        sfRenderWindow_close(game->window->win);
    if (is_button_clicked(MAIN_MENU->settings_button_sprite,
        game->window->event)) {
        display_options_menu(game);
    }
    return 1;
}

int display_menu(game_t *game)
{
    int status = 1;

    sfRenderWindow_setMouseCursorVisible(game->window->win, sfTrue);
    while (sfRenderWindow_isOpen(game->window->win)) {
        while (sfRenderWindow_pollEvent(game->window->win,
            &game->window->event)) {
            status = analyze_menu_event(game);
        }
        if (status == 0) {
            sfRenderWindow_setMouseCursorVisible(game->window->win, sfFalse);
            sfRenderWindow_clear(game->window->win, sfBlack);
            return 0;
        }
        sfRenderWindow_clear(game->window->win, sfBlack);
        display_button(game->window->win, game->graphics->menu);
        sfRenderWindow_display(game->window->win);
    }
    return 0;
}
