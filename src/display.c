/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** display
*/

#include "wolf.h"

static sfVertexArray *create_textured_quad(sfVector2f p1, sfVector2f p2,
    sfVector2f p3, sfVector2f p4)
{
    sfColor color = sfGreen;
    sfVertexArray *quad = sfVertexArray_create();
    sfVertex v1 = {.position = p1, .color = color};
    sfVertex v2 = {.position = p2, .color = color};
    sfVertex v3 = {.position = p3, .color = color};
    sfVertex v4 = {.position = p4, .color = color};

    if (!quad)
        return NULL;
    sfVertexArray_append(quad, v1);
    sfVertexArray_append(quad, v2);
    sfVertexArray_append(quad, v4);
    sfVertexArray_append(quad, v3);
    sfVertexArray_setPrimitiveType(quad, sfQuads);
    return quad;
}

void display_floor_ceilling(game_t *game)
{
    sfVertexArray *floor = create_textured_quad(
        (sfVector2f){0, 0},
        (sfVector2f){game->window->mode.width, 0},
        (sfVector2f){300, game->window->mode.height / 2 - 100},
        (sfVector2f){game->window->mode.width - 300, game->window->mode.height / 2 - 100}
    );
    sfVertexArray *ceilling = create_textured_quad(
        (sfVector2f){0, game->window->mode.height},
        (sfVector2f){game->window->mode.width, game->window->mode.height},
        (sfVector2f){300, game->window->mode.height / 2 + 100},
        (sfVector2f){game->window->mode.width - 300, game->window->mode.height / 2 + 100}
    );
    sfRenderWindow_drawVertexArray(game->window->win, floor, NULL);
    sfRenderWindow_drawVertexArray(game->window->win, ceilling, NULL);
    sfVertexArray_destroy(floor);
    sfVertexArray_destroy(ceilling);
}

void draw_floor_and_wall(game_t *game)
{
    for (int i = 0; i < game->map->height; i++) {
        for (int j = 0; j < game->map->width; j++) {
            if (game->map->map[i][j] == 1) {
                sfRectangleShape *rect = sfRectangleShape_create();
                sfRectangleShape_setSize(rect, (sfVector2f){game->map->tile_size, game->map->tile_size});
                sfRectangleShape_setPosition(rect, (sfVector2f){j * game->map->tile_size, i * game->map->tile_size});
                sfRectangleShape_setFillColor(rect, sfRed);
                sfRenderWindow_drawRectangleShape(game->window->win, rect, NULL);
                sfRectangleShape_destroy(rect);
            }
            if (game->map->map[i][j] == 0) {
                sfRectangleShape *rect = sfRectangleShape_create();
                sfRectangleShape_setSize(rect, (sfVector2f){game->map->tile_size, game->map->tile_size});
                sfRectangleShape_setPosition(rect, (sfVector2f){j * game->map->tile_size, i * game->map->tile_size});
                sfRectangleShape_setFillColor(rect, sfWhite);
                sfRenderWindow_drawRectangleShape(game->window->win, rect, NULL);
                sfRectangleShape_destroy(rect);
            }
        }
    }
}

static int display_player_angle(game_t *game)
{
    sfVertexArray *line = sfVertexArray_create();
    sfVertex v1 = {.position = (sfVector2f){
        game->player->x * game->map->tile_size + game->map->tile_size / 2,
        game->player->y * game->map->tile_size + game->map->tile_size / 2},
        .color = sfBlue};
    sfVertex v2 = {.position = (sfVector2f){
        (game->player->x + cos(game->player->angle)) * game->map->tile_size + game->map->tile_size / 2,
        (game->player->y + sin(game->player->angle)) * game->map->tile_size + game->map->tile_size / 2},
        .color = sfBlue};

    if (!line)
        return 84;
    sfVertexArray_append(line, v1);
    sfVertexArray_append(line, v2);
    sfVertexArray_setPrimitiveType(line, sfLines);
    if (is_wall(game->map, game->player->x + cos(game->player->angle),
        game->player->y + sin(game->player->angle))) {
        printf("WALL\n");
    }
    sfRenderWindow_drawVertexArray(game->window->win, line, NULL);
    sfVertexArray_destroy(line);
    return 0;
}

int display_player(game_t *game)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setRadius(circle, game->map->tile_size / 2);
    sfCircleShape_setOrigin(circle, (sfVector2f){0, 0});
    sfCircleShape_setFillColor(circle, sfGreen);
    sfCircleShape_setPosition(circle, (sfVector2f){game->player->x * game->map->tile_size, game->player->y * game->map->tile_size});
    sfRenderWindow_drawCircleShape(game->window->win, circle, NULL);
    display_player_angle(game);    
    sfCircleShape_destroy(circle);
    return 0;
}
