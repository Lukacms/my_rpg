/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display_provisor
*/

#include "rpg.h"

int display_provisor_after(game_t *game)
{
    if (!game)
        return FAILURE;
    if (is_above_or_ahead(game->entities.mc, &game->htp.provisor) &&
        !game->htp.provisor.hidden)
        sfRenderWindow_drawSprite(game->window.window,
            game->htp.provisor.sprite, NULL);
    return SUCCESS;
}

int display_provisor_before(game_t *game)
{
    if (!game)
        return FAILURE;
    if (!is_above_or_ahead(game->entities.mc, &game->htp.provisor) &&
        !game->htp.provisor.hidden)
        sfRenderWindow_drawSprite(game->window.window,
            game->htp.provisor.sprite, NULL);
    return SUCCESS;
}
