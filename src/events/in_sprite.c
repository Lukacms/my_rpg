/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** in_sprite
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "rpg.h"

bool in_sprite(sfSprite *text, int x, int y, sfVector2f scaling)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(text);

    rect.left *= scaling.x;
    rect.width *= scaling.x;
    rect.top *= scaling.y;
    rect.height *= scaling.y;
    if (sfFloatRect_contains(&rect, x, y) == sfTrue)
        return true;
    return false;
}
