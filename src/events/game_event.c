/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** game_event
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <stdbool.h>
#include "rpg.h"

int change_scene(game_t *game, sfEvent event)
{
    if (event.key.code == game->key.pause && event.type == sfEvtKeyPressed) {
        game->status = PAUSE;
    }
    return 0;
}

int analyse_game_events(game_t *game, sfEvent event)
{
    game->entities.mc.display_particules = false;
    if (event.type == sfEvtKeyPressed) {
        move_character(&game->entities.mc, game, event.key.code);
        analyse_interaction(game, event);
        center_view(game);
    }
    if (sfKeyboard_isKeyPressed(game->key.open_skill))
        game->status = SKILL_TREE;
    if (sfKeyboard_isKeyPressed(game->key.open_inv))
        game->status = INVENTARY;
    change_scene(game, event);
    return SUCCESS;
}
