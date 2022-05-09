/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** close_window
*/

#include <SFML/Graphics.h>
#include "rpg.h"

void close_window(game_t *game, sfEvent evt)
{
    if (evt.type == sfEvtClosed || (evt.type == sfEvtKeyPressed &&
        evt.key.code == game->key.quit) || game->status == QUIT)
        sfRenderWindow_close(game->window.window);
    return;
}
