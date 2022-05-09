/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** dialogue
*/

#include "rpg.h"

static const char monologue[] = "I have to say 'Sachiko, we beg of you' "\
                            "one time by people\n present here plus Sachiko " \
                            "in my mind.";

static const char falling_monologue[] = "Ahhhhhhhhhhhhhhhh................";

void third_dialogue(game_t *game)
{
    sfText_setString(game->dialogue.text, monologue);
    return;
}

void falling_dialogue(game_t *game)
{
    sfText_setString(game->dialogue.text, falling_monologue);
    return;
}
