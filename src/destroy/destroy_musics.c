/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** destroy_musics
*/

#include <SFML/Graphics.h>
#include "rpg.h"

void destroy_musics(ost_t *ost)
{
    if (!ost)
        return;
    if (sfMusic_getStatus(ost->ghost) == sfPlaying)
        sfMusic_stop(ost->ghost);
    sfMusic_destroy(ost->ghost);
    if (sfMusic_getStatus(ost->main_theme) == sfPlaying)
        sfMusic_stop(ost->main_theme);
    sfMusic_destroy(ost->main_theme);
    if (sfMusic_getStatus(ost->panic) == sfPlaying)
        sfMusic_stop(ost->panic);
    sfMusic_destroy(ost->panic);
    if (sfMusic_getStatus(ost->sachiko) == sfPlaying)
        sfMusic_stop(ost->sachiko);
    sfMusic_destroy(ost->sachiko);
    if (sfMusic_getStatus(ost->title_theme) == sfPlaying)
        sfMusic_stop(ost->title_theme);
    sfMusic_destroy(ost->title_theme);
}
