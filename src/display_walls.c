/*
** EPITECH PROJECT, 2024
** day_13
** File description:
** main
*/

#include "wolf.h"

int calcuate_rays_dist(game_t *game)
{
    float dist = 0;
    sfVector2f start = {0, 0};
    sfVector2f end = {0, 0};

    for (int index = 0; index < NUM_RAYS; index++) {
        start = game->player->view_field[index]->start;
        end = game->player->view_field[index]->end;
        dist = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
        game->player->view_field[index]->distance = dist;
    }
    return 0;
}

void create_wall(game_t *game, int i, float dist, float wall_height)
{
    sfVector2f size = {1, wall_height};
    sfVector2f position = {i * (game->window->mode.width / NUM_RAYS),
        (game->window->mode.height - wall_height) / 2};
    sfColor color = sfColor_fromRGB(150 - dist, 75, 0);

    sfRectangleShape_setSize(game->player->view_field[i]->wall, size);
    sfRectangleShape_setPosition(game->player->view_field[i]->wall, position);
    sfRectangleShape_setFillColor(game->player->view_field[i]->wall, color);
    sfRenderWindow_drawRectangleShape(game->window->win,
        game->player->view_field[i]->wall, NULL);
}

void display_rays_walls(game_t *game)
{
    float dist = 0;
    float corrected_dist = 0;
    float wall_height = 0;

    for (int i = 0; i < 1920; i++) {
        if (game->player->view_field[i]->distance == 0)
            continue;
        dist = game->player->view_field[i]->distance;
        corrected_dist = dist * cos(game->player->angle
            - game->player->view_field[i]->angle);
        wall_height = (TILE_SIZE / corrected_dist) * (WINDOW_WIDTH / 2);
        create_wall(game, i, corrected_dist, wall_height);
    }
}
