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

static sfVector2f cast_single_ray(game_t *game)
{
    sfVector2f ray_dir = {cosf(game->player->angle)
        , sinf(game->player->angle)};
    sfVector2f ray_pos = {(game->player->x + 0.5) * TILE_SIZE,
        (game->player->y + 0.5) * TILE_SIZE};
    sfVector2f step = {ray_dir.x * TILE_SIZE / 50, ray_dir.y * TILE_SIZE / 50};
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

static void project_rays(game_t *game, int index, sfVector2f line_coord,
    sfVertex *modified_vertex)
{
    game->player->view_field[index]->start.x =
        (game->player->x + 0.5) * TILE_SIZE;
    game->player->view_field[index]->start.y =
        (game->player->y + 0.5) * TILE_SIZE;
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
        (sfVector2f){game->player->x * TILE_SIZE,
        game->player->y * TILE_SIZE});
    print_player_view(game->player, game->window);
    sfRenderWindow_drawCircleShape(game->window->win,
        game->player->avatar, NULL);
    return 0;
}
