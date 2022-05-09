/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** init_sfx
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"

int init_sfx(game_t *game)
{
    game->sfx.b_items = sfSoundBuffer_createFromFile(ITEMS_SFX);
    game->sfx.b_door = sfSoundBuffer_createFromFile(DOOR);
    game->sfx.b_start = sfSoundBuffer_createFromFile(START_SONG);
    game->sfx.b_over = sfSoundBuffer_createFromFile(GAME_OVER_SOUND);
    game->sfx.b_wood = sfSoundBuffer_createFromFile(FALLING_WOOD);
    game->sfx.b_fire = sfSoundBuffer_createFromFile(FIREBALL_SOUND);
    game->sfx.b_click = sfSoundBuffer_createFromFile(CLICK_SOUND);
    game->sfx.b_laught = sfSoundBuffer_createFromFile(GHOST_SOUND);
    game->sfx.sfx = sfSound_create();
    if (!game->sfx.sfx || !game->sfx.b_items || !game->sfx.b_door)
        return FAILURE;
    if (!game->sfx.b_start || !game->sfx.b_over || !game->sfx.b_wood
        || !game->sfx.b_fire || !game->sfx.b_click || !game->sfx.b_laught)
        return FAILURE;
    return SUCCESS;
}
