/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** button_save.c
*/

#include "rpg.h"

int init_button_save(game_t *game)
{
    if (!game)
        return 84;
    game->pause_menu.save.rectangle =
    create_rectangle((sfVector2f){200, 500}, (sfVector2f){100, 100});
    if (!game->pause_menu.save.rectangle)
        return 84;
    game->pause_menu.save.pos_text = (sfVector2f){200, 700};
    game->pause_menu.save.text = init_text(game->dialogue.font,
    game->pause_menu.save.pos_text, "SAVE");
    if (!game->pause_menu.save.text)
        return 84;
    game->pause_menu.save.pos_text =
    sfText_getPosition(game->pause_menu.save.text);
    return 0;
}
