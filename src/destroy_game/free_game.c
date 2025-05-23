/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** free_game
*/

#include "wolf.h"

int free_graphics(graphics_t *graphics)
{
    if (graphics->pokeball)
        sfTexture_destroy(graphics->pokeball);
    if (graphics->menu) {
        free_menu(graphics->menu);
        free(graphics->menu);
    }
    if (graphics->hud) {
        free_hud(graphics->hud);
        free(graphics->hud);
    }
    if (graphics->ceilling)
        sfRectangleShape_destroy(graphics->ceilling);
    if (graphics->floor)
        sfRectangleShape_destroy(graphics->floor);
    if (graphics->cursor)
        sfSprite_destroy(graphics->cursor);
    return 0;
}

int free_player(player_t *player)
{
    if (player->avatar)
        sfCircleShape_destroy(player->avatar);
    if (player->view_field) {
        for (int i = 0; i < NUM_RAYS; i++) {
            sfVertexArray_destroy(player->view_field[i]->line);
            free(player->view_field[i]);
        }
        free(player->view_field);
    }
    free(player);
    return 0;
}

int free_game(game_t *game)
{
    if (game->map)
        free_map(game->map);
    if (game->player)
        free_player(game->player);
    if (game->graphics) {
        free_graphics(game->graphics);
        free(game->graphics);
    }
    if (game->window) {
        free_window(game->window);
        free(game->window);
    }
    if (game->sounds) {
        free_sounds(game->sounds);
        free(game->sounds);
    }
    if (game)
        free(game);
    return 0;
}
