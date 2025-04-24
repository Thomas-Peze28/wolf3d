/*
** EPITECH PROJECT, 2024
** day_13
** File description:
** main
*/

#include "wolf.h"

void handle_key_pressed(game_t *game)
{
    handle_player_movement(game, game->player, game->map);
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        game->player->angle -= 0.05;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        game->player->angle += 0.05;
}

int analyze_event(game_t *game)
{
    if (game->window->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window->win);
    return 0;
}

int generate_test(game_t *game)
{
    game->player->x = 2 * TILE_SIZE;
    game->player->y = 3 * TILE_SIZE;
    game->player->angle = 0;
    if (!game || !game->window->win)
        return 84;
    return 0;
}

int open_window(void)
{
    sfClock *clock = sfClock_create();
    sfTime time = {0};
    float seconds = 0.0;
    game_t *game = init_game();

    generate_test(game);
    draw_2d_map(game);
    while (sfRenderWindow_isOpen(game->window->win)) {
        time = sfClock_getElapsedTime(clock);
        seconds = sfTime_asSeconds(time);
        while (sfRenderWindow_pollEvent(game->window->win,
            &game->window->event))
            analyze_event(game);
        if (seconds > 0.01) {
            game_loop(game);
            sfClock_restart(clock);
        }
    }
    sfRenderWindow_destroy(game->window->win);
    return 0;
}

int main(void)
{
    open_window();
    return 0;
}
