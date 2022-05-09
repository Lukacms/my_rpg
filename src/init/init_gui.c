/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** init_gui
*/

#include <SFML/Graphics.h>
#include "rpg.h"

static int set_gui_details(game_t *game, sfVector2u size)
{
    sfVector2f pos = {30, size.y};
    sfIntRect rect = sfSprite_getTextureRect(game->gui.icon);

    game->gui.health = sfRectangleShape_copy(game->gui.bar);
    if (!game->gui.health)
        return FAILURE;
    sfRectangleShape_setFillColor(game->gui.bar, sfBlack);
    sfRectangleShape_setFillColor(game->gui.health, sfRed);
    pos.y -= rect.height;
    sfSprite_setPosition(game->gui.icon, pos);
    return SUCCESS;
}

int init_gui(game_t *game)
{
    sfVector2u size = sfRenderWindow_getSize(game->window.window);
    sfVector2f size_alt = {0, size.y};

    game->gui.tex_icon = sfTexture_createFromFile(ICON, NULL);
    game->gui.icon = sfSprite_create();
    if (!game->gui.icon || !game->gui.tex_icon)
        return FAILURE;
    sfSprite_setTexture(game->gui.icon, game->gui.tex_icon, sfTrue);
    game->gui.bar = sfRectangleShape_create();
    if (!game->gui.bar)
        return FAILURE;
    sfRectangleShape_setSize(game->gui.bar, (sfVector2f){150, 25});
    size_alt.x += 350;
    size_alt.y -= 150;
    sfRectangleShape_setPosition(game->gui.bar, size_alt);
    return set_gui_details(game, size);
}
