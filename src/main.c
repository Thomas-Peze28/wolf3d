/*
** EPITECH PROJECT, 2024
** day_13
** File description:
** main
*/

#include "wolf.h"

static void handle_player_movement(game_t *game)
{
    if (game->window->event.key.code == sfKeyZ) {
        if (!is_wall(game->map, game->player->x,
            (game->player->y - 1)))
            game->player->y -= 1;
    }
    if (game->window->event.key.code == sfKeyS) {
        if (!is_wall(game->map, game->player->x,
            (game->player->y + 1)))
            game->player->y += 1;
    }
    if (game->window->event.key.code == sfKeyQ) {
        if (!is_wall(game->map, (game->player->x - 1),
        game->player->y))
            game->player->x -= 1;
    }
    if (game->window->event.key.code == sfKeyD) {
        if (!is_wall(game->map, (game->player->x + 1),
        game->player->y))
            game->player->x += 1;
    }
}

void handle_key_pressed(game_t *game)
{
    handle_player_movement(game);
    if (game->window->event.key.code == sfKeyLeft)
        game->player->angle -= 0.1;
    if (game->window->event.key.code == sfKeyRight)
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
    game->player->x = 2 * TILE_SIZE;
    game->player->y = 3 * TILE_SIZE;
    game->player->angle = 0;
    if (!game || !game->window->win)
        return 84;
    return 0;
}

void print_framerate(void)
{
    static int first = 1;
    static sfClock *clock;
    static int fps = 0;
    sfTime elapsed;

    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
        printf("%3d FPS\n", fps);
        fflush(stdout);
        fps = 0;
        sfClock_restart(clock);
    } else
        fps++;
}

int open_window(void)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds;
    game_t *game = init_game();

    generate_test(game);
    sfRenderWindow_setFramerateLimit(game->window->win, 30);
    while (sfRenderWindow_isOpen(game->window->win)) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0f;
        while (sfRenderWindow_pollEvent(game->window->win,
            &game->window->event))
            analyze_event(game);
        if (seconds > 0.001) {
            print_framerate();
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
