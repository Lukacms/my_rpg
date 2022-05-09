/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** display_settings_mode
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

int loop_button(sfVector2i pos_mouse, game_t *game, sfText *text, sfVector2f p)
{
    sfFloatRect rect;
    sfVector2f tmp;

    if (!game || !text)
        return FAILURE;
    rect = sfText_getGlobalBounds(text);
    rect.left *= game->window.scaling.x;
    rect.top *= game->window.scaling.y;
    rect.width *= game->window.scaling.x;
    rect.height *= game->window.scaling.y;
    tmp = (sfVector2f){p.x - 5, p.y - 5};

    if (sfFloatRect_contains(&rect, pos_mouse.x, pos_mouse.y)) {
        sfText_setPosition(text, tmp);
        sfText_setScale(text, (sfVector2f){1.4, 1.4});
    } else {
        sfText_setPosition(text, p);
        sfText_setScale(text, (sfVector2f){1.0, 1.0});
    }
    return SUCCESS;
}

static int draw_rectangle(game_t *game)
{
    if (!game)
        return FAILURE;
    sfRenderWindow_drawRectangleShape(game->window.window,
    game->settings_menu.controls.rectangle, NULL);
    sfRenderWindow_drawRectangleShape(game->window.window,
    game->settings_menu.graphics.rectangle, NULL);
    sfRenderWindow_drawRectangleShape(game->window.window,
    game->settings_menu.audio.rectangle, NULL);
    return SUCCESS;
}

static int check_clicked(game_t *game)
{
    if (!game)
        return FAILURE;
    if (game->settings_menu.audio.clicked == true) {
        sfRenderWindow_drawSprite(game->window.window,
        game->settings_menu.audio.sprite, NULL);
        sfRenderWindow_drawRectangleShape(game->window.window,
        game->settings_menu.audio.rectangle, NULL);
    }
    if (game->settings_menu.controls.clicked == true) {
        sfRenderWindow_drawSprite(game->window.window,
        game->settings_menu.controls.sprite, NULL);
        sfRenderWindow_drawRectangleShape(game->window.window,
        game->settings_menu.controls.rectangle, NULL);
    }
    if (game->settings_menu.graphics.clicked == true) {
        sfRenderWindow_drawSprite(game->window.window,
        game->settings_menu.graphics.sprite, NULL);
        sfRenderWindow_drawRectangleShape(game->window.window,
        game->settings_menu.graphics.rectangle, NULL);
    }
    return SUCCESS;
}

int display_selected_mode(game_t *game, sfVector2i mouse)
{
    if (!game)
        return FAILURE;
    sfRenderWindow_drawSprite(game->window.window,
    game->settings_menu.sprite,NULL);
    check_clicked(game);
    sfRenderWindow_drawRectangleShape(game->window.window,
    game->settings_menu.back, NULL);
    draw_rectangle(game);
    if (game->mode == AUDIO)
        display_settings_mode_audio(game, mouse);
    if (game->mode == GRAPHICS)
        display_settings_mode_graphics(game, mouse);
    if (game->mode == CONTROLS)
        display_settings_mode_controls(game, mouse);
    return SUCCESS;
}
