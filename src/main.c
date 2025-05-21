/*
** EPITECH PROJECT, 2024
** wolf3D
** File description:
** main
*/

#include "wolf.h"

void handle_key_pressed(game_t *game)
{
    handle_player_movement(game, game->player, game->map);
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        game->player->angle -= 0.02;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        game->player->angle += 0.02;
}

int analyze_event(game_t *game)
{
    sfContextSettings settings = {0};

    if (game->window->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window->win);
    if (game->window->event.type == sfEvtKeyPressed
        && game->window->event.key.code == sfKeyF11) {
        sfRenderWindow_destroy(game->window->win);
        if (game->window->style == sfFullscreen)
            game->window->style = sfResize | sfClose;
        else
            game->window->style = sfFullscreen;
        settings.antialiasingLevel = 4;
        game->window->win = sfRenderWindow_create(
            game->window->mode, "WOLF", game->window->style, &settings);
        sfRenderWindow_setFramerateLimit(game->window->win, 60);
    }
    if (is_key_pressed(game->window->event, sfKeyEscape))
        display_menu(game);
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
    sfTime time_clock = {0};
    float seconds = 0.0;
    game_t *game = init_game();
    gastly_t **gastly_tab = init_gastly_tab(3, game->map->map);
    mimikyu_t **mimikyu_tab = init_mimikyu_tab(3, game->map->map);

    display_menu(game);
    generate_test(game);
    while (sfRenderWindow_isOpen(game->window->win)) {
        time_clock = sfClock_getElapsedTime(clock);
        seconds = sfTime_asSeconds(time_clock);
        while (sfRenderWindow_pollEvent(game->window->win,
            &game->window->event))
            analyze_event(game);
        if (seconds > 0.01) {
            game_loop(game);
            display_ennemies(gastly_tab, mimikyu_tab, game);
            sfRenderWindow_display(game->window->win);
            sfClock_restart(clock);
        }
    }
    sfRenderWindow_destroy(game->window->win);
    return 0;
}

int main(void)
{
    srand(time(NULL));
    open_window();
    return 0;
}
