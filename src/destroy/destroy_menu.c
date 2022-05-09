/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** dsetroy_menu
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

int destroy_menu(start_menu_t *menu)
{
    if (!menu)
        return FAILURE;
    sfTexture_destroy(menu->tex_logo);
    sfTexture_destroy(menu->tex_bg);
    if (menu->logo)
        sfSprite_destroy(menu->logo);
    sfSprite_destroy(menu->bg);
    sfFont_destroy(menu->menu_font);
    sfText_destroy(menu->menu_ng);
    sfText_destroy(menu->menu_continue);
    sfText_destroy(menu->menu_quit);
    sfText_destroy(menu->loading);
    sfRectangleShape_destroy(menu->load);
    return SUCCESS;
}
