/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_enemies
*/

#include "wolf.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value)
        rect->left += offset;
    if (rect->left >= max_value)
        rect->left = 0;
}
