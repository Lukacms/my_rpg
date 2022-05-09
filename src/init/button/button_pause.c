/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** button_pause
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"
#include <fcntl.h>
#include <stdio.h>

int init_button_return_game(game_t *game)
{
    if (!game)
        return 84;
    game->pause_menu.return_game.rectangle =
    create_rectangle((sfVector2f){200, 200}, (sfVector2f){100, 100});
    if (!game->pause_menu.return_game.rectangle)
        return 84;
    game->pause_menu.return_game.pos_text = (sfVector2f){200, 200};
    game->pause_menu.return_game.text = init_text(game->pause_menu.font_mc,
    game->pause_menu.return_game.pos_text, "CONTINUE");
    if (!game->pause_menu.return_game.text)
        return 84;
    game->pause_menu.return_game.pos_text =
    sfText_getPosition(game->pause_menu.return_game.text);
    return 0;
}

int init_button_inventory(game_t *game)
{
    if (!game)
        return 84;
    game->pause_menu.inventory.rectangle =
    create_rectangle((sfVector2f){200, 300}, (sfVector2f){100, 100});
    if (!game->pause_menu.inventory.rectangle)
        return 84;
    game->pause_menu.inventory.pos_text = (sfVector2f){200, 300};
    game->pause_menu.inventory.text = init_text(game->pause_menu.font_mc,
    game->pause_menu.inventory.pos_text, "INVENTORY");
    if (!game->pause_menu.inventory.text)
        return 84;
    game->pause_menu.inventory.pos_text =
    sfText_getPosition(game->pause_menu.inventory.text);
    return 0;
}

int init_button_options(game_t *game)
{
    if (!game)
        return 84;
    game->pause_menu.options.rectangle =
    create_rectangle((sfVector2f){200, 400}, (sfVector2f){100, 100});
    if (!game->pause_menu.options.rectangle)
        return 84;
    game->pause_menu.options.pos_text = (sfVector2f){200, 400};
    game->pause_menu.options.text = init_text(game->pause_menu.font_mc,
    game->pause_menu.options.pos_text, "OPTIONS");
    if (!game->pause_menu.options.text)
        return 84;
    game->pause_menu.options.pos_text =
    sfText_getPosition(game->pause_menu.options.text);
    return 0;
}

int init_button_return_to_title(game_t *game)
{
    if (!game)
        return 84;
    game->pause_menu.return_to_title.rectangle =
    create_rectangle((sfVector2f){200, 500}, (sfVector2f){100, 100});
    if (!game->pause_menu.return_to_title.rectangle)
        return 84;
    game->pause_menu.return_to_title.pos_text = (sfVector2f){200, 500};
    game->pause_menu.return_to_title.text = init_text(game->pause_menu.font_mc,
    game->pause_menu.return_to_title.pos_text, "BACK TO TITLE");
    if (!game->pause_menu.return_to_title.text)
        return 84;
    game->pause_menu.return_to_title.pos_text =
    sfText_getPosition(game->pause_menu.return_to_title.text);
    return 0;
}

int init_button_mc(game_t *game)
{
    if (!game)
        return 84;
    game->pause_menu.mc.rectangle =
    create_rectangle((sfVector2f){780, 187}, (sfVector2f){175, 175});
    if (!game->pause_menu.mc.rectangle)
        return 84;
    game->pause_menu.mc.pos_text = (sfVector2f){1000, 187};
    game->pause_menu.mc.text = init_text(game->pause_menu.font_mc,
    game->pause_menu.mc.pos_text, "SATOSHI");
    if (!game->pause_menu.mc.text)
        return 84;
    game->pause_menu.mc.pos_text =
    sfText_getPosition(game->pause_menu.mc.text);
    game->pause_menu.sprite_mc = sfSprite_copy(game->gui.icon);
    if (!game->pause_menu.sprite_mc)
        return 84;
    sfSprite_setPosition(game->pause_menu.sprite_mc, (sfVector2f){780, 187});
    sfSprite_setScale(game->pause_menu.sprite_mc, (sfVector2f){0.5, 0.5});
    return 0;
}
