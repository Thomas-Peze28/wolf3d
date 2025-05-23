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
    display_score(game);
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

void render_game(game_t *game)
{
    float life_ratio = (float)game->player->health / 100.0f;

    if (life_ratio < 0)
        life_ratio = 0;
    sfRectangleShape_setSize(game->graphics->hud->life_bar,
        (sfVector2f){300 * life_ratio, 30});
    sfRenderWindow_clear(game->window->win, sfBlack);
    draw_ceilling_floor(game);
    manage_rays(game);
    draw_minimap(game);
    display_ennemies(game);
    sfRenderWindow_drawSprite(game->window->win, game->graphics->cursor, NULL);
    sfRenderWindow_drawSprite(game->window->win,
        game->graphics->hud->poke_blaster, NULL);
    sfRenderWindow_drawRectangleShape(game->window->win,
        game->graphics->hud->life_bar_bg, NULL);
    sfRenderWindow_drawRectangleShape(game->window->win,
        game->graphics->hud->life_bar, NULL);
}

int game_loop(game_t *game, shoot_t *shoot)
{
    game->ennmies_alive = count_ennemies(game->gastly_tab,
        game->mimikyu_tab);
    handle_shoot(game, shoot);
    handle_key_pressed(game);
    enemies_attack_player(game);
    render_game(game);
    return 0;
}
