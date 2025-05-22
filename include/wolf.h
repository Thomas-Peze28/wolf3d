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
    #include <SFML/Audio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <math.h>
    #include <time.h>
    #include <string.h>

    #include "window.h"
    #include "map.h"
    #include "player.h"
    #include "enemy.h"
    #include "graphics.h"

    #define OPTION_MENU game->graphics->menu->options_menu
    #define MAIN_MENU game->graphics->menu->main_menu

typedef struct sounds_s {
    sfMusic *background_music;
    sfSoundBuffer *footstep_buffer;
    sfSound *footstep;
} sounds_t;

typedef struct shoot_s {
    int shoot;
    int nb_frame_ball;
    int nb_frame_gun;
    sfIntRect rect;
    sfIntRect hud_rect;
} shoot_t;
typedef struct game_s {
    int level;
    window_t *window;
    map_t *map;
    player_t *player;
    graphics_t *graphics;
    sounds_t *sounds;
    gastly_t **gastly_tab;
    mimikyu_t **mimikyu_tab;
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
int analyze_event(game_t *game, shoot_t *shoot);
void handle_events(game_t *game, shoot_t *shoot);
void handle_key_pressed(game_t *game);

int is_button_clicked_rect(sfFloatRect rect, sfVector2i mouse);
bool is_key_pressed(sfEvent event, sfKeyCode key);
bool is_mouse_clicked(sfEvent event, sfMouseButton button);
int is_button_clicked(sfSprite *sprite, sfEvent event);

int game_loop(game_t *game, shoot_t *shoot);
int manage_rays(game_t *game);
int draw_minimap(game_t *game);
int draw_ceilling_floor(game_t *game);
void print_framerate(void);

void handle_player_movement(game_t *game, player_t *player, map_t *map);
void move_rect(sfIntRect *rect, int offset, int max_value);
float normalize_angle(float angle);
void set_cursor_position(game_t *game);

void display_gastly(game_t *game, gastly_t *gastly);
void display_mimikyu(game_t *game, mimikyu_t *mimikyu);
int display_ennemies(game_t *game);
void update_gastly_anim(gastly_t *gastly);
void update_mimikyu_anim(mimikyu_t *mimikyu);

int display_menu(game_t *game);
void display_fps(game_t *game);
menu_t *init_menu(void);
int display_options_menu(game_t *game);
menu_t *init_menu(void);
options_t *init_options_menu(void);
sounds_t *init_sounds(void);
void handle_shoot(game_t *game, shoot_t *shoot);

#endif /* WOLF_H */
