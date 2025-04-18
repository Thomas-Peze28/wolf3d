/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_structs
*/

#include "wolf.h"

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->window = init_window();
    game->map = init_map();
    game->player = init_player(game->map->tile_size);
    game->graphics = init_graphics(game);
    game->map->tiles = create_tiles(game->map->width, game->map->height,
        game->map->tile_size, game->map->map);
    return game;
}

graphics_t *init_graphics(game_t *game)
{
    graphics_t *graphics = malloc(sizeof(graphics_t));

    if (!graphics)
        return NULL;
    graphics->floor = sfRectangleShape_create();
    graphics->ceilling = sfRectangleShape_create();
    sfRectangleShape_setFillColor(graphics->floor,
        sfColor_fromRGB(96, 96, 96));
    sfRectangleShape_setFillColor(graphics->ceilling,
        sfColor_fromRGB(64, 64, 64));
    sfRectangleShape_setSize(graphics->floor,
        (sfVector2f){game->window->mode.width, game->window->mode.height / 2});
    sfRectangleShape_setSize(graphics->ceilling,
        (sfVector2f){game->window->mode.width, game->window->mode.height / 2});
    sfRectangleShape_setPosition(graphics->floor,
        (sfVector2f){0, game->window->mode.height / 2});
    sfRectangleShape_setPosition(graphics->ceilling, (sfVector2f){0, 0});
    return graphics;
}

window_t *init_window(void)
{
    window_t *win = malloc(sizeof(window_t));

    if (!win)
        return NULL;
    win->win = NULL;
    win->event = (sfEvent){0};
    win->mode = (sfVideoMode){0};
    win->mode.bitsPerPixel = 32;
    win->mode.width = WINDOW_WIDTH;
    win->mode.height = WINDOW_HEIGHT;
    win->win = sfRenderWindow_create(win->mode, "WOLF",
        sfResize | sfClose, NULL);
    return win;
}

static void create_line(player_t *player, int i)
{
    sfVertex vertex1 = {.position = player->view_field[i]->start,
        .color = sfGreen};
    sfVertex vertex2 = {.position = player->view_field[i]->end,
        .color = sfGreen};

    sfVertexArray_append(player->view_field[i]->line, vertex1);
    sfVertexArray_append(player->view_field[i]->line, vertex2);
}

static player_t *init_view_player(player_t *player)
{
    for (int i = 0; i < NUM_RAYS; i++) {
        player->view_field[i] = malloc(sizeof(view_field_t));
        if (!player->view_field[i])
            return NULL;
        player->view_field[i]->line = sfVertexArray_create();
        sfVertexArray_setPrimitiveType(player->view_field[i]->line, sfLines);
        player->view_field[i]->start = (sfVector2f) {player->x, player->y};
        player->view_field[i]->end = (sfVector2f){0, 0};
        create_line(player, i);
        player->view_field[i]->direction = (sfVector2f){0, 0};
        player->view_field[i]->angle = 0;
        player->view_field[i]->distance = 0;
    }
    return player;
}

player_t *init_player(int tile_size)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->x = 0;
    player->y = 0;
    player->angle = 0;
    player->view_angle = 0;
    player->avatar = sfCircleShape_create();
    sfCircleShape_setRadius(player->avatar, tile_size / 2);
    sfCircleShape_setOrigin(player->avatar, (sfVector2f){0, 0});
    sfCircleShape_setFillColor(player->avatar, sfRed);
    sfCircleShape_setPosition(player->avatar,
        (sfVector2f){player->x * tile_size, player->y * tile_size});
    player->view_field = malloc(sizeof(view_field_t *) * NUM_RAYS);
    if (!player->view_field)
        return NULL;
    player = init_view_player(player);
    return player;
}
