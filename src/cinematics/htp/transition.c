/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** transition
*/

#include <SFML/Graphics.h>
#include "rpg.h"

const char instruction[] = "Press W close to the provisor to talk to him.\n";

static int display_corresponding_text(game_t *game)
{
    float pos_y;
    sfVector2f text_pos;

    if (!game)
        return FAILURE;
    pos_y = game->window.wdw_size.y;
    text_pos = (sfVector2f){40, pos_y - (pos_y / 10)};
    sfText_setPosition(game->htp.text, text_pos);
    text_pos.x = 0;
    sfSprite_setPosition(game->dialogue.textbox, text_pos);
    sfText_setString(game->htp.text, instruction);
    sfRenderWindow_drawSprite(game->window.window,
        game->dialogue.textbox, NULL);
    sfRenderWindow_drawText(game->window.window, game->htp.text, NULL);
    return SUCCESS;
}

int transition(game_t *game)
{
    if (!game)
        return FAILURE;
    display_corresponding_text(game);
    if (game->htp.next == true) {
        change_cinematics(&game->htp);
        game->htp.next = false;
    }
    return SUCCESS;
}
