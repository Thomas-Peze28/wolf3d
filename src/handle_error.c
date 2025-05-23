/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-romane.cauvez
** File description:
** handle_error
*/

#include "wolf.h"

int verif_line_content(char *line)
{
    for (int i = 0; line[i]; i++) {
        if (line[i] != '0'&& line[i] != '1' && line[i] != '\n')
            return 84;
    }
    return 0;
}

int handle_error(char *file_name)
{
    FILE *file = fopen(file_name, "r");
    char *buffer = NULL;
    size_t len = 0;
    int line = 0;
 
    if (!file)
        return -1;
    getline(&buffer, &len, file);
    while (buffer) {
        line = strlen(buffer);
        if (line != 51 || verif_line_content(buffer) == 84)
            return 84;
        getline(&buffer, &len, file);
    }
    free(buffer);
    fclose(file);
    return 0;
}
