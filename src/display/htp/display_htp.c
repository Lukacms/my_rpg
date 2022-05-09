/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display_htp
*/

#include <SFML/Graphics.h>
#include "rpg.h"

int display_htp(game_t *game)
{
    howtoplay_t htp = {0};

    if (!game)
        return FAILURE;
    htp = game->htp;
    render_views(game);
    if (draw_map(game, htp.map) != SUCCESS)
        return FAILURE;
    display_provisor_before(game);
    sfRenderWindow_drawSprite(game->window.window, game->entities.mc.sprite,
        NULL);
    display_provisor_after(game);
    sfRenderWindow_setView(game->window.window, game->views.ui);
    display_cinematics(game);
    sfRenderWindow_setView(game->window.window, game->views.normal);
    return SUCCESS;
}
