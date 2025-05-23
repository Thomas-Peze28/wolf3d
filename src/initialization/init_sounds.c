/*
** EPITECH PROJECT, 2024
** day_13
** File description:
** main
*/

#include "wolf.h"

sfSound *init_sound(char *audio_name, float volume)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *sound_buff = sfSoundBuffer_createFromFile(audio_name);

    sfSound_setBuffer(sound, sound_buff);
    sfSound_setVolume(sound, volume);
    return sound;
}

sounds_t *init_sounds(void)
{
    sounds_t *sounds = malloc(sizeof(sounds_t));

    if (!sounds)
        return NULL;
    sounds->background_music = sfMusic_createFromFile(
        "assets/sound/lavender_town_theme.mp3");
    sfMusic_setLoop(sounds->background_music, sfTrue);
    sfMusic_setVolume(sounds->background_music, 1);
    sfMusic_play(sounds->background_music);
    sounds->catched_pokemon = init_sound("assets/sound/pokemon.wav", 100);
    sounds->launched_pokeball = init_sound("assets/sound/pokeball.ogg", 50);
    return sounds;
}
