/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** init_2d_array
*/

#include <stdlib.h>
#include "my.h"

static int line_counter(char *map)
{
    int lines = 0;
    int i = 0;

    if (!map)
        return -1;
    for (; map[i] != '\0'; i += 1) {
        if (map[i] == '\n')
            lines += 1;
    }
    if (map[i - 1] != '\n')
        lines += 1;
    return lines;
}

static int cols_counter(char *map)
{
    int cols = 0;

    for (; map[cols] != '\0' && map[cols] != '\n'; cols += 1);
    return cols;
}

char **initialize_two_d_array(char *map)
{
    char **tab = NULL;
    int lines = line_counter(map);
    int cols = 0;
    int index_jump = 0;

    if (map == NULL)
        return NULL;
    tab = malloc(sizeof(char *) * (lines + 1));
    for (int i = 0; i < lines; i += 1) {
        cols = cols_counter(map + index_jump);
        if (!(tab[i] = malloc(sizeof(char) * (cols + 1))))
            return NULL;
        tab[i] = my_strncpy(tab[i], map + index_jump, cols);
        index_jump += cols + 1;
    }
    tab[lines] = NULL;
    return tab;
}
