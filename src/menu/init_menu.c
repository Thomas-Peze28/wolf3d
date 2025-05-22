/*
** EPITECH PROJECT, 2024
** wolf3D
** File description:
** main
*/

#include "wolf.h"

static void init_main_menu_background(main_t *main_menu)
{
    main_menu->background_texture = sfTexture_createFromFile(
        "assets/menu_bg.png", NULL);
    main_menu->background_sprite = sfSprite_create();
    sfSprite_setTexture(main_menu->background_sprite,
        main_menu->background_texture, sfTrue);
    sfSprite_setScale(main_menu->background_sprite, (sfVector2f){1.7, 1.7});
}

static void init_main_menu_play_button(main_t *main_menu)
{
    main_menu->play_button_texture = sfTexture_createFromFile(
        "assets/start_btn.png", NULL);
    main_menu->play_button_sprite = sfSprite_create();
    sfSprite_setTexture(main_menu->play_button_sprite,
        main_menu->play_button_texture, sfTrue);
    sfSprite_setPosition(main_menu->play_button_sprite,
        (sfVector2f){WINDOW_WIDTH / 2 - 700, 700});
}

static void init_main_menu_exit_button(main_t *main_menu)
{
    main_menu->exit_button_texture = sfTexture_createFromFile(
        "assets/exit_btn.png", NULL);
    main_menu->exit_button_sprite = sfSprite_create();
    sfSprite_setTexture(main_menu->exit_button_sprite,
        main_menu->exit_button_texture, sfTrue);
    sfSprite_setPosition(main_menu->exit_button_sprite,
        (sfVector2f){WINDOW_WIDTH / 2 + 400, 700});
}

static void init_main_menu_settings_button(main_t *main_menu)
{
    main_menu->settings_button_texture = sfTexture_createFromFile(
        "assets/options_btn.png", NULL);
    main_menu->settings_button_sprite = sfSprite_create();
    sfSprite_setTexture(main_menu->settings_button_sprite,
        main_menu->settings_button_texture, sfTrue);
    sfSprite_setPosition(main_menu->settings_button_sprite,
        (sfVector2f){WINDOW_WIDTH / 2 - 150, 900});
}

main_t *init_main_menu(void)
{
    main_t *main_menu = malloc(sizeof(main_t));

    if (!main_menu)
        return NULL;
    init_main_menu_background(main_menu);
    init_main_menu_play_button(main_menu);
    init_main_menu_exit_button(main_menu);
    init_main_menu_settings_button(main_menu);
    return main_menu;
}

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    if (!menu)
        return NULL;
    menu->main_menu = init_main_menu();
    menu->options_menu = init_options_menu();
    return menu;
}
