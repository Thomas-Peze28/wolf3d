/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** free_game
*/

#include "wolf.h"

int free_hud(hud_t *hud)
{
    if (!hud)
        return 0;
    if (hud->gun)
        sfTexture_destroy(hud->gun);
    if (hud->poke_blaster)
        sfSprite_destroy(hud->poke_blaster);
    if (hud->banner)
        sfRectangleShape_destroy(hud->banner);
    if (hud->life_stat)
        sfText_destroy(hud->life_stat);
    if (hud->points)
        sfText_destroy(hud->points);
    if (hud->life_bar_bg)
        sfRectangleShape_destroy(hud->life_bar_bg);
    if (hud->life_bar)
        sfRectangleShape_destroy(hud->life_bar);
    free(hud);
    return 0;
}
