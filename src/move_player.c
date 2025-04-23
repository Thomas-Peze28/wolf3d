/*
** EPITECH PROJECT, 2024
** day_13
** File description:
** main
*/

#include "wolf.h"

int move_player(player_t *player, map_t *map, float new_x, float new_y)
{
    if (!is_wall(map, new_x + 1, new_y + 1)) {
        player->x = new_x;
        player->y = new_y;
    }
    return 0;
}

void handle_player_movement(game_t *game, player_t *player, map_t *map)
{
    float new_x = player->x;
    float new_y = player->y;

    if (game->window->event.key.code == sfKeyZ) {
        new_x = game->player->x + cos(game->player->angle) * player->speed;
        new_y = game->player->y + sin(game->player->angle) * player->speed;
    }
    if (game->window->event.key.code == sfKeyS) {
        new_x = game->player->x - cos(game->player->angle) * player->speed;
        new_y = game->player->y - sin(game->player->angle) * player->speed;
    }
    if (game->window->event.key.code == sfKeyQ) {
        new_x = game->player->x + sin(game->player->angle) * player->speed;
        new_y = game->player->y - cos(game->player->angle) * player->speed;
    }
    if (game->window->event.key.code == sfKeyD) {
        new_x = game->player->x - sin(game->player->angle) * player->speed;
        new_y = game->player->y + cos(game->player->angle) * player->speed;
    }
    move_player(player, map, new_x, new_y);
}
