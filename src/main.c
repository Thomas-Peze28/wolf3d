/*
** EPITECH PROJECT, 2024
** day_13
** File description:
** main
*/

#include "wolf.h"

void handle_key_pressed(game_t *game)
{
    if (game->window->event.key.code == sfKeyUp) {
        if (!is_wall(game->map, game->player->x * TILE_SIZE, (game->player->y - 1) * TILE_SIZE))
            game->player->y -= 1;
    }
    if (game->window->event.key.code == sfKeyDown) {
        if (!is_wall(game->map, game->player->x * TILE_SIZE, (game->player->y + 1) * TILE_SIZE))
            game->player->y += 1;
    }
    if (game->window->event.key.code == sfKeyLeft) {
        if (!is_wall(game->map, (game->player->x - 1) * TILE_SIZE, game->player->y * TILE_SIZE))
            game->player->x -= 1;
    }
    if (game->window->event.key.code == sfKeyRight) {
        if (!is_wall(game->map, (game->player->x + 1) * TILE_SIZE, game->player->y * TILE_SIZE))
            game->player->x += 1;
    }
    if (game->window->event.key.code == sfKeyQ)
        game->player->angle -= 0.1;
    if (game->window->event.key.code == sfKeyD)
        game->player->angle += 0.1;
}

int analyze_event(game_t *game)
{
    if (game->window->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window->win);
    if (game->window->event.type == sfEvtKeyPressed) {
        if (game->window->event.key.code == sfKeyEscape) {
            sfRenderWindow_close(game->window->win);
        } else
            handle_key_pressed(game);
    }
    return 0;
}

int generate_test(game_t *game)
{
    game->player->x = 2;
    game->player->y = 1;
    game->player->angle = 0;
    if (!game || !game->window->win)
        return 84;
    return 0;
}

int open_window(void)
{
    game_t *game = init_game();

    generate_test(game);
    sfRenderWindow_setFramerateLimit(game->window->win, 60);
    while (sfRenderWindow_isOpen(game->window->win)) {
        while (sfRenderWindow_pollEvent(game->window->win, &game->window->event))
            analyze_event(game);
        sfRenderWindow_clear(game->window->win, sfBlack);
        sfRenderWindow_drawRectangleShape(game->window->win, game->graphics->floor, NULL);
        sfRenderWindow_drawRectangleShape(game->window->win, game->graphics->ceilling, NULL);
        draw_2d_map(game);
        display_player(game);
        sfRenderWindow_display(game->window->win);
    }
    sfRenderWindow_destroy(game->window->win);
    return 0;
}

int main(void)
{
    open_window();
    return 0;
}
