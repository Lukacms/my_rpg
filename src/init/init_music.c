/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** init_music
*/

#include "rpg.h"

static int set_volume_music(game_t *game)
{
    sfMusic_setVolume(game->ost.title_theme, 10);
    sfMusic_setVolume(game->ost.main_theme, 10);
    sfMusic_setVolume(game->ost.panic, 10);
    sfSound_setVolume(game->sfx.sfx, 10);
    return SUCCESS;
}

int init_music(game_t *game)
{
    game->ost.main_theme = sfMusic_createFromFile(MAIN_THEME);
    game->ost.title_theme = sfMusic_createFromFile(TITLE_THEME);
    game->ost.panic = sfMusic_createFromFile(PANIC);
    game->ost.ghost = sfMusic_createFromFile(GHOST_SOUND);
    game->ost.sachiko = sfMusic_createFromFile(SACHIKO_MEET);
    if (!game->ost.title_theme || !game->ost.main_theme || !game->ost.panic
        || !game->ost.sachiko || !game->ost.ghost)
        return FAILURE;
    set_volume_music(game);
    sfMusic_setLoop(game->ost.main_theme, sfTrue);
    sfMusic_setLoop(game->ost.title_theme, sfTrue);
    sfMusic_setLoop(game->ost.panic, sfTrue);
    sfMusic_setLoop(game->ost.sachiko, sfTrue);
    return SUCCESS;
}
