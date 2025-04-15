/*
** EPITECH PROJECT, 2023
** include
** File description:
** wolf.h
*/

#ifndef WOLF_H
    #define WOLF_H
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <math.h>

    #include "window.h"
    #include "map.h"
    #include "player.h"
    #include "enemy.h"

typedef struct game_s {
    window_t *window;
    map_t *map;
    player_t *player;
} game_t;

int my_strcmp(char const *s1, char const *s2);
int open_window(void);
game_t *init_game(void);
bool is_wall(map_t *map, int x, int y);
void display_floor(game_t *game);

#endif
