/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** menu_events
*/

#include <SFML/Graphics.h>
#include "rpg/events.h"
#include "rpg/macros.h"
#include "rpg/game.h"
#include "rpg.h"

static const sfVector2f htp_pos = {1920, 500};

static int color_choices(game_t *game, sfMouseMoveEvent button)
{
    start_menu_t menu = game->start_menu;

    sfText_setColor(game->start_menu.menu_continue, sfWhite);
    sfText_setColor(game->start_menu.menu_ng, sfWhite);
    sfText_setColor(game->start_menu.menu_quit, sfWhite);
    if (in_text(menu.menu_quit, button.x, button.y, game->window.scaling))
        sfText_setColor(game->start_menu.menu_quit, sfRed);
    if (in_text(menu.menu_continue, button.x, button.y, game->window.scaling))
        sfText_setColor(game->start_menu.menu_continue, sfRed);
    if (in_text(menu.menu_ng, button.x, button.y, game->window.scaling))
        sfText_setColor(game->start_menu.menu_ng, sfRed);
    return SUCCESS;
}

static int analyse_input(game_t *game, sfMouseButtonEvent button)
{
    start_menu_t menu = game->start_menu;

    if (in_text(menu.menu_quit, button.x, button.y, game->window.scaling)) {
        game->status = QUIT;
        sfText_setColor(game->start_menu.menu_quit, sfBlue);
    }
    if (in_text(menu.menu_continue, button.x, button.y, game->window.scaling)) {
        load_game(game);
        game->status = GAME;
        sfText_setColor(game->start_menu.menu_continue, sfBlue);
    }
    if (in_text(menu.menu_ng, button.x, button.y, game->window.scaling)) {
        game->status = HTP;
        reset_game(game);
        sfText_setColor(game->start_menu.menu_ng, sfBlue);
    }
    if (game->status != MENU)
        return SUCCESS;
    while (sfMouse_isButtonPressed(button.button))
        add_particules(game);
    return SUCCESS;

}

static void entering_game(game_t *game)
{
    sfClock *tmp = sfClock_create();
    sfTime time = sfClock_getElapsedTime(tmp);
    float i = 0;

    sfSound_setBuffer(game->sfx.sfx, game->sfx.b_start);
    sfSound_play(game->sfx.sfx);
    while (sfTime_asSeconds(time) < 7.0) {
        if (sfTime_asSeconds(time) > i) {
            display_loading_screen(game);
            i += 0.5;
        }
        time = sfClock_getElapsedTime(tmp);
    }
    sfClock_destroy(tmp);
    center_view(game);
}

static void set_music(game_t *game)
{
    if (game->status == GAME) {
        sfMusic_stop(game->ost.title_theme);
        entering_game(game);
        sfMusic_play(game->ost.main_theme);
        sfRectangleShape_setSize(game->gui.health, (sfVector2f){150, 25});
    } else if (game->status == HTP) {
        sfMusic_stop(game->ost.title_theme);
        entering_game(game);
        sfMusic_play(game->ost.main_theme);
        sfSprite_setPosition(game->entities.mc.sprite, htp_pos);
        center_view(game);
    }
}

int analyse_menu_events(game_t *game, sfEvent event)
{
    if (!game)
        return FAILURE;
    if (event.type == sfEvtMouseButtonPressed)
        analyse_input(game, event.mouseButton);
    else if (event.type == sfEvtMouseMoved)
        color_choices(game, event.mouseMove);
    set_music(game);
    return SUCCESS;
}
