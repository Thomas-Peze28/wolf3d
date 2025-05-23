/*
** EPITECH PROJECT, 2024
** wolf3D
** File description:
** main
*/

#include "wolf.h"

void display_score(game_t *game)
{
    static sfFont *font = NULL;
    static sfText *text = NULL;
    char score_str[32];

    if (!font) {
        font = sfFont_createFromFile("assets/Roboto-Black.ttf");
        text = sfText_create();
        sfText_setFont(text, font);
        sfText_setCharacterSize(text, 50);
        sfText_setFillColor(text, sfYellow);
        sfText_setPosition(text, (sfVector2f){5, 300});
    }
    snprintf(score_str, sizeof(score_str), "Score: %d", game->score);
    sfText_setString(text, score_str);
    sfRenderWindow_drawText(game->window->win, text, NULL);
}
