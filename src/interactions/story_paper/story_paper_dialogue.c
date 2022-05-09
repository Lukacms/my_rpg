/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** story_paper_dialogue
*/

#include "rpg.h"

static const char monologue[] =
                "'If you read this, it means that you're already dead'";
static const char monologue2[] = "What...! What does it means ?";
static const char monologue3[] =
                "'When you enter in this place, you cannot go out anymore\n \
                I can't count the number of times I tried to flee of here.'";
static const char monologue4[] = "But... I will die here so...";
static const char monologue5[] = "No ! I can't. I have to go back home !";

int story_dialogue_1(game_t *game)
{
    if (game == NULL)
        return FAILURE;
    sfText_setString(game->dialogue.text, monologue);
    return SUCCESS;
}

int story_dialogue_2(game_t *game)
{
    if (game == NULL)
        return FAILURE;
    sfSprite_setTextureRect(game->dialogue.portrait,
    (sfIntRect){1024 * 4, 1440 * 1, 1024, 1440});
    sfText_setString(game->dialogue.text, monologue2);
    return SUCCESS;
}

int story_dialogue_3(game_t *game)
{
    if (game == NULL)
        return FAILURE;
    sfText_setString(game->dialogue.text, monologue3);
    return SUCCESS;
}

int story_dialogue_4(game_t *game)
{
    if (game == NULL)
        return FAILURE;
    sfText_setString(game->dialogue.text, monologue4);
    return SUCCESS;
}

int story_dialogue_5(game_t *game)
{
    if (game == NULL)
        return FAILURE;
    sfSprite_setTextureRect(game->dialogue.portrait,
    (sfIntRect){1024 * 0, 1440 * 1, 1024, 1440});
    sfText_setString(game->dialogue.text, monologue5);
    return SUCCESS;
}
