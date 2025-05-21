/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_enemies
*/

#include "wolf.h"

void update_gastly_anim(gastly_t *gastly)
{
    move_rect(&gastly->rect, 67, 26800);
    sfSprite_setTextureRect(gastly->sprite, gastly->rect);
}

void update_mimikyu_anim(mimikyu_t *mimikyu)
{
    move_rect(&mimikyu->rect, 57, 2223);
    sfSprite_setTextureRect(mimikyu->sprite, mimikyu->rect);
}
