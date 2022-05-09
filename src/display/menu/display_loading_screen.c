/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display_loading_screen
*/

#include <SFML/Graphics.h>
#include "rpg.h"

static char * const load[] = {
    "Loading\n",
    "Loading .\n",
    "Loading ..\n",
    "Loading ...\n",
    NULL
};

int display_loading_screen(game_t *game)
{
    static int i = 0;
    sfVector2f size = sfRectangleShape_getSize(game->start_menu.load);

    if (!load[i])
        i = 0;
    if (size.x <= 370)
        size.x += 17;
    else
        size.x = 0;
    sfRectangleShape_setSize(game->start_menu.load, size);
    sfRenderWindow_clear(game->window.window, sfBlack);
    sfText_setString(game->start_menu.loading, load[i]);
    sfRenderWindow_drawText(game->window.window,
        game->start_menu.loading, NULL);
    sfRenderWindow_drawRectangleShape(game->window.window,
        game->start_menu.load, NULL);
    sfRenderWindow_display(game->window.window);
    i++;
    return SUCCESS;
}
