/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** check_bools
*/

#include "rpg.h"

int check_bools(bool *boolean, char **str)
{
    if ((*str)[0] != '0' && (*str)[0] != '1')
        return FAILURE;
    if ((*str)[0] == '1') {
        (*boolean) = true;
        (*str) += 2;
        return SUCCESS;
    }
    (*boolean) = false;
    (*str) += 2;
    return SUCCESS;
}
