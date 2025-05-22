/*
** EPITECH PROJECT, 2024
** day_13
** File description:
** main
*/

#include "wolf.h"

sounds_t *init_sounds(void)
{
    sounds_t *sounds = malloc(sizeof(sounds_t));

    if (!sounds)
        return NULL;
    sounds->background_music = sfMusic_createFromFile(
        "assets/sound/lavender_town_theme.mp3");
    if (!sounds->background_music)
        return NULL;
    sfMusic_setLoop(sounds->background_music, sfTrue);
    sfMusic_setVolume(sounds->background_music, 50);
    sfMusic_play(sounds->background_music);
    return sounds;
}
