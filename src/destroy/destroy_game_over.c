/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** destroy_game_over
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"

int destroy_game_over(game_over_t *over)
{
    if (!over)
        return FAILURE;
    sfClock_destroy(over->over_clock);
    sfText_destroy(over->over_text);
    sfSprite_destroy(over->over);
    sfTexture_destroy(over->t_over);
    free_pixellist(over);
    return SUCCESS;
}
