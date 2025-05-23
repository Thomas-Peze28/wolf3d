/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** display
*/

#include "wolf.h"

int is_enemy_sprite_shot(game_t *game, sfSprite *sprite)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window->win);
    sfFloatRect sprite_bounds = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&sprite_bounds, mouse_pos.x, mouse_pos.y)) {
        sfSound_play(game->sounds->catched_pokemon);
        return 1;
    }
    return 0;
}

int is_enemy_shot(game_t *game, float ennemy_x, float ennemy_y)
{
    float dx = ennemy_x - game->player->x;
    float dy = ennemy_y - game->player->y;
    float dist = sqrtf(dx * dx + dy * dy);
    float angle_to_enemy = atan2f(dy, dx);
    float rel_angle = normalize_angle(angle_to_enemy - game->player->angle);
    int col = 0;

    if (fabs(rel_angle) < 0.05f) {
        col = (int)((rel_angle + (FOV / 2)) / FOV * WINDOW_WIDTH) *
        NUM_RAYS / WINDOW_WIDTH;
        if (col < 0)
            col = 0;
        if (col >= NUM_RAYS)
            col = NUM_RAYS - 1;
        if (dist < game->map->wall_dist[col])
            return 1;
    }
    return 0;
}
