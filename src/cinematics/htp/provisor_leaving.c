/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** provisor_go
*/

#include <SFML/Graphics.h>
#include "rpg.h"

static int display_elements_for_view(game_t *game)
{
    sfEvent event = {0};

    if (!game)
        return FAILURE;
    sfRenderWindow_clear(game->window.window, sfBlack);
    sfRenderWindow_setView(game->window.window, game->views.normal);
    draw_map(game, game->htp.map);
    display_provisor_before(game);
    display_mc(&game->entities.mc, game->window.window);
    display_provisor_after(game);
    sfRenderWindow_display(game->window.window);
    while (sfRenderWindow_pollEvent(game->window.window, &event))
        close_window(game, event);
    return SUCCESS;
}

static int set_view_on_provisor(game_t *game)
{
    sfFloatRect r;
    sfVector2f pos;
    sfTime time = {0};

    if (!game)
        return FAILURE;
    r = sfSprite_getGlobalBounds(game->htp.provisor.sprite);
    pos = (sfVector2f){r.left + (r.width / 2), r.top + (r.height / 2)};
    sfView_setCenter(game->views.normal, pos);
    for (int i = 0; i < 15;) {
        display_elements_for_view(game);
        time = sfClock_getElapsedTime(game->htp.clock);
        if (sfTime_asSeconds(time) > 0.1) {
            sfView_zoom(game->views.normal, 0.98);
            sfClock_restart(game->htp.clock);
            i++;
        }
    }
    return SUCCESS;
}

static int move_provisor(howtoplay_t *htp, int *i, game_t *game)
{
    sfTime time = {0};
    sfVector2f move_provisor = {0, -5};
    sfColor color;
    sfIntRect rect;

    if (!game || !htp || !i)
        return FAILURE;
    time = sfClock_getElapsedTime(htp->clock);
    color = sfSprite_getColor(htp->provisor.sprite);;
    rect = sfSprite_getTextureRect(htp->provisor.sprite);;
    if (sfTime_asSeconds(time) < 0.1)
        return FAILURE;
    rect.top = BACK;
    if (*i < 85)
        color.a -= 3;
    sfSprite_setColor(htp->provisor.sprite, color);
    sfSprite_setTextureRect(htp->provisor.sprite, rect);
    animate_provisor(htp);
    sfClock_restart(htp->clock);
    *i += 1;
    sfSprite_move(htp->provisor.sprite, move_provisor);
    sfView_move(game->views.normal, move_provisor);
    return SUCCESS;
}

static int zoom_back(game_t *game)
{
    sfTime time = {0};

    if (!game)
        return FAILURE;
    for (int i = 0; i < 15;) {
        display_elements_for_view(game);
        time = sfClock_getElapsedTime(game->htp.clock);
        if (sfTime_asSeconds(time) > 0.1) {
            sfView_zoom(game->views.normal, 1.02);
            sfClock_restart(game->htp.clock);
            i++;
        }
    }
    return SUCCESS;
}

int provisor_leaving(game_t *game)
{
    if (!game)
        return FAILURE;
    set_view_on_provisor(game);
    for (int i = 0; i < 115;) {
        display_elements_for_view(game);
        move_provisor(&game->htp, &i, game);
    }
    zoom_back(game);
    change_cinematics(&game->htp);
    return SUCCESS;
}
