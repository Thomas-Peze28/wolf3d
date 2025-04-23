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
    #include "graphics.h"

typedef struct game_s {
    int level;
    window_t *window;
    map_t *map;
    player_t *player;
    graphics_t *graphics;
} game_t;

int my_strcmp(char const *s1, char const *s2);
int open_window(void);
game_t *init_game(void);
graphics_t *init_graphics(game_t *game);
bool is_wall(map_t *map, int x, int y);
void display_floor_ceilling(game_t *game);
void draw_floor_and_wall(game_t *game);
int display_player(game_t *game);
void draw_2d_map(game_t *game);
int cast_all_rays(game_t *game);
int calcuate_rays_dist(game_t *game);
void display_rays_walls(game_t *game);

int game_loop(game_t *game);
int manage_rays(game_t *game);
int draw_minimap(game_t *game);
int draw_ceilling_floor(game_t *game);

#endif
