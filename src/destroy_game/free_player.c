/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** free_game
*/

#include "wolf.h"

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
