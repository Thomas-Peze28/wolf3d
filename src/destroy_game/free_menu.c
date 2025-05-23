/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** free_game
*/

#include "wolf.h"

int free_main_menu(main_t *main_menu)
{
    if (!main_menu)
        return 0;
    if (main_menu->background_sprite)
        sfSprite_destroy(main_menu->background_sprite);
    if (main_menu->background_texture)
        sfTexture_destroy(main_menu->background_texture);
    if (main_menu->play_button_sprite)
        sfSprite_destroy(main_menu->play_button_sprite);
    if (main_menu->play_button_texture)
        sfTexture_destroy(main_menu->play_button_texture);
    if (main_menu->exit_button_sprite)
        sfSprite_destroy(main_menu->exit_button_sprite);
    if (main_menu->exit_button_texture)
        sfTexture_destroy(main_menu->exit_button_texture);
    if (main_menu->settings_button_sprite)
        sfSprite_destroy(main_menu->settings_button_sprite);
    if (main_menu->settings_button_texture)
        sfTexture_destroy(main_menu->settings_button_texture);
    free(main_menu);
    return 0;
}

int free_options_menu(options_t *options)
{
    if (!options)
        return 0;
    if (options->font)
        sfFont_destroy(options->font);
    if (options->fullscreen_btn)
        sfText_destroy(options->fullscreen_btn);
    if (options->sound_text)
        sfText_destroy(options->sound_text);
    if (options->sound_slider_bar)
        sfRectangleShape_destroy(options->sound_slider_bar);
    if (options->sound_slider_cursor)
        sfRectangleShape_destroy(options->sound_slider_cursor);
    if (options->aiming_btn)
        sfText_destroy(options->aiming_btn);
    free(options);
    return 0;
}

int free_menu(menu_t *menu)
{
    if (!menu)
        return 0;
    if (menu->main_menu)
        free_main_menu(menu->main_menu);
    if (menu->options_menu)
        free_options_menu(menu->options_menu);
    free(menu);
    return 0;
}
