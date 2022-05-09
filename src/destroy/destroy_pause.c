/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** destroy_pause
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"

static int destroy_button(button_t *button)
{
    if (!button)
        return FAILURE;
    sfRectangleShape_destroy(button->rectangle);
    sfText_destroy(button->text);
    return SUCCESS;
}

int destroy_pause(pause_menu_t *pause_menu)
{
    if (!pause_menu)
        return FAILURE;
    destroy_button(&pause_menu->return_game);
    destroy_button(&pause_menu->return_to_title);
    destroy_button(&pause_menu->inventory);
    destroy_button(&pause_menu->options);
    destroy_button(&pause_menu->quit);
    destroy_button(&pause_menu->mc_sprite);
    destroy_button(&pause_menu->stats);
    destroy_button(&pause_menu->save);
    destroy_button(&pause_menu->mc);
    sfTexture_destroy(pause_menu->texture);
    sfSprite_destroy(pause_menu->sprite);
    sfSprite_destroy(pause_menu->sprite_mc);
    if (pause_menu->font_mc)
        sfFont_destroy(pause_menu->font_mc);
    return SUCCESS;
}
