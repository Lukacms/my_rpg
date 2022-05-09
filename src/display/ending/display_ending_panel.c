/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** ending_display
*/

#include "rpg.h"

int display_ending_panel(game_t *game)
{
    sfColor color = sfSprite_getColor(game->ending.fade);

    color.a = 255;
    sfSprite_setColor(game->ending.fade, color);
    sfRenderWindow_drawSprite(game->window.window, game->ending.panel, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyW) == sfTrue) {
        sfMusic_play(game->ost.title_theme);
        game->status = MENU;
    }
    return SUCCESS;
}
