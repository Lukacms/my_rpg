/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** init_game_over
*/

#include "rpg.h"

static void configure_text(game_t *game)
{
    char text[] = "Press W to return to title screen\n";
    sfText_setString(game->game_over.over_text, text);
    sfText_setFont(game->game_over.over_text, game->start_menu.menu_font);
    sfText_setCharacterSize(game->game_over.over_text, 45);
    sfText_setPosition(game->game_over.over_text, (sfVector2f){300, 950});
    sfText_setFillColor(game->game_over.over_text, sfWhite);
    return;
}

int init_game_over(game_t *game)
{
    if (!game)
        return FAILURE;
    game->game_over.t_over = sfTexture_createFromFile(GAME_OVER_BG, NULL);
    game->game_over.over_text = sfText_create();
    if (!game->game_over.over_text || !game->game_over.t_over)
        return FAILURE;
    game->game_over.over = sfSprite_create();
    game->game_over.over_clock = sfClock_create();
    if (!game->game_over.over || !game->game_over.over_clock)
        return FAILURE;
    sfSprite_setTexture(game->game_over.over, game->game_over.t_over, sfTrue);
    configure_text(game);
    return init_pixellist(game);
}
