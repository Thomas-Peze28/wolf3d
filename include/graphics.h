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
} options_t;

typedef struct menu_s {
    main_t *main_menu;
    options_t *options_menu;
} menu_t;

// typedef struct hud_s {
//     sfSprite *gun_sprite;
//     sfTexture *gun_texture;
//     sfIntRect gun_rect;
// } hud_t;

typedef struct hud_s {
    sfTexture *gun;
    sfSprite *poke_blaster;
    sfRectangleShape *banner;
    sfText *life_stat;
    sfText *points;
} hud_t;

// typedef struct mobs_s {
//     sfTexture *mimikyu;
//     sfTexture *gastly;
//     sfTexture *haunter;
//     sfTexture *gengar;
//     sfTexture *mega_gengar;
//     sfTexture *shiny_mimikyu;
//     sfTexture *shiny_gastly;
//     sfTexture *shiny_haunter;
//     sfTexture *shiny_gengar;
//     sfTexture *shiny_mega_gengar;
// } mobs_t;

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
