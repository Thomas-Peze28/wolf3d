/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_enemies
*/

#include "wolf.h"

float normalize_angle(float angle)
{
    while (angle > M_PI)
        angle -= 2 * M_PI;
    while (angle < - M_PI)
        angle += 2 * M_PI;
    return angle;
}
