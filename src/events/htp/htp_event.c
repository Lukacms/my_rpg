/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** htp_event
*/

#include <SFML/Graphics.h>
#include "rpg.h"

static void change_scene(game_t *game, sfKeyCode code)
{
    if (code == sfKeyEnter)
        game->htp.state = FINISHED;
    if (code == sfKeyS && game->htp.state != TRANSITION)
        game->htp.next = true;
    is_provisor_talked_to(game, code);
}

int analyse_htp_event(game_t *game, sfEvent event)
{
    if (!game)
        return FAILURE;
    if (event.type == sfEvtKeyPressed) {
        change_scene(game, event.key.code);
        move_character(&game->entities.mc, game, event.key.code);
        center_view(game);
    }
    return SUCCESS;
}
