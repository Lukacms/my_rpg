/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** settings_mode_graphics_events
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include "rpg.h"

static int analyse_graphics(game_t *game, sfMouseButtonEvent button)
{
    check_clicked_graphics_size(game, button);
    check_clicked_graphics_fps(game, button);
    return SUCCESS;
}

int modify_size(game_t *game, sfVector2u new_size, sfRectangleShape *re,
sfRectangleShape *re2)
{
    if (!game)
        return 84;
    sfVector2u size = sfRenderWindow_getSize(game->window.window);
    size = new_size;
    sfRenderWindow_setSize(game->window.window, size);
    game->window.scaling.x = size.x;
    game->window.scaling.y = size.y;
    game->window.wdw_size.x = size.x;
    game->window.wdw_size.y = size.y;
    sfRectangleShape_setFillColor(re, sfColor_fromRGBA(0, 255, 0, 255));
    sfRectangleShape_setFillColor(re2, sfColor_fromRGBA(255, 0, 0, 255));
    return SUCCESS;
}

int change_fps(game_t *game, int value, sfRectangleShape *re)
{
    sfRenderWindow_setFramerateLimit(game->window.window, value);
    sfRectangleShape_setFillColor(re, sfColor_fromRGBA(0, 255, 0, 255));
    return SUCCESS;
}

static int color_choices_graphics(game_t *game, sfMouseMoveEvent button)
{
    for (int i = 0; i < 7; i++) {
        sfText_setColor(game->settings_menu.graphics.button1[i]->text, sfWhite);
        if (in_text(game->settings_menu.graphics.button1[i]->text, button.x,
        button.y, game->window.scaling))
            sfText_setColor(game->settings_menu.graphics.button1[i]->text,
            sfRed);
    }
    return SUCCESS;
}

int analyse_graphics_events(game_t *game, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        analyse_graphics(game, event.mouseButton);
        play_sound_selected(game, 4);
    }
    else if (event.type == sfEvtMouseMoved)
        color_choices_graphics(game, event.mouseMove);
    return SUCCESS;
}
