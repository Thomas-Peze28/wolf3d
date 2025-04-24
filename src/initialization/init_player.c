/*
** EPITECH PROJECT, 2024
** day_13
** File description:
** main
*/

#include "wolf.h"

void create_line(player_t *player, int i)
{
    sfVertex vertex1 = {.position = player->view_field[i]->start,
        .color = sfGreen};
    sfVertex vertex2 = {.position = player->view_field[i]->end,
        .color = sfGreen};

    sfVertexArray_append(player->view_field[i]->line, vertex1);
    sfVertexArray_append(player->view_field[i]->line, vertex2);
}

player_t *init_view_player(player_t *player)
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
        player->view_field[i]->wall = sfRectangleShape_create();
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
    player->speed = 0.5;
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
