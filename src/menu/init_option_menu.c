/*
** EPITECH PROJECT, 2024
** wolf3D
** File description:
** main
*/

#include "wolf.h"

void init_options_menu_fullscreen_btn(options_t *options_menu)
{
    options_menu->fullscreen_btn = sfText_create();
    sfText_setFont(options_menu->fullscreen_btn, options_menu->font);
    sfText_setString(options_menu->fullscreen_btn, "Fullscreen");
    sfText_setCharacterSize(options_menu->fullscreen_btn, 60);
    sfText_setPosition(options_menu->fullscreen_btn,
        (sfVector2f){WINDOW_WIDTH / 2 - 200, 400});
    sfText_setFillColor(options_menu->fullscreen_btn, sfYellow);
}

void init_options_aim_fullscreen_btn(options_t *options_menu)
{
    options_menu->aiming_btn = sfText_create();
    sfText_setFont(options_menu->aiming_btn, options_menu->font);
    sfText_setString(options_menu->aiming_btn, "Aim mode");
    sfText_setCharacterSize(options_menu->aiming_btn, 60);
    sfText_setPosition(options_menu->aiming_btn,
        (sfVector2f){WINDOW_WIDTH / 2 - 200, 800});
    sfText_setFillColor(options_menu->aiming_btn, sfYellow);
    options_menu->aiming_move = false;
}

void init_options_menu_sound_slider(options_t *options_menu)
{
    options_menu->sound_slider_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(options_menu->sound_slider_bar,
        (sfVector2f){300, 10});
    sfRectangleShape_setFillColor(options_menu->sound_slider_bar, sfWhite);
    sfRectangleShape_setPosition(options_menu->sound_slider_bar,
        (sfVector2f){WINDOW_WIDTH / 2 - 150, 600});
    options_menu->sound_slider_cursor = sfRectangleShape_create();
    sfRectangleShape_setSize(options_menu->sound_slider_cursor,
        (sfVector2f){20, 40});
    sfRectangleShape_setFillColor(options_menu->sound_slider_cursor, sfYellow);
    sfRectangleShape_setPosition(options_menu->sound_slider_cursor,
        (sfVector2f){WINDOW_WIDTH / 2 - 150, 590});
}

void init_options_menu_sound_text(options_t *options_menu)
{
    options_menu->sound_text = sfText_create();
    sfText_setString(options_menu->sound_text, "Volume");
    sfText_setFont(options_menu->sound_text, options_menu->font);
    sfText_setCharacterSize(options_menu->sound_text, 32);
    sfText_setFillColor(options_menu->sound_text, sfWhite);
    sfText_setPosition(options_menu->sound_text,
        (sfVector2f){WINDOW_WIDTH / 2 - 50, 550});
}

options_t *init_options_menu(void)
{
    options_t *options_menu = malloc(sizeof(options_t));

    if (!options_menu)
        return NULL;
    options_menu->font = sfFont_createFromFile("assets/Roboto-Black.ttf");
    init_options_menu_fullscreen_btn(options_menu);
    init_options_aim_fullscreen_btn(options_menu);
    init_options_menu_sound_slider(options_menu);
    init_options_menu_sound_text(options_menu);
    options_menu->sound_volume = 50;
    return options_menu;
}
