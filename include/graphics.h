/*
** EPITECH PROJECT, 2023
** include
** File description:
** map.h
*/


#ifndef GRAPHICS_H
    #define GRAPHICS_H

    #include "wolf.h"

typedef struct graphics_s {
    sfRectangleShape *floor;
    sfRectangleShape *ceilling;
    sfSprite *wall_sprite;
    sfTexture *wall_texture;
} graphics_t;

#endif /* GRAPHICS_H */
