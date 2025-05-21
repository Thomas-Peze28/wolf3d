/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** display
*/

#include "wolf.h"

int manage_rays(game_t *game)
{
    cast_all_rays(game);
    calcuate_rays_dist(game);
    display_rays_walls(game);
    return 0;
}

int draw_minimap(game_t *game)
{
    display_fps(game);
    draw_2d_map(game);
    display_player(game);
    return 0;
}

int draw_ceilling_floor(game_t *game)
{
    sfRenderWindow_drawRectangleShape(game->window->win,
        game->graphics->floor, NULL);
    sfRenderWindow_drawRectangleShape(game->window->win,
        game->graphics->ceilling, NULL);
    return 0;
}

static void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value)
        rect->left += offset;
    if (rect->left >= max_value)
        rect->left = 0;
}

int game_loop(game_t *game, int *shoot, int *nb_frame_ball, int *nb_frame_gun,
    sfIntRect *rect, sfIntRect *hud_rect)
{
    if (*shoot == 1) {
        if (*nb_frame_gun != 7) {
            move_rect(hud_rect, 186, 1298);
            sfSprite_setTextureRect(game->graphics->hud->poke_blaster,
                *hud_rect);
            sfRenderWindow_drawSprite(game->window->win,
                game->graphics->hud->poke_blaster, NULL);
            (*nb_frame_gun)++;
        }
        if (*nb_frame_ball != 12) {
            move_rect(rect, 64, 768);
            sfSprite_setTextureRect(game->graphics->cursor, *rect);
            sfRenderWindow_drawSprite(game->window->win,
                game->graphics->cursor, NULL);
            (*nb_frame_ball)++;
        }
        if (*nb_frame_ball == 12) {
            *shoot = 0;
            *nb_frame_ball = 0;
            *nb_frame_gun = 0;
        }
    }
    handle_key_pressed(game);
    sfRenderWindow_clear(game->window->win, sfBlack);
    draw_ceilling_floor(game);
    manage_rays(game);
    draw_minimap(game);
    sfRenderWindow_drawSprite(game->window->win, game->graphics->cursor, NULL);
    sfRenderWindow_drawSprite(game->window->win,
        game->graphics->hud->poke_blaster, NULL);
    return 0;
}
