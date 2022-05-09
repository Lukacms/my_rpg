/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** play_sound_selected
*/

#include "rpg.h"
#include "SFML/Audio.h"

void play_sound_selected(game_t *game, int id)
{
    if (id == 0)
        sfSound_setBuffer(game->sfx.sfx, game->sfx.b_items);
    if (id == 1)
        sfSound_setBuffer(game->sfx.sfx, game->sfx.b_wood);
    if (id == 3)
        sfSound_setBuffer(game->sfx.sfx, game->sfx.b_fire);
    if (id == 4)
        sfSound_setBuffer(game->sfx.sfx, game->sfx.b_click);
    if (id == 5)
        sfSound_setBuffer(game->sfx.sfx, game->sfx.b_laught);
    sfSound_play(game->sfx.sfx);
    return;
}
