/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** display
*/

#include "wolf.h"

void draw_2d_map(game_t *game)
{
    for (int i = 0; i < game->map->height; i++) {
        for (int j = 0; j < game->map->width; j++) {
            sfRenderWindow_drawRectangleShape(
                game->window->win,
                game->map->tiles[i][j]->tile,
                NULL);
        }
    }
}

static void print_player_view(player_t *player, window_t *window)
{
    int i = 0;

    while (i < NUM_RAYS) {
        sfRenderWindow_drawVertexArray(window->win,
            player->view_field[i]->line, NULL);
        i++;
    }
}

int display_player(game_t *game)
{
    sfCircleShape_setPosition(game->player->avatar,
        (sfVector2f){game->player->x, game->player->y});
    sfCircleShape_setOrigin(game->player->avatar,
        (sfVector2f){TILE_SIZE / 2,
        TILE_SIZE / 2});
    print_player_view(game->player, game->window);
    sfRenderWindow_drawCircleShape(game->window->win,
        game->player->avatar, NULL);
    return 0;
}
