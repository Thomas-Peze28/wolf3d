/*
** EPITECH PROJECT, 2024
** wolf3D
** File description:
** main
*/

#include "wolf.h"

void draw_enemy_sprite(sfRenderWindow *window, sfSprite *sprite,
    sfVector2f pos, float size)
{
    sfSprite_setScale(sprite, (sfVector2f){size / 64, size / 64});
    sfSprite_setPosition(sprite, (sfVector2f){pos.x - size / 2, pos.y});
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void display_gastly(game_t *game, gastly_t *gastly)
{
    float dx = gastly->x - game->player->x;
    float dy = gastly->y - game->player->y;
    float dist = sqrtf(dx * dx + dy * dy);
    float angle = atan2f(dy, dx) - game->player->angle;
    float screen_x = 0;
    float size = 0;
    float sprite_y = 0;
    int col = 0;

    angle = normalize_angle(angle);
    if (fabs(angle) < (FOV / 2)) {
        screen_x = (angle + (FOV / 2)) / FOV * WINDOW_WIDTH;
        size = (TILE_SIZE * WINDOW_HEIGHT) / (dist * cosf(angle) + 0.0001f);
        sprite_y = (WINDOW_HEIGHT / 2) - size + (size / 2);
        col = (int)screen_x * NUM_RAYS / WINDOW_WIDTH;
        if (col >= 0 && col < WINDOW_WIDTH && dist < game->map->wall_dist[col])
            draw_enemy_sprite(game->window->win, gastly->sprite,
                (sfVector2f){screen_x, sprite_y}, size);
    }
}

void display_mimikyu(game_t *game, mimikyu_t *mimikyu)
{
    float dx = mimikyu->x - game->player->x;
    float dy = mimikyu->y - game->player->y;
    float dist = sqrtf(dx * dx + dy * dy);
    float angle = atan2f(dy, dx) - game->player->angle;
    float screen_x = 0;
    float size = 0;
    float sprite_y = 0;
    int col = 0;

    angle = normalize_angle(angle);
    if (fabs(angle) < (FOV / 2)) {
        screen_x = (angle + (FOV / 2)) / FOV * WINDOW_WIDTH;
        size = (TILE_SIZE * WINDOW_HEIGHT) / (dist * cosf(angle) + 0.0001f);
        sprite_y = (WINDOW_HEIGHT / 2) - size + (size / 2);
        col = (int)screen_x * NUM_RAYS / WINDOW_WIDTH;
        if (col >= 0 && col < WINDOW_WIDTH
            && dist < game->map->wall_dist[col])
            draw_enemy_sprite(game->window->win, mimikyu->sprite,
                (sfVector2f){screen_x, sprite_y}, size);
    }
}

int display_ennemies(gastly_t **gastly_tab, mimikyu_t **mimikyu_tab,
    game_t *game)
{
    for (int i = 0; gastly_tab[i] != NULL; i++) {
        update_gastly_anim(gastly_tab[i]);
        display_gastly(game, gastly_tab[i]);
    }
    for (int i = 0; mimikyu_tab[i] != NULL; i++) {
        update_mimikyu_anim(mimikyu_tab[i]);
        display_mimikyu(game, mimikyu_tab[i]);
    }
    return 0;
}
