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

    if (game->graphics->menu->options_menu->aiming_move == false)
        set_cursor_position(game);
    handle_events(game, shoot);
    if (seconds > 0.01) {
        game_loop(game, shoot);
        sfRenderWindow_display(game->window->win);
        sfClock_restart(clock);
    }
}

int launch_game(char *filepath)
{
    sfClock *clock = sfClock_create();
    game_t *game = init_game(filepath);
    shoot_t shoot = {0};

    shoot.rect = (sfIntRect){0, 0, 64, 64};
    shoot.hud_rect = (sfIntRect){0, 0, 185, 192};
    display_menu(game);
    while (sfRenderWindow_isOpen(game->window->win)) {
        game_clock(game, &shoot, clock);
        if (game->player->health <= 0) {
            display_game_over(game);
            return 0;
        }
        if (game->ennmies_alive == 0) {
            display_win(game);
            return 0;
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
    if (argv[1] && strcmp(argv[1], "-h") == 0) {
        printf("USAGE :\n\t./wolf3d (-h, -f <file>)\n\nDESCRIPTION :\n\n"
            "Oh no ! The Rocket team poisened some mimikyu and gastly and "
            "threw them in a maze ! Go save (catch) them all !\nBe carefull,"
            " the poison in their vein make them angry and violent. They "
            "might attack you...\n");
        return 0;
    }
    srand(time(NULL));
    if (argc == 3 && strcmp(argv[1], "-f") == 0) {
        launch_game(argv[2]);
    } else {
        generate_and_save_map();
        launch_game("map_gen.txt");
    }
    return 0;
}
