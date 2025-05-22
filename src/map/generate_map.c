/*
** EPITECH PROJECT, 2024
** wold3D
** File description:
** map
*/

#include "wolf.h"

void shuffle_dirs(int directions[4][2])
{
    int random = 0;
    int temp0 = 0;
    int temp1 = 0;

    for (int i = 0; i < 4; i++) {
        random = rand() % 4;
        temp0 = directions[i][0];
        temp1 = directions[i][1];
        directions[i][0] = directions[random][0];
        directions[i][1] = directions[random][1];
        directions[random][0] = temp0;
        directions[random][1] = temp1;
    }
}

void generate_maze(int map[MAP_HEIGHT][MAP_WIDTH], int x, int y)
{
    int directions[4][2] = {{0, 2}, {0, -2}, {2, 0}, {-2, 0}};
    int new_x = 0;
    int new_y = 0;

    shuffle_dirs(directions);
    for (int i = 0; i < 4; i++) {
        new_x = x + directions[i][0];
        new_y = y + directions[i][1];
        if (new_x > 0 && new_x < MAP_WIDTH - 1 && new_y > 0
            && new_y < MAP_HEIGHT - 1
            && map[new_y][new_x] == 1) {
            map[new_y][new_x] = 0;
            map[y + directions[i][1] / 2][x + directions[i][0] / 2] = 0;
            generate_maze(map, new_x, new_y);
        }
    }
}

void set_room(int map[MAP_HEIGHT][MAP_WIDTH],
    sfVector2i tupple, int w, int h)
{
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            map[tupple.y + i][tupple.x + j] = 0;
}

void add_rooms(int map[MAP_HEIGHT][MAP_WIDTH], int nb_rooms)
{
    int room_w = 0;
    int room_h = 0;
    sfVector2i tupple = {0, 0};

    for (int r = 0; r < nb_rooms; r++) {
        room_w = 2 + rand() % 8;
        room_h = 2 + rand() % 8;
        tupple.x = 1 + rand() % (MAP_WIDTH - room_w - 2);
        tupple.y = 1 + rand() % (MAP_HEIGHT - room_h - 2);
        set_room(map, tupple, room_w, room_h);
    }
}

void generate_and_save_map(void)
{
    int map[MAP_HEIGHT][MAP_WIDTH];

    for (int y = 0; y < MAP_HEIGHT; y++)
        for (int x = 0; x < MAP_WIDTH; x++)
            map[y][x] = 1;
    add_rooms(map, 15);
    map[1][1] = 0;
    generate_maze(map, 1, 1);
    save_map_to_file(map, "map_gen.txt");
}
