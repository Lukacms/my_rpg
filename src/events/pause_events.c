/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** pause_events
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include "rpg.h"
#include "my.h"

static void check_text_quit_charact(game_t *game, sfMouseButtonEvent button)
{
    if (in_text(game->pause_menu.quit.text,
    button.x, button.y, game->window.scaling) == true)
        sfRenderWindow_close(game->window.window);
    if (in_text(game->pause_menu.mc_sprite.text,
    button.x, button.y, game->window.scaling) == true)
        game->status = CHARACTERS;
    if (in_text(game->pause_menu.stats.text,
    button.x, button.y, game->window.scaling) == true)
        game->status = SKILL_TREE;
}

static int analyse_input_pause(game_t *game, sfMouseButtonEvent button)
{
    if (in_text(game->pause_menu.return_game.text,
    button.x, button.y, game->window.scaling) == true)
        game->status = GAME;
    if (in_text(game->pause_menu.inventory.text,
    button.x, button.y, game->window.scaling) == true)
        game->status = INVENTARY;
    if (in_text(game->pause_menu.options.text,
    button.x, button.y, game->window.scaling) == true)
        game->status = SETTINGS;
    if (in_text(game->pause_menu.return_to_title.text,
    button.x, button.y, game->window.scaling) == true)
        game->status = MENU;
    if (in_text(game->pause_menu.save.text,
    button.x, button.y, game->window.scaling) == true) {
        saving_map(game);
        saving_stats(game);
    }
    check_text_quit_charact(game, button);
    return SUCCESS;
}

static void set_colors(game_t *game, sfMouseMoveEvent button)
{
    sfText_setColor(game->pause_menu.return_game.text, sfWhite);
    sfText_setColor(game->pause_menu.inventory.text, sfWhite);
    sfText_setColor(game->pause_menu.options.text, sfWhite);
    sfText_setColor(game->pause_menu.return_to_title.text, sfWhite);
    sfText_setColor(game->pause_menu.quit.text, sfWhite);
    sfText_setColor(game->pause_menu.mc.text, sfWhite);
    sfText_setColor(game->pause_menu.mc_sprite.text, sfWhite);
    sfText_setColor(game->pause_menu.stats.text, sfWhite);
    sfText_setColor(game->pause_menu.save.text, sfWhite);
    if (in_text(game->pause_menu.return_game.text,
    button.x, button.y, game->window.scaling) == true)
        sfText_setColor(game->pause_menu.return_game.text, sfRed);
    if (in_text(game->pause_menu.inventory.text,
    button.x, button.y, game->window.scaling) == true)
        sfText_setColor(game->pause_menu.inventory.text, sfRed);
    if (in_text(game->pause_menu.options.text,
    button.x, button.y, game->window.scaling) == true)
        sfText_setColor(game->pause_menu.options.text, sfRed);
}

static int color_choices(game_t *game, sfMouseMoveEvent button)
{
    set_colors(game, button);
    if (in_text(game->pause_menu.return_to_title.text,
    button.x, button.y, game->window.scaling) == true)
        sfText_setColor(game->pause_menu.return_to_title.text, sfRed);
    if (in_text(game->pause_menu.quit.text,
    button.x, button.y, game->window.scaling) == true)
        sfText_setColor(game->pause_menu.quit.text, sfRed);
    if (in_text(game->pause_menu.mc_sprite.text,
    button.x, button.y, game->window.scaling) == true)
        sfText_setColor(game->pause_menu.mc_sprite.text, sfRed);
    if (in_text(game->pause_menu.stats.text,
    button.x, button.y, game->window.scaling) == true)
        sfText_setColor(game->pause_menu.stats.text, sfRed);
    if (in_text(game->pause_menu.save.text,
    button.x, button.y, game->window.scaling) == true)
        sfText_setColor(game->pause_menu.save.text, sfRed);
    return SUCCESS;
}

int analyse_pause_events(game_t *game, sfEvent event)
{
    if (!game)
        return FAILURE;
    if (event.type == sfEvtMouseButtonPressed)
        analyse_input_pause(game, event.mouseButton);
    else if (event.type == sfEvtMouseMoved)
        color_choices(game, event.mouseMove);
    return SUCCESS;
}
