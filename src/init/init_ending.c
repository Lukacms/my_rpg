/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** init_ending
*/

#include "rpg.h"

static const sfIntRect endings[] = {
    {0, 0, 1920, 1080},
    {1920, 0, 1920, 1080},
    {3840, 0, 1920, 1080},
};

int init_ending(game_t *game)
{
    if (!game)
        return FAILURE;
    game->ending.t_ending = sfTexture_createFromFile(ENDING_MAP, NULL);
    game->ending.ending = sfSprite_create();
    game->ending.fade = sfSprite_create();
    game->ending.panel = sfSprite_create();
    if (!game->ending.t_ending || !game->ending.ending || !game->ending.fade
        || !game->ending.panel)
        return FAILURE;
    sfSprite_setTexture(game->ending.ending, game->ending.t_ending, sfTrue);
    sfSprite_setTexture(game->ending.fade, game->ending.t_ending, sfTrue);
    sfSprite_setTexture(game->ending.panel, game->ending.t_ending, sfTrue);
    sfSprite_setTextureRect(game->ending.ending, endings[0]);
    sfSprite_setTextureRect(game->ending.fade, endings[1]);
    sfSprite_setTextureRect(game->ending.panel, endings[2]);
    return SUCCESS;
}
