/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display_help
*/

#include "rpg/macros.h"
#include "my.h"

int display_help(int argc)
{
    char **help = load_file_in_array(INFO_FILE);

    if (!help)
        return FAILURE;
    my_show_word_array(help);
    free_array((void **)help);
    if (argc != 2)
        return FAILURE;
    return SUCCESS;
}
