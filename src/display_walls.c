/*
** EPITECH PROJECT, 2024
** day_13
** File description:
** main
*/

#include "wolf.h"

sfColor calculate_wall_color(float dist, sfColor base_color)
{
    float max_distance = 400.0f;
    float factor = 1.0 - (dist / max_distance);
    sfColor color = base_color;

    if (factor < 0.2f)
        factor = 0.2f;
    color = sfColor_fromRGB(
            base_color.r * factor,
            base_color.g * factor,
            base_color.b * factor);
    return color;
}

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
    float wall_width = (float)WINDOW_WIDTH / NUM_RAYS;
    sfVector2f size = {wall_width, wall_height};
    sfVector2f position = {i * (game->window->mode.width / NUM_RAYS),
        (game->window->mode.height - wall_height) / 2};
    sfColor base_color = sfColor_fromRGB(150, 75, 0);
    sfColor shaded_color = calculate_wall_color(dist, base_color);

    sfRectangleShape_setSize(game->player->view_field[i]->wall, size);
    sfRectangleShape_setPosition(game->player->view_field[i]->wall, position);
    sfRectangleShape_setFillColor(game->player->view_field[i]->wall,
        shaded_color);
    sfRenderWindow_drawRectangleShape(game->window->win,
        game->player->view_field[i]->wall, NULL);
}

void display_rays_walls(game_t *game)
{
    float dist = 0;
    float corrected_dist = 0;
    float wall_height = 0;

    for (int i = 0; i < NUM_RAYS; i++) {
        if (game->player->view_field[i]->distance == 0)
            continue;
        dist = game->player->view_field[i]->distance;
        corrected_dist = dist *
            cosf(game->player->angle - game->player->view_field[i]->angle);
        wall_height = (TILE_SIZE / corrected_dist) * (WINDOW_WIDTH / 2);
        create_wall(game, i, corrected_dist, wall_height);
    }
}
