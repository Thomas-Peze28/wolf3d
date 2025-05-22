/*
** EPITECH PROJECT, 2024
** init_graphics
** File description:
** main
*/

#include "wolf.h"

void init_floor_and_ceiling(graphics_t *graphics, game_t *game)
{
    graphics->floor = sfRectangleShape_create();
    graphics->ceilling = sfRectangleShape_create();
    sfRectangleShape_setFillColor(graphics->floor,
        sfColor_fromRGB(96, 96, 96));
    sfRectangleShape_setFillColor(graphics->ceilling,
        sfColor_fromRGB(64, 64, 64));
    sfRectangleShape_setSize(graphics->floor,
        (sfVector2f){game->window->mode.width, game->window->mode.height / 2});
    sfRectangleShape_setSize(graphics->ceilling,
        (sfVector2f){game->window->mode.width, game->window->mode.height / 2});
    sfRectangleShape_setPosition(graphics->floor,
        (sfVector2f){0, game->window->mode.height / 2});
    sfRectangleShape_setPosition(graphics->ceilling, (sfVector2f){0, 0});
}

void init_wall(graphics_t *graphics)
{
    graphics->wall_rect = (sfIntRect){0, 0, 64, 64};
    graphics->wall_texture = sfTexture_createFromFile(
        "assets/stone_wall.jpg", NULL);
    graphics->wall_sprite = sfSprite_create();
    sfSprite_setTexture(graphics->wall_sprite, graphics->wall_texture, sfTrue);
    sfSprite_setTextureRect(graphics->wall_sprite, graphics->wall_rect);
}

static void init_cursor(graphics_t *graphics)
{
    sfSprite_setTexture(graphics->cursor, graphics->pokeball, sfTrue);
    sfSprite_setPosition(graphics->cursor, (sfVector2f){100, 100});
    sfSprite_setTextureRect(graphics->cursor, (sfIntRect){0, 0, 64, 64});
    sfSprite_setOrigin(graphics->cursor, (sfVector2f){32, 32});
    sfSprite_rotate(graphics->cursor, 180.0);
}

static void init_pokeblaster(graphics_t *graphics)
{
    sfSprite_setTexture(graphics->hud->poke_blaster,
        graphics->hud->gun, sfTrue);
    sfSprite_setPosition(graphics->hud->poke_blaster,
        (sfVector2f){((WINDOW_WIDTH / 2) - ((185 * 3) / 2)),
            WINDOW_HEIGHT - (195 * 2)});
    sfSprite_setTextureRect(graphics->hud->poke_blaster,
        (sfIntRect){0, 0, 185, 192});
    sfSprite_setScale(graphics->hud->poke_blaster, (sfVector2f){3, 3});
}

void init_life_bar(hud_t *hud)
{
    hud->life_bar_bg = sfRectangleShape_create();
    sfRectangleShape_setSize(hud->life_bar_bg, (sfVector2f){300, 35});
    sfRectangleShape_setFillColor(hud->life_bar_bg,
        sfColor_fromRGB(50, 50, 50));
    sfRectangleShape_setPosition(hud->life_bar_bg, (sfVector2f){30, 900});
    hud->life_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(hud->life_bar, (sfVector2f){300, 30});
    sfRectangleShape_setFillColor(hud->life_bar, sfGreen);
    sfRectangleShape_setPosition(hud->life_bar, (sfVector2f){30, 900});
}

graphics_t *init_graphics(game_t *game)
{
    graphics_t *graphics = malloc(sizeof(graphics_t));

    if (!graphics)
        return NULL;
    init_floor_and_ceiling(graphics, game);
    init_wall(graphics);
    if (!graphics->floor || !graphics->ceilling)
        return NULL;
    graphics->pokeball = sfTexture_createFromFile("assets/pokeball.png", NULL);
    graphics->cursor = sfSprite_create();
    init_cursor(graphics);
    graphics->hud = malloc(sizeof(hud_t));
    graphics->hud->gun =
        sfTexture_createFromFile("assets/pokeblasterss.png", NULL);
    graphics->hud->poke_blaster = sfSprite_create();
    init_pokeblaster(graphics);
    init_life_bar(graphics->hud);
    return graphics;
}
