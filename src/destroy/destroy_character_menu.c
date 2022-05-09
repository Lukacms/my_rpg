/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** dsetroy_character_menu
*/

#include <SFML/Graphics.h>
#include "rpg.h"

static void destroy_satoshi(satoshi_t *perso)
{
    if (!perso)
        return;
    sfRectangleShape_destroy(perso->satoshi);
    sfText_destroy(perso->text_satoshi);
}

static void destroy_skater(skater_t *perso)
{
    if (!perso)
        return;
    sfRectangleShape_destroy(perso->skater);
    sfText_destroy(perso->text_skater);
}

static void destroy_girl(girl_t *perso)
{
    if (!perso)
        return;
    sfRectangleShape_destroy(perso->girl);
    sfText_destroy(perso->text_girl);
}

static void destroy_blond(blond_t *perso)
{
    if (!perso)
        return;
    sfRectangleShape_destroy(perso->blond);
    sfText_destroy(perso->text_blond);
}

void destroy_character_menu(character_menu_t *menu)
{
    if (!menu)
        return;
    sfRectangleShape_destroy(menu->color_blue);
    sfRectangleShape_destroy(menu->color_red);
    sfRectangleShape_destroy(menu->color_green);
    sfText_destroy(menu->back);
    sfSprite_destroy(menu->sprite);
    sfTexture_destroy(menu->tex_charact);
    sfSprite_destroy(menu->skin);
    sfClock_destroy(menu->clock);
    destroy_satoshi(&menu->satoshi);
    destroy_girl(&menu->girl);
    destroy_blond(&menu->blond);
    destroy_skater(&menu->skater);
}
