/*
** EPITECH PROJECT, 2024
** day_13
** File description:
** main
*/

#include "wolf.h"

sfVector2f cast_single_ray(game_t *game)
{
    sfVector2f ray_dir = {cosf(game->player->angle)
        , sinf(game->player->angle)};
    sfVector2f ray_pos = {(game->player->x), (game->player->y)};
    sfVector2f step = {ray_dir.x * TILE_SIZE / 100,
        ray_dir.y * TILE_SIZE / 100};
    sfVector2f current_pos = ray_pos;

    while (current_pos.x >= 0
        && current_pos.x < game->map->width * TILE_SIZE
        && current_pos.y >= 0
        && current_pos.y < game->map->height * TILE_SIZE) {
        if (is_wall(game->map, current_pos.x, current_pos.y))
            return current_pos;
        current_pos.x += step.x;
        current_pos.y += step.y;
    }
    return current_pos;
}

void project_rays(game_t *game, int index, sfVector2f line_coord,
    sfVertex *modified_vertex)
{
    game->player->view_field[index]->start.x =
        (game->player->x);
    game->player->view_field[index]->start.y =
        (game->player->y);
    game->player->view_field[index]->end.x = line_coord.x;
    game->player->view_field[index]->end.y = line_coord.y;
    modified_vertex =
        sfVertexArray_getVertex(game->player->view_field[index]->line, 0);
    modified_vertex->position = game->player->view_field[index]->start;
    modified_vertex =
        sfVertexArray_getVertex(game->player->view_field[index]->line, 1);
    modified_vertex->position = line_coord;
}

int cast_all_rays(game_t *game)
{
    float original_angle = game->player->angle;
    float start_angle = original_angle - (FOV / 2);
    float end_angle = original_angle + FOV;
    float step = FOV / NUM_RAYS;
    sfVector2f line_coord = {0, 0};
    sfVertex *modified_vertex = NULL;
    int index = 0;

    for (float angle = start_angle; angle <= end_angle; angle += step) {
        game->player->angle = angle;
        line_coord = cast_single_ray(game);
        if (index < NUM_RAYS) {
            game->player->view_field[index]->angle = angle;
            project_rays(game, index, line_coord, modified_vertex);
            index++;
        }
    }
    game->player->angle = original_angle;
    return 0;
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
