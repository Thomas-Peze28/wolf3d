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

void game_clock(game_t *game, shoot_t *shoot, sfClock *clock)
{
    sfTime time_clock = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time_clock);

    set_cursor_position(game);
    handle_events(game, shoot);
    if (seconds > 0.01) {
        game_loop(game, shoot);
        display_ennemies(game);
        sfRenderWindow_display(game->window->win);
        sfClock_restart(clock);
    }
}

int launch_game(void)
{
    sfClock *clock = sfClock_create();
    game_t *game = init_game();
    shoot_t shoot = {0};

    shoot.rect = (sfIntRect){0, 0, 64, 64};
    shoot.hud_rect = (sfIntRect){0, 0, 185, 192};
    display_menu(game);
    while (sfRenderWindow_isOpen(game->window->win))
        game_clock(game, &shoot, clock);
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
