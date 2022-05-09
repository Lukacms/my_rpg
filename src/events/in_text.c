/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** in_text
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "rpg.h"

bool in_text(sfText *text, int x, int y, sfVector2f scaling)
{
    sfFloatRect rect = sfText_getGlobalBounds(text);

    rect.left *= scaling.x;
    rect.width *= scaling.x;
    rect.top *= scaling.y;
    rect.height *= scaling.y;
    if (sfFloatRect_contains(&rect, x, y) == sfTrue)
        return true;
    return false;
}

bool in_rectangle(sfRectangleShape *re, int x, int y, sfVector2f scaling)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(re);

    rect.left *= scaling.x;
    rect.width *= scaling.x;
    rect.top *= scaling.y;
    rect.height *= scaling.y;
    if (sfFloatRect_contains(&rect, x, y) == sfTrue)
        return true;
    return false;
}

sfText *init_text(sfFont *str, sfVector2f pos_text, char *text_str)
{
    sfText *text = sfText_create();

    if (str == NULL)
        return NULL;
    if (!text || !str || !text_str)
        return NULL;
    sfText_setFont(text, str);
    sfText_setString(text, text_str);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, pos_text);
    return text;
}

sfRectangleShape *create_rectangle(sfVector2f pos, sfVector2f size)
{
    sfRectangleShape *re = sfRectangleShape_create();

    if (!re)
        return NULL;
    sfRectangleShape_setSize(re, size);
    sfRectangleShape_setPosition(re, pos);
    sfRectangleShape_setFillColor(re, sfColor_fromRGBA(0, 0, 0, 0));
    return re;
}
