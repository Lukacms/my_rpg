/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display_cinematics
*/

#include <stdlib.h>
#include "rpg.h"

static const sfVector2f mc_game_pos = {1080, 1900};

static const htp_status_t handler[] = {
    {.state = VISUAL, .cinematic = &set_situation},
    {.state = STORY_EXPLANATION, .cinematic = &story_explanation},
    {.state = LEARN_MOVES, .cinematic = &learn_moves},
    {.state = MOVING_PROVISOR, .cinematic = &moving_provisor},
    {.state = TRANSITION, .cinematic = &transition},
    {.state = BASIC_KEYS, .cinematic = &learn_keys},
    {.state = PROVISOR_LEAVING, .cinematic = &provisor_leaving},
    {.state = FINISHED, .cinematic = NULL},
    {0}
};

int display_cinematics(game_t *game)
{
    for (int i = 0; handler[i].cinematic; i += 1)
        if (handler[i].state == game->htp.state)
            return handler[i].cinematic(game);
    if (game->htp.state == FINISHED) {
        game->status = GAME;
        sfSprite_setPosition(game->entities.mc.sprite, mc_game_pos);
        center_view(game);
    }
    return SUCCESS;
}
