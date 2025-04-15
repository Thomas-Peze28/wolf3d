/*
** EPITECH PROJECT, 2023
** include
** File description:
** window.h
*/


#ifndef WINDOW_H
    #define WINDOW_H

    #include "wolf.h"

    #define WINDOW_WIDTH 800
    #define WINDOW_HEIGHT 600

typedef struct window_s {
    sfRenderWindow *win;
    sfEvent event;
    sfVideoMode mode;
} window_t;

int open_window(void);
window_t *create_struct(void);

#endif
