/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** free_game
*/

#include "wolf.h"

int free_sounds(sounds_t *sounds)
{
    if (sounds->background_music)
        sfMusic_destroy(sounds->background_music);
    if (sounds->footstep)
        sfSound_destroy(sounds->footstep);
    if (sounds->footstep_buffer)
        sfSoundBuffer_destroy(sounds->footstep_buffer);
    if (sounds->catched_pokemon)
        sfSound_destroy(sounds->catched_pokemon);
    if (sounds->launched_pokeball)
        sfSound_destroy(sounds->launched_pokeball);
    return 0;
}
