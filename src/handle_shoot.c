/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** display
*/

#include "wolf.h"

int is_enemy_shot(game_t *game, float ennemy_x, float ennemy_y)
{
    float dx = ennemy_x - game->player->x;
    float dy = ennemy_y - game->player->y;
    float dist = sqrtf(dx * dx + dy * dy);
    float angle_to_enemy = atan2f(dy, dx);
    float rel_angle = normalize_angle(angle_to_enemy - game->player->angle);
    int col = 0;

    if (fabs(rel_angle) < 0.05f) {
        col = (int)((rel_angle + (FOV / 2)) / FOV * WINDOW_WIDTH) *
        NUM_RAYS / WINDOW_WIDTH;
        if (col < 0)
            col = 0;
        if (col >= NUM_RAYS)
            col = NUM_RAYS - 1;
        if (dist < game->map->wall_dist[col])
            return 1;
    }
    return 0;
}

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

void check_enemies_shot(game_t *game)
{
    for (int i = 0; game->gastly_tab[i] != NULL; i++) {
        if (is_enemy_shot(game, game->gastly_tab[i]->x,
            game->gastly_tab[i]->y))
            game->gastly_tab[i]->is_alive = 0;
    }
    for (int i = 0; game->mimikyu_tab[i] != NULL; i++) {
        if (is_enemy_shot(game, game->mimikyu_tab[i]->x,
            game->mimikyu_tab[i]->y))
            game->mimikyu_tab[i]->is_alive = 0;
    }
}

void handle_shoot(game_t *game, shoot_t *shoot)
{
    if (shoot->shoot == 1) {
        animate_gun(game, shoot);
        animate_bullet(game, shoot);
        check_enemies_shot(game);
        if (shoot->nb_frame_ball == 12) {
            shoot->shoot = 0;
            shoot->nb_frame_ball = 0;
            shoot->nb_frame_gun = 0;
        }
    }
}
