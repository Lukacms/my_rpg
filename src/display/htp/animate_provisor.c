/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** animate_provisor
*/

#include <SFML/Graphics.h>
#include "rpg.h"

int animate_provisor(howtoplay_t *htp)
{
    sfTime time = {0};
    sfIntRect rect = sfSprite_getTextureRect(htp->provisor.sprite);

    if (!htp)
        return FAILURE;
    time = sfClock_getElapsedTime(htp->provisor.animate);
    if (sfTime_asSeconds(time) > 0.1) {
        rect.left += 24;
        sfClock_restart(htp->provisor.animate);
    }
    if (rect.left >= 72)
        rect.left = 0;
    sfSprite_setTextureRect(htp->provisor.sprite, rect);
    return SUCCESS;
}
