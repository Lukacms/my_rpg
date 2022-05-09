/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** init_portraits
*/

#include <SFML/Graphics.h>
#include "rpg.h"

static int setup_text(game_t *game)
{
    game->dialogue.font = sfFont_createFromFile(FONT_TEXT);
    game->dialogue.text = sfText_create();
    if (!game->dialogue.text || !game->dialogue.font)
        return FAILURE;
    sfText_setFillColor(game->dialogue.text, sfWhite);
    sfText_setPosition(game->dialogue.text, (sfVector2f){50, 850});
    sfText_setFont(game->dialogue.text, game->dialogue.font);
    if (!game->dialogue.text)
        return FAILURE;
    sfSprite_setPosition(game->dialogue.textbox, (sfVector2f){0, 855});
    sfSprite_setPosition(game->dialogue.portrait, (sfVector2f){-100, -150});
    sfText_setCharacterSize(game->dialogue.text, 120);
    return SUCCESS;
}

int init_dialogue(game_t *game)
{
    game->dialogue.t_portraits = sfTexture_createFromFile(PORTRAITS, NULL);
    game->dialogue.portrait = sfSprite_create();
    game->dialogue.t_textbox = sfTexture_createFromFile(TEXTBOX, NULL);
    game->dialogue.textbox = sfSprite_create();
    if (!game->dialogue.portrait || !game->dialogue.t_portraits)
        return FAILURE;
    if (!game->dialogue.t_textbox || !game->dialogue.textbox)
        return FAILURE;
    sfSprite_setTexture(game->dialogue.portrait, game->dialogue.t_portraits
                        , sfTrue);
    sfSprite_setTexture(game->dialogue.textbox, game->dialogue.t_textbox
                        , sfTrue);
    if (!game->dialogue.portrait || !game->dialogue.textbox)
        return FAILURE;
    return setup_text(game);
}
