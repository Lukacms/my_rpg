/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** load_file_in_array
*/

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char **load_file_in_array(char *path)
{
    char **infos = NULL;
    ssize_t size = 0;
    size_t count = 0;
    char *line = NULL;
    FILE *fileno = NULL;

    if (!path || !(fileno = fopen(path, "r")))
        return NULL;
    for (u_int i = 1; (size = getline(&line, &count, fileno)) != -1; i++) {
        infos = my_reallocarray(infos, i, size);
        if (line[size - 1] == '\n')
            line[size - 1] = '\0';
        infos[i - 1] = my_strcpy(infos[i - 1], line);
        infos[i] = NULL;
    }
    free(line);
    fclose(fileno);
    return infos;
}
