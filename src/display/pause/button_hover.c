/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** button_hover
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

int loop_button_game(sfVector2i pos_mouse, game_t *game)
{
    sfFloatRect rect;
    sfVector2f tmp;

    if (!game)
        return FAILURE;
    rect = sfText_getGlobalBounds(game->pause_menu.return_game.text);
    rect.left *= game->window.scaling.x;
    rect.top *= game->window.scaling.y;
    rect.width *= game->window.scaling.x;
    rect.height *= game->window.scaling.y;
    tmp = (sfVector2f){game->pause_menu.return_game.pos_text.x - 5,
    game->pause_menu.return_game.pos_text.y - 5};

    if (sfFloatRect_contains(&rect, pos_mouse.x, pos_mouse.y)) {
        sfText_setPosition(game->pause_menu.return_game.text, tmp);
        sfText_setScale(game->pause_menu.return_game.text,
        (sfVector2f){1.4, 1.4});
    } else {
        sfText_setPosition(game->pause_menu.return_game.text,
        game->pause_menu.return_game.pos_text);
        sfText_setScale(game->pause_menu.return_game.text,
        (sfVector2f){1.0, 1.0});
    }
    return SUCCESS;
}

int loop_button_title(sfVector2i pos_mouse, game_t *game)
{
    sfFloatRect rect;
    sfVector2f tmp;

    if (!game)
        return FAILURE;
    rect = sfText_getGlobalBounds(game->pause_menu.return_to_title.text);
    rect.left *= game->window.scaling.x;
    rect.top *= game->window.scaling.y;
    rect.width *= game->window.scaling.x;
    rect.height *= game->window.scaling.y;
    tmp = (sfVector2f){game->pause_menu.return_to_title.pos_text.x - 5,
    game->pause_menu.return_to_title.pos_text.y - 5};
    if (sfFloatRect_contains(&rect, pos_mouse.x, pos_mouse.y)) {
        sfText_setPosition(game->pause_menu.return_to_title.text, tmp);
        sfText_setScale(game->pause_menu.return_to_title.text,
        (sfVector2f){1.4, 1.4});
    } else {
        sfText_setPosition(game->pause_menu.return_to_title.text,
        game->pause_menu.return_to_title.pos_text);
        sfText_setScale(game->pause_menu.return_to_title.text,
        (sfVector2f){1.0, 1.0});
    }
    return SUCCESS;
}

int loop_button_options(sfVector2i pos_mouse, game_t *game)
{
    sfFloatRect rect;
    sfVector2f tmp;

    if (!game)
        return FAILURE;
    rect = sfText_getGlobalBounds(game->pause_menu.options.text);
    rect.left *= game->window.scaling.x;
    rect.top *= game->window.scaling.y;
    rect.width *= game->window.scaling.x;
    rect.height *= game->window.scaling.y;
    tmp = (sfVector2f){game->pause_menu.options.pos_text.x - 5,
    game->pause_menu.options.pos_text.y - 5};

    if (sfFloatRect_contains(&rect, pos_mouse.x, pos_mouse.y)) {
        sfText_setPosition(game->pause_menu.options.text, tmp);
        sfText_setScale(game->pause_menu.options.text,
        (sfVector2f){1.4, 1.4});
    } else {
        sfText_setPosition(game->pause_menu.options.text,
        game->pause_menu.options.pos_text);
        sfText_setScale(game->pause_menu.options.text,
        (sfVector2f){1.0, 1.0});
    }
    return 0;
}

int loop_button_inventory(sfVector2i pos_mouse, game_t *game)
{
    sfFloatRect rect;
    sfVector2f tmp;

    if (!game)
        return FAILURE;
    rect = sfText_getGlobalBounds(game->pause_menu.inventory.text);
    rect.left *= game->window.scaling.x;
    rect.top *= game->window.scaling.y;
    rect.width *= game->window.scaling.x;
    rect.height *= game->window.scaling.y;
    tmp = (sfVector2f){game->pause_menu.inventory.pos_text.x - 5,
    game->pause_menu.inventory.pos_text.y - 5};

    if (sfFloatRect_contains(&rect, pos_mouse.x, pos_mouse.y)) {
        sfText_setPosition(game->pause_menu.inventory.text, tmp);
        sfText_setScale(game->pause_menu.inventory.text,
        (sfVector2f){1.4, 1.4});
    } else {
        sfText_setPosition(game->pause_menu.inventory.text,
        game->pause_menu.inventory.pos_text);
        sfText_setScale(game->pause_menu.inventory.text,
        (sfVector2f){1.0, 1.0});
    }
    return 0;
}
