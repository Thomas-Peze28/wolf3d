/*
** EPITECH PROJECT, 2024
** day_13
** File description:
** main
*/

#include "wolf.h"

window_t *create_struct(void)
{
    window_t *win = malloc(sizeof(window_t));

    if (!win)
        return NULL;
    win->win = NULL;
    win->event = (sfEvent){0};
    win->mode = (sfVideoMode){0};
    win->mode.bitsPerPixel = 32;
    win->mode.width = 800;
    win->mode.height = 600;
    win->win = sfRenderWindow_create(win->mode, "WOLF", sfResize | sfClose, NULL);
    return win;
}   

map_t *create_map(void)
{
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        return NULL;
    map->map = NULL;
    map->width = MAP_WIDTH;
    map->height = MAP_HEIGHT;
    map->tile_size = TILE_SIZE;
    map->map = malloc(sizeof(int *) * map->height);
    if (!map->map)
        return NULL;
    for (int i = 0; i < map->height; i++) {
        map->map[i] = malloc(sizeof(int) * map->width);
        if (!map->map[i])
            return NULL;
    }
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            map->map[i][j] = 0;
        }
    }
    return map;
}

player_t *create_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->x = 0;
    player->y = 0;
    player->angle = 0;
    return player;
}

game_t *create_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->window = create_struct();
    game->map = create_map();
    game->player = create_player();
    return game;
}

void print_map(map_t *map)
{
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            printf("%d ", map->map[i][j]);
        }
        printf("\n");
    }
}

void wall_map(map_t *map)
{
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
                map->map[i][j] = 1;
            else
                map->map[i][j] = 0;
        }
    }
}

bool is_wall(map_t *map, int x, int y)
{
    if (x < 0 || x >= map->width || y < 0 || y >= map->height)
        return false;
    return map->map[y][x] == 1;
}

void draw_floor_and_wall(game_t *game)
{
    for (int i = 0; i < game->map->height; i++) {
        for (int j = 0; j < game->map->width; j++) {
            if (game->map->map[i][j] == 1) {
                sfRectangleShape *rect = sfRectangleShape_create();
                sfRectangleShape_setSize(rect, (sfVector2f){game->map->tile_size, game->map->tile_size});
                sfRectangleShape_setPosition(rect, (sfVector2f){j * game->map->tile_size, i * game->map->tile_size});
                sfRectangleShape_setFillColor(rect, sfRed);
                sfRenderWindow_drawRectangleShape(game->window->win, rect, NULL);
                sfRectangleShape_destroy(rect);
            }
            if (game->map->map[i][j] == 0) {
                sfRectangleShape *rect = sfRectangleShape_create();
                sfRectangleShape_setSize(rect, (sfVector2f){game->map->tile_size, game->map->tile_size});
                sfRectangleShape_setPosition(rect, (sfVector2f){j * game->map->tile_size, i * game->map->tile_size});
                sfRectangleShape_setFillColor(rect, sfWhite);
                sfRenderWindow_drawRectangleShape(game->window->win, rect, NULL);
                sfRectangleShape_destroy(rect);
            }
        }
    }
}

int display_player_angle(game_t *game)
{
    sfVertexArray *line = sfVertexArray_create();
    sfVertex v1 = {.position = (sfVector2f){
        game->player->x * game->map->tile_size + game->map->tile_size / 2,
        game->player->y * game->map->tile_size + game->map->tile_size / 2},
        .color = sfBlue};
    sfVertex v2 = {.position = (sfVector2f){
        (game->player->x + cos(game->player->angle)) * game->map->tile_size + game->map->tile_size / 2,
        (game->player->y + sin(game->player->angle)) * game->map->tile_size + game->map->tile_size / 2},
        .color = sfBlue};

    if (!line)
        return 84;
    sfVertexArray_append(line, v1);
    sfVertexArray_append(line, v2);
    sfVertexArray_setPrimitiveType(line, sfLines);

    if (is_wall(game->map, game->player->x + cos(game->player->angle),
        game->player->y + sin(game->player->angle))) {
        printf("WALL\n");
    }

    sfRenderWindow_drawVertexArray(game->window->win, line, NULL);
    sfVertexArray_destroy(line);
    return 0;
}

int display_player(game_t *game)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setRadius(circle, game->map->tile_size / 2);
    sfCircleShape_setOrigin(circle, (sfVector2f){0, 0});
    sfCircleShape_setFillColor(circle, sfGreen);
    sfCircleShape_setPosition(circle, (sfVector2f){game->player->x * game->map->tile_size, game->player->y * game->map->tile_size});
    sfRenderWindow_drawCircleShape(game->window->win, circle, NULL);
    display_player_angle(game);    
    sfCircleShape_destroy(circle);
    return 0;
}

sfVertexArray *create_textured_quad(sfVector2f p1, sfVector2f p2,
    sfVector2f p3, sfVector2f p4)
{
    sfColor color = sfGreen;
    sfVertexArray *quad = sfVertexArray_create();
    sfVertex v1 = {.position = p1, .color = color};
    sfVertex v2 = {.position = p2, .color = color};
    sfVertex v3 = {.position = p3, .color = color};
    sfVertex v4 = {.position = p4, .color = color};

    if (!quad)
        return NULL;
    sfVertexArray_append(quad, v1);
    sfVertexArray_append(quad, v2);
    sfVertexArray_append(quad, v4);
    sfVertexArray_append(quad, v3);
    sfVertexArray_setPrimitiveType(quad, sfQuads);
    return quad;
}

void display_floor(game_t *game)
{
    sfVertexArray *floor = create_textured_quad(
        (sfVector2f){0, 0},
        (sfVector2f){game->window->mode.width, 0},
        (sfVector2f){300, game->window->mode.height / 2 - 100},
        (sfVector2f){game->window->mode.width - 300, game->window->mode.height / 2 - 100}
    );
    sfVertexArray *ceilling = create_textured_quad(
        (sfVector2f){0, game->window->mode.height},
        (sfVector2f){game->window->mode.width, game->window->mode.height},
        (sfVector2f){300, game->window->mode.height / 2 + 100},
        (sfVector2f){game->window->mode.width - 300, game->window->mode.height / 2 + 100}
    );
    sfRenderWindow_drawVertexArray(game->window->win, floor, NULL);
    sfRenderWindow_drawVertexArray(game->window->win, ceilling, NULL);
    sfVertexArray_destroy(floor);
    sfVertexArray_destroy(ceilling);
}

int analyze_event(game_t *game)
{
    if (game->window->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window->win);
    if (game->window->event.type == sfEvtKeyPressed) {
        if (game->window->event.key.code == sfKeyEscape)
            sfRenderWindow_close(game->window->win);
        if (game->window->event.key.code == sfKeyUp) {
            if (!is_wall(game->map, game->player->x, game->player->y - 1))
                game->player->y -= 1;
        }
        if (game->window->event.key.code == sfKeyDown) {
            if (!is_wall(game->map, game->player->x, game->player->y + 1))
                game->player->y += 1;
        }
        if (game->window->event.key.code == sfKeyLeft) {
            if (!is_wall(game->map, game->player->x - 1, game->player->y))
                game->player->x -= 1;
        }
        if (game->window->event.key.code == sfKeyRight) {
            if (!is_wall(game->map, game->player->x + 1, game->player->y))
                game->player->x += 1;
        }
        if (game->window->event.key.code == sfKeyA) {
            game->player->angle -= 0.1;
        }
        if (game->window->event.key.code == sfKeyZ) {
            game->player->angle += 0.1;
        }
    }
    return 0;
}

int open_window(void)
{
    game_t *game = create_game();

    wall_map(game->map);

    game->player->x = 1;
    game->player->y = 1;
    game->player->angle = 0;

    if (!game || !game->window->win)
        return 84;

    game->map->map[2][2] = 1;
    game->map->map[3][2] = 1;
    game->map->map[5][5] = 1;
    game->map->map[5][6] = 1;
    print_map(game->map);
    fmod(game->player->angle, 2 * 3.14159265358979323846);

    sfRenderWindow_setFramerateLimit(game->window->win, 60);
    while (sfRenderWindow_isOpen(game->window->win)) {
        while (sfRenderWindow_pollEvent(game->window->win, &game->window->event)) {
            analyze_event(game);
        }
        sfRenderWindow_clear(game->window->win, sfBlack);
        draw_floor_and_wall(game);
        display_player(game);
        //display_floor(game);
        sfRenderWindow_display(game->window->win);
    }
    sfWindow_destroy(game->window->win);
    return 0;
}

int main(void)
{
    open_window();
    return 0;
}
