/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** destroy_dialogue
*/

#include <SFML/Graphics.h>
#include "rpg.h"

void destroy_dialogue(dialogue_t *dialogue)
{
    sfTexture_destroy(dialogue->t_portraits);
    sfTexture_destroy(dialogue->t_textbox);
    sfSprite_destroy(dialogue->portrait);
    sfSprite_destroy(dialogue->textbox);
    sfFont_destroy(dialogue->font);
    sfText_destroy(dialogue->text);
}
