/*
** EPITECH PROJECT, 2024
** wold3D
** File description:
** map
*/

#include "wolf.h"

void save_map_to_file(int map[MAP_HEIGHT][MAP_WIDTH], const char *filename)
{
    FILE *file = fopen(filename, "w");

    if (!file)
        return;
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++)
            fprintf(file, "%d", map[y][x]);
        fprintf(file, "\n");
    }
    fclose(file);
}

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

void add_rooms(int map[MAP_HEIGHT][MAP_WIDTH], int nb_rooms)
{
    for (int r = 0; r < nb_rooms; r++) {
        int room_w = 2 + rand() % 8;
        int room_h = 2 + rand() % 8;
        int x = 1 + rand() % (MAP_WIDTH - room_w - 2);
        int y = 1 + rand() % (MAP_HEIGHT - room_h - 2);

        for (int i = 0; i < room_h; i++)
            for (int j = 0; j < room_w; j++)
                map[y + i][x + j] = 0;
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
