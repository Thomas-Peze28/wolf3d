/*
** EPITECH PROJECT, 2024
** wolf3D
** File description:
** main
*/

#include "wolf.h"

static int init_fps_display(sfFont **font, sfText **text, sfClock **clock)
{
    if (!(*font)) {
        *font = sfFont_createFromFile("assets/Roboto-Black.ttf");
        if (!(*font))
            return -1;
        *text = sfText_create();
        sfText_setFont(*text, *font);
        sfText_setCharacterSize(*text, 50);
        sfText_setPosition(*text, (sfVector2f){WINDOW_WIDTH - 200, 10});
        sfText_setFillColor(*text, sfWhite);
        *clock = sfClock_create();
    }
    if (!(*text) || !(*clock) || !(*font)) {
        sfFont_destroy(*font);
        sfText_destroy(*text);
        sfClock_destroy(*clock);
        return -1;
    }
    return 0;
}

void display_fps(game_t *game)
{
    static sfFont *font = NULL;
    static sfText *text = NULL;
    static sfClock *clock = NULL;
    static int frame_count = 0;
    static float fps = 0.0f;
    sfTime elapsed = {0};
    char fps_str[32];

    if (init_fps_display(&font, &text, &clock))
        return;
    frame_count++;
    elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1.0f) {
        fps = frame_count / sfTime_asSeconds(elapsed);
        frame_count = 0;
        sfClock_restart(clock);
    }
    snprintf(fps_str, sizeof(fps_str), "FPS: %.0f", fps);
    sfText_setString(text, fps_str);
    sfRenderWindow_drawText(game->window->win, text, NULL);
}
