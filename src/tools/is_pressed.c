/*
** EPITECH PROJECT, 2024
** wolf3D
** File description:
** main
*/

#include "wolf.h"

int is_button_clicked_rect(sfFloatRect rect, sfVector2i mouse)
{
    return sfFloatRect_contains(&rect, mouse.x, mouse.y);
}

bool is_key_pressed(sfEvent event, sfKeyCode key)
{
    return (event.type == sfEvtKeyPressed && event.key.code == key);
}

bool is_mouse_clicked(sfEvent event, sfMouseButton button)
{
    return (event.type == sfEvtMouseButtonPressed
        && event.mouseButton.button == button);
}

int is_button_clicked(sfSprite *sprite, sfEvent event)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);
    sfVector2i mouse = {event.mouseButton.x, event.mouseButton.y};

    return sfFloatRect_contains(&rect, mouse.x, mouse.y);
}
