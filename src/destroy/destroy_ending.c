/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** destroy_ending
*/

#include <SFML/Graphics.h>
#include "rpg.h"

void destroy_ending(ending_t *ending)
{
    if (!ending)
        return;
    sfTexture_destroy(ending->t_ending);
    sfSprite_destroy(ending->ending);
    sfSprite_destroy(ending->fade);
    sfSprite_destroy(ending->panel);
}
