/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** write_bools
*/

#include <unistd.h>
#include "rpg.h"

void write_bools(bool boolean, int fd)
{
    if (boolean == false) {
        write(fd, "0", 1);
        return;
    }
    write(fd, "1", 1);
    return;
}
