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

int analyze_event(game_t *game, int *shoot)
{
    sfContextSettings settings = {0};

    if (game->window->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape))
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
    if (game->window->event.type == sfEvtMouseMoved)
        sfSprite_setPosition(game->graphics->cursor,
        (sfVector2f){game->window->event.mouseMove.x,
        game->window->event.mouseMove.y});
    if (game->window->event.type == sfEvtMouseButtonPressed)
        *shoot = 1;
    return 0;
}

int generate_test(game_t *game)
{
    game->player->x = 1 * TILE_SIZE;
    game->player->y = 1 * TILE_SIZE;
    game->player->angle = 0;
    if (!game || !game->window->win)
        return 84;
    return 0;
}

int launch_game(void)
{
    sfClock *clock = sfClock_create();
    sfTime time_clock = {0};
    float seconds = 0.0;
    game_t *game = init_game();
    sfIntRect rect = {0, 0, 64, 64};
    sfIntRect hud_rect = {0, 0, 185, 192};
    int shoot = 0;
    int nb_frame_ball = 0;
    int nb_frame_gun = 0;
    gastly_t **gastly_tab = init_gastly_tab(3, game->map->map);
    mimikyu_t **mimikyu_tab = init_mimikyu_tab(3, game->map->map);

    display_menu(game);
    set_cursor_position(game);
    sfRenderWindow_setMouseCursorVisible(game->window->win, sfFalse);
    generate_test(game);
    while (sfRenderWindow_isOpen(game->window->win)) {
        time_clock = sfClock_getElapsedTime(clock);
        seconds = sfTime_asSeconds(time_clock);
        while (sfRenderWindow_pollEvent(game->window->win,
            &game->window->event))
            analyze_event(game, &shoot);
        if (seconds > 0.01) {
            game_loop(game, &shoot, &nb_frame_ball, &nb_frame_gun, &rect,
                &hud_rect);
            display_ennemies(gastly_tab, mimikyu_tab, game);
            sfRenderWindow_display(game->window->win);
            sfClock_restart(clock);
        }
    }
    sfRenderWindow_destroy(game->window->win);
    return 0;
}

int main(int argc, char **argv, char **env)
{
    (void)argc;
    if (!env || !env[0] || !getenv("DISPLAY"))
        return 84;
    if (argv[1] && argv[1][0] == '-' && argv[1][1] == 'h') {
        printf("USAGE :\n\t./wolf3d (-h)\n\nDESCRIPTION :\n");
        return 0;
    }
    srand(time(NULL));
    generate_and_save_map();
    launch_game();
    return 0;
}
