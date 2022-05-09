/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** display_settings
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

int display_settings(game_t *game)
{
    sfVector2i mouse;

    if (!game)
        return FAILURE;
    mouse = sfMouse_getPositionRenderWindow(game->window.window);
    display_selected_mode(game, mouse);
    return SUCCESS;
}
