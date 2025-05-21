/*
** EPITECH PROJECT, 2023
** include
** File description:
** window.h
*/


#ifndef WINDOW_H
    #define WINDOW_H

    #include "wolf.h"

    #define WINDOW_WIDTH 1920
    #define WINDOW_HEIGHT 1080

typedef struct window_s {
    sfRenderWindow *win;
    sfEvent event;
    sfVideoMode mode;
    sfUint32 style;
    bool is_fullscreen;
} window_t;

int open_window(void);
window_t *init_window(sfUint32 style);

#endif
