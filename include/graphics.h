/*
** EPITECH PROJECT, 2023
** include
** File description:
** map.h
*/


#ifndef GRAPHICS_H
    #define GRAPHICS_H

    #include "wolf.h"
typedef struct main_s {
    sfSprite *background_sprite;
    sfTexture *background_texture;
    sfIntRect background_rect;
    sfSprite *play_button_sprite;
    sfTexture *play_button_texture;
    sfIntRect play_button_rect;
    sfSprite *exit_button_sprite;
    sfTexture *exit_button_texture;
    sfIntRect exit_button_rect;
    sfSprite *settings_button_sprite;
    sfTexture *settings_button_texture;
    sfIntRect settings_button_rect;
} main_t;

typedef struct options_s {
    sfFont *font;
    sfText *fullscreen_btn;
    sfText *sound_text;
    sfRectangleShape *sound_slider_bar;
    sfRectangleShape *sound_slider_cursor;
    float sound_volume;
} options_t;

typedef struct menu_s {
    main_t *main_menu;
    options_t *options_menu;
} menu_t;

typedef struct hud_s {
    sfTexture *gun;
    sfSprite *poke_blaster;
    sfRectangleShape *banner;
    sfText *life_stat;
    sfText *points;
} hud_t;

typedef struct graphics_s {
    sfRectangleShape *floor;
    sfRectangleShape *ceilling;
    sfSprite *wall_sprite;
    sfTexture *wall_texture;
    sfIntRect wall_rect;
    menu_t *menu;
    // mobs_t *textures;
    sfTexture *pokeball;
    sfSprite *cursor;
    hud_t *hud;
} graphics_t;

#endif
