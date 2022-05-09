/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** render_views
*/

#include <stdbool.h>
#include <stdio.h>
#include "my.h"
#include "rpg.h"

void render_views(game_t *game)
{
    sfRenderWindow_setView(game->window.window, game->views.normal);
    return;
}
