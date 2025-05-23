/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** display
*/

#include "wolf.h"

void animate_gun(game_t *game, shoot_t *shoot)
{
    if (shoot->nb_frame_gun != 7) {
        move_rect(&shoot->hud_rect, 186, 1298);
        sfSprite_setTextureRect(game->graphics->hud->poke_blaster,
            shoot->hud_rect);
        sfRenderWindow_drawSprite(game->window->win,
            game->graphics->hud->poke_blaster, NULL);
        shoot->nb_frame_gun++;
    }
}

void animate_bullet(game_t *game, shoot_t *shoot)
{
    if (shoot->nb_frame_ball != 12) {
        move_rect(&shoot->rect, 64, 768);
        sfSprite_setTextureRect(game->graphics->cursor, shoot->rect);
        sfRenderWindow_drawSprite(game->window->win,
            game->graphics->cursor, NULL);
        shoot->nb_frame_ball++;
    }
}

void check_ennemies_shot_mouse(game_t *game)
{
    for (int i = 0; game->gastly_tab[i] != NULL; i++) {
        if (is_enemy_sprite_shot(game, game->gastly_tab[i]->sprite)) {
            game->gastly_tab[i]->is_alive = 0;
            check_gain_gastly_health(game, game->gastly_tab[i]);
        }
    }
    for (int i = 0; game->mimikyu_tab[i] != NULL; i++) {
        if (is_enemy_sprite_shot(game, game->mimikyu_tab[i]->sprite)) {
            game->mimikyu_tab[i]->is_alive = 0;
            check_gain_mimikyu_health(game, game->mimikyu_tab[i]);
        }
    }
}

void check_ennemies_shot(game_t *game)
{
    for (int i = 0; game->gastly_tab[i] != NULL; i++) {
        if (is_enemy_shot(game, game->gastly_tab[i]->x,
            game->gastly_tab[i]->y)) {
            game->gastly_tab[i]->is_alive = 0;
            check_gain_gastly_health(game, game->gastly_tab[i]);
        }
    }
    for (int i = 0; game->mimikyu_tab[i] != NULL; i++) {
        if (is_enemy_shot(game, game->mimikyu_tab[i]->x,
            game->mimikyu_tab[i]->y)) {
            game->mimikyu_tab[i]->is_alive = 0;
            check_gain_mimikyu_health(game, game->mimikyu_tab[i]);
        }
    }
}

void handle_shoot(game_t *game, shoot_t *shoot)
{
    if (shoot->shoot == 1) {
        animate_gun(game, shoot);
        animate_bullet(game, shoot);
        if (game->graphics->menu->options_menu->aiming_move == true)
            check_ennemies_shot_mouse(game);
        else
            check_ennemies_shot(game);
        if (shoot->nb_frame_ball == 12) {
            shoot->shoot = 0;
            shoot->nb_frame_ball = 0;
            shoot->nb_frame_gun = 0;
        }
    }
}
