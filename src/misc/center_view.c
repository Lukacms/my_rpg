/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** center_view
*/

#include "rpg.h"

void center_view(game_t *game)
{
    sfFloatRect r = sfSprite_getGlobalBounds(game->entities.mc.sprite);
    sfVector2f pos = {r.left + (r.width / 2), r.top + (r.height / 2)};

    sfView_setCenter(game->views.normal, pos);
}
