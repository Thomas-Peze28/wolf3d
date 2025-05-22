/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_enemies
*/

#include "wolf.h"

void set_gastly(gastly_t *gastly, int **map)
{
    while (map[(int)(gastly->y / TILE_SIZE)]
    [(int)(gastly->x / TILE_SIZE)] == 1) {
        gastly->x = (rand() % MAP_WIDTH) *
        TILE_SIZE + TILE_SIZE / 2;
        gastly->y = (rand() % MAP_HEIGHT) *
        TILE_SIZE + TILE_SIZE / 2;
    }
    gastly->sprite = sfSprite_create();
    if (gastly->shiny == 1)
        gastly->texture = sfTexture_createFromFile(
            "assets/spritesheet/gastly_shiny.png", NULL);
    else
        gastly->texture = sfTexture_createFromFile(
            "assets/spritesheet/gastly.png", NULL);
    gastly->rect = (sfIntRect){0, 0, 67, 76};
    gastly->frame = 0;
    gastly->nb_frame = 144;
    sfSprite_setTextureRect(gastly->sprite, gastly->rect);
    sfSprite_setTexture(gastly->sprite, gastly->texture, sfTrue);
}

gastly_t *init_gastly(gastly_t *gastly, int **map)
{
    gastly = malloc(sizeof(gastly_t));
    if (!gastly)
        return NULL;
    gastly->evolution = GASTLY;
    gastly->attack = 1 + ((rand() / 5) + 1) * gastly->evolution;
    gastly->aim = 10 + (10 * gastly->evolution);
    gastly->shiny = (rand() % 5) == 0;
    gastly->x = (rand() % MAP_WIDTH) * TILE_SIZE + TILE_SIZE / 2;
    gastly->y = (rand() % MAP_HEIGHT) * TILE_SIZE + TILE_SIZE / 2;
    gastly->is_alive = true;
    set_gastly(gastly, map);
    return gastly;
}

void set_mimukyu(mimikyu_t *mimikyu, int **map)
{
    while (map[(int)(mimikyu->y / TILE_SIZE)]
    [(int)(mimikyu->x / TILE_SIZE)] == 1) {
        mimikyu->x = (rand() % MAP_WIDTH) *
        TILE_SIZE + TILE_SIZE / 2;
        mimikyu->y = (rand() % MAP_HEIGHT) *
        TILE_SIZE + TILE_SIZE / 2;
    }
    mimikyu->sprite = sfSprite_create();
    if (mimikyu->shiny == 1)
        mimikyu->texture = sfTexture_createFromFile(
            "assets/spritesheet/mimikyu_shiny.png", NULL);
    else
        mimikyu->texture = sfTexture_createFromFile(
            "assets/spritesheet/mimikyu.png", NULL);
    sfSprite_setTexture(mimikyu->sprite, mimikyu->texture, sfTrue);
    mimikyu->rect = (sfIntRect){0, 0, 57, 67};
    mimikyu->frame = 0;
    mimikyu->nb_frame = 39;
    sfSprite_setTextureRect(mimikyu->sprite, mimikyu->rect);
    sfSprite_setTexture(mimikyu->sprite, mimikyu->texture, sfTrue);
}

mimikyu_t *init_mimikyu(mimikyu_t *mimikyu, int **map)
{
    mimikyu = malloc(sizeof(mimikyu_t));
    if (!mimikyu)
        return NULL;
    mimikyu->attack = 10;
    mimikyu->aim = 10;
    mimikyu->shiny = (rand() % 5) == 0;
    mimikyu->x = (rand() % MAP_WIDTH) * TILE_SIZE + TILE_SIZE / 2;
    mimikyu->y = (rand() % MAP_HEIGHT) * TILE_SIZE + TILE_SIZE / 2;
    mimikyu->is_alive = true;
    set_mimukyu(mimikyu, map);
    return mimikyu;
}
