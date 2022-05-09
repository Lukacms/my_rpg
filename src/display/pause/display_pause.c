/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** display_pause
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

int loop_button_save(sfVector2i pos_mouse, game_t *game)
{
    sfFloatRect rect;
    sfVector2f tmp;

    if (!game)
        return FAILURE;
    rect = sfText_getGlobalBounds(game->pause_menu.save.text);
    rect.left *= game->window.scaling.x;
    rect.top *= game->window.scaling.y;
    rect.width *= game->window.scaling.x;
    rect.height *= game->window.scaling.y;
    tmp = (sfVector2f){game->pause_menu.save.pos_text.x - 5,
    game->pause_menu.save.pos_text.y - 5};

    if (sfFloatRect_contains(&rect, pos_mouse.x, pos_mouse.y)) {
        sfText_setPosition(game->pause_menu.save.text, tmp);
        sfText_setScale(game->pause_menu.save.text,
        (sfVector2f){1.4, 1.4});
    } else {
        sfText_setPosition(game->pause_menu.save.text,
        game->pause_menu.save.pos_text);
        sfText_setScale(game->pause_menu.save.text,
        (sfVector2f){1.0, 1.0});
    }
    return SUCCESS;
}

static int display_text(game_t *game)
{
    if (!game)
        return FAILURE;
    sfRenderWindow_drawText(game->window.window,
    game->pause_menu.return_game.text, NULL);
    sfRenderWindow_drawText(game->window.window,
    game->pause_menu.inventory.text, NULL);
    sfRenderWindow_drawText(game->window.window,
    game->pause_menu.options.text, NULL);
    sfRenderWindow_drawText(game->window.window,
    game->pause_menu.return_to_title.text, NULL);
    sfRenderWindow_drawText(game->window.window,
    game->pause_menu.mc.text, NULL);
    sfRenderWindow_drawText(game->window.window,
    game->pause_menu.quit.text, NULL);
    sfRenderWindow_drawText(game->window.window,
    game->pause_menu.mc_sprite.text, NULL);
    sfRenderWindow_drawText(game->window.window,
    game->pause_menu.stats.text, NULL);
    sfRenderWindow_drawText(game->window.window,
    game->pause_menu.save.text, NULL);
    return SUCCESS;
}

int loop_button_quit(sfVector2i pos_mouse, game_t *game)
{
    sfFloatRect rect;
    sfVector2f tmp;

    if (!game)
        return FAILURE;
    rect = sfText_getGlobalBounds(game->pause_menu.quit.text);
    rect.left *= game->window.scaling.x;
    rect.top *= game->window.scaling.y;
    rect.width *= game->window.scaling.x;
    rect.height *= game->window.scaling.y;
    tmp = (sfVector2f){game->pause_menu.quit.pos_text.x - 5,
    game->pause_menu.quit.pos_text.y - 5};
    if (sfFloatRect_contains(&rect, pos_mouse.x, pos_mouse.y)) {
        sfText_setPosition(game->pause_menu.quit.text, tmp);
        sfText_setScale(game->pause_menu.quit.text,
        (sfVector2f){1.4, 1.4});
    } else {
        sfText_setPosition(game->pause_menu.quit.text,
        game->pause_menu.quit.pos_text);
        sfText_setScale(game->pause_menu.quit.text,
        (sfVector2f){1.0, 1.0});
    }
    return SUCCESS;
}

int loop_button_mc_sprite(sfVector2i pos_mouse, game_t *game)
{
    sfFloatRect rect;
    sfVector2f tmp;

    if (!game)
        return FAILURE;
    rect = sfText_getGlobalBounds(game->pause_menu.mc_sprite.text);
    rect.left *= game->window.scaling.x;
    rect.top *= game->window.scaling.y;
    rect.width *= game->window.scaling.x;
    rect.height *= game->window.scaling.y;
    tmp = (sfVector2f){game->pause_menu.mc_sprite.pos_text.x - 5,
    game->pause_menu.mc_sprite.pos_text.y - 5};

    if (sfFloatRect_contains(&rect, pos_mouse.x, pos_mouse.y)) {
        sfText_setPosition(game->pause_menu.mc_sprite.text, tmp);
        sfText_setScale(game->pause_menu.mc_sprite.text,
        (sfVector2f){1.4, 1.4});
    } else {
        sfText_setPosition(game->pause_menu.mc_sprite.text,
        game->pause_menu.mc_sprite.pos_text);
        sfText_setScale(game->pause_menu.mc_sprite.text,
        (sfVector2f){1.0, 1.0});
    }
    return SUCCESS;
}

int loop_button_stats(sfVector2i pos_mouse, game_t *game)
{
    sfFloatRect rect;
    sfVector2f tmp;

    if (!game)
        return FAILURE;
    rect = sfText_getGlobalBounds(game->pause_menu.stats.text);
    rect.left *= game->window.scaling.x;
    rect.top *= game->window.scaling.y;
    rect.width *= game->window.scaling.x;
    rect.height *= game->window.scaling.y;
    tmp = (sfVector2f){game->pause_menu.stats.pos_text.x - 5,
    game->pause_menu.stats.pos_text.y - 5};

    if (sfFloatRect_contains(&rect, pos_mouse.x, pos_mouse.y)) {
        sfText_setPosition(game->pause_menu.stats.text, tmp);
        sfText_setScale(game->pause_menu.stats.text,
        (sfVector2f){1.4, 1.4});
    } else {
        sfText_setPosition(game->pause_menu.stats.text,
        game->pause_menu.stats.pos_text);
        sfText_setScale(game->pause_menu.stats.text,
        (sfVector2f){1.0, 1.0});
    }
    return SUCCESS;
}

int display_pause(game_t *game)
{
    sfVector2i mouse;

    if (!game)
        return FAILURE;
    mouse = sfMouse_getPositionRenderWindow(game->window.window);
    loop_button_game(mouse, game);
    loop_button_title(mouse, game);
    loop_button_inventory(mouse, game);
    loop_button_options(mouse, game);
    loop_button_quit(mouse, game);
    loop_button_mc_sprite(mouse, game);
    loop_button_stats(mouse, game);
    loop_button_save(mouse, game);
    sfRenderWindow_setView(game->window.window, game->views.ui);
    sfRenderWindow_drawSprite(game->window.window, game->pause_menu.sprite,
    NULL);
    sfRenderWindow_drawRectangleShape(game->window.window,
    game->pause_menu.mc.rectangle, NULL);
    sfRenderWindow_drawSprite(game->window.window, game->pause_menu.sprite_mc,
    NULL);
    display_text(game);
    return SUCCESS;
}
