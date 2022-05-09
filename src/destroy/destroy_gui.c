/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** destroy_gui
*/

#include <SFML/Graphics.h>
#include "rpg.h"

void destroy_gui(gui_t *gui)
{
    if (!gui)
        return;
    sfTexture_destroy(gui->tex_icon);
    sfSprite_destroy(gui->icon);
    sfRectangleShape_destroy(gui->bar);
    sfRectangleShape_destroy(gui->health);
}
