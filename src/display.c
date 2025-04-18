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

sfVector2f cast_single_ray(game_t *game)
{
    sfVector2f ray_dir = {cos(game->player->angle), sin(game->player->angle)};
    sfVector2f ray_pos = {(game->player->x + 0.5) * TILE_SIZE, (game->player->y + 0.5) * TILE_SIZE};
    sfVector2f step = {ray_dir.x * 0.1, ray_dir.y * 0.1};
    sfVector2f current_pos = ray_pos;

    while (current_pos.x >= 0 && current_pos.x < game->map->width * TILE_SIZE &&
        current_pos.y >= 0 && current_pos.y < game->map->height * TILE_SIZE) {
        if (is_wall(game->map, current_pos.x, current_pos.y)) {
            //printf("Ray hit a wall at (%f, %f)\n", current_pos.x, current_pos.y);
            return current_pos;
        }
        current_pos.x += step.x;
        current_pos.y += step.y;
    }
    return current_pos;
}

int cast_all_rays(game_t *game)
{
    float original_angle = game->player->angle;
    float start_angle = original_angle - (FOV / 2);
    float end_angle = original_angle + (FOV / 2);
    float step = FOV / NUM_RAYS;
    sfVector2f line_coord = {0, 0};
    sfVertex *modified_vertex = NULL;
    int index = 0;

    for (float angle = start_angle; angle <= end_angle; angle += step) {
        game->player->angle = angle;
        line_coord = cast_single_ray(game);
        if (index < NUM_RAYS) {
            game->player->view_field[index]->start.x = (game->player->x + 0.5) * TILE_SIZE;
            game->player->view_field[index]->start.y = (game->player->y + 0.5) * TILE_SIZE;
            game->player->view_field[index]->end.x = line_coord.x;
            game->player->view_field[index]->end.y = line_coord.y;
            modified_vertex = sfVertexArray_getVertex(game->player->view_field[index]->line, 0);
            modified_vertex->position = game->player->view_field[index]->start;
            modified_vertex = sfVertexArray_getVertex(game->player->view_field[index]->line, 1);
            modified_vertex->position = line_coord;
            index++;
        }
    }
    game->player->angle = original_angle;
    return 0;
}

int display_player_rotation(game_t *game)
{
    sfVector2f v1 = {game->player->x * TILE_SIZE + TILE_SIZE / 2, game->player->y * TILE_SIZE + TILE_SIZE / 2};
    sfVector2f v2 = {game->player->x * TILE_SIZE + TILE_SIZE / 2 + cos(game->player->angle) * 50,
        game->player->y * TILE_SIZE + TILE_SIZE / 2 + sin(game->player->angle) * 50};
    sfVertex vertex1 = {.position = v1, .color = sfBlue};
    sfVertex vertex2 = {.position = v2, .color = sfBlue};
    sfVertexArray *line = sfVertexArray_create();
    sfVertex *second_vertex = NULL;

    sfVertexArray_setPrimitiveType(line, sfLines);
    sfVertexArray_append(line, vertex1);
    sfVertexArray_append(line, vertex2);
    second_vertex = sfVertexArray_getVertex(line, 1);
    second_vertex->position = (sfVector2f){second_vertex->position.x, second_vertex->position.y};
    sfRenderWindow_drawVertexArray(game->window->win, line, NULL);
    sfVertexArray_destroy(line);
    return 0;
}

void print_player_view(player_t *player, window_t *window)
{
    int i = 0;

    while (i < NUM_RAYS) {
        sfRenderWindow_drawVertexArray(window->win, player->view_field[i]->line, NULL);
        i++;
    }
}

int display_player(game_t *game)
{
    sfCircleShape_setPosition(game->player->avatar, (sfVector2f){game->player->x * TILE_SIZE, game->player->y * TILE_SIZE});
    sfRenderWindow_drawCircleShape(game->window->win, game->player->avatar, NULL);
    display_player_rotation(game);
    cast_all_rays(game);
    print_player_view(game->player, game->window);
    return 0;
}
