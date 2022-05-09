/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init_principal_vision
*/

#include <SFML/Graphics.h>
#include "rpg.h"

static sfVector2f get_sprite_pos(enemies_t *enemy)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(enemy->sprite);
    sfVector2f pos = {0};

    pos.x = rect.left + (rect.width / 2);
    pos.y = rect.top + (rect.height / 2);
    return pos;
}

int set_provisor_vision(howtoplay_t *htp)
{
    sfVector2f pos = {0};

    if (!(htp->provisor.vision = sfCircleShape_create()))
        return FAILURE;
    pos = get_sprite_pos(&htp->provisor);
    sfCircleShape_setPosition(htp->provisor.vision,
        (sfVector2f){pos.x - 100, pos.y - 100});
    return SUCCESS;
}
