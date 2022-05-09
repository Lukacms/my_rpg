/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** init_characters
*/

#include <stdlib.h>
#include "rpg.h"

static int init_character_rectangle(game_t *game)
{
    game->characters.skater.skater =
    create_rectangle((sfVector2f){648, 110}, (sfVector2f){200, 300});
    game->characters.blond.blond =
    create_rectangle((sfVector2f){876, 125}, (sfVector2f){200, 300});
    game->characters.satoshi.satoshi =
    create_rectangle((sfVector2f){1110, 130}, (sfVector2f){200, 300});
    game->characters.girl.girl =
    create_rectangle((sfVector2f){1330, 130}, (sfVector2f){200, 300});
    if (!game->characters.satoshi.satoshi || !game->characters.girl.girl ||
    !game->characters.skater.skater || !game->characters.blond.blond)
        return FAILURE;
    return SUCCESS;
}

static int init_character_text(game_t *game)
{
    game->characters.back = init_text(game->start_menu.menu_font,
                                    (sfVector2f){50, 900}, "BACK");
    game->characters.satoshi.text_satoshi =
    init_text(game->start_menu.menu_font, (sfVector2f){50, 50}, "");
    game->characters.girl.text_girl =
    init_text(game->start_menu.menu_font, (sfVector2f){50, 50}, "");
    game->characters.blond.text_blond = init_text(game->start_menu.menu_font,
    (sfVector2f){50, 50}, "");
    game->characters.skater.text_skater = init_text(game->start_menu.menu_font,
    (sfVector2f){50, 50}, "");
    if (!game->characters.back || !game->characters.satoshi.text_satoshi ||
    !game->characters.girl.text_girl || !game->characters.blond.text_blond ||
    !game->characters.skater.text_skater)
        return FAILURE;
    return SUCCESS;
}

static int init_characters_rect(game_t *game)
{
    game->characters.blond.rect = (sfIntRect){24, 192, 24, 48};
    game->characters.girl.rect = (sfIntRect){24, 384, 24, 48};
    game->characters.skater.rect = (sfIntRect){24, 576, 24, 48},
    game->characters.satoshi.rect = (sfIntRect){24, 0, 24, 48};
    game->characters.color_red = create_rectangle((sfVector2f){600, 750},
    (sfVector2f){255, 20});
    sfRectangleShape_setFillColor(game->characters.color_red, sfRed);
    game->characters.color_green = create_rectangle((sfVector2f){600, 800},
    (sfVector2f){255, 20});
    sfRectangleShape_setFillColor(game->characters.color_green, sfGreen);
    game->characters.color_blue = create_rectangle((sfVector2f){600, 850},
    (sfVector2f){255, 20});
    sfRectangleShape_setFillColor(game->characters.color_blue, sfBlue);
    return SUCCESS;
}

static int init_characters_click(game_t *game)
{
    game->characters.blond.clicked_blond = false;
    game->characters.girl.clicked_girl = false;
    game->characters.satoshi.clicked_satoshi = false;
    game->characters.skater.clicked_skater = false;
    game->characters.color_red_click = false;
    game->characters.color_blue_click = false;
    game->characters.color_green_click = false;
    game->characters.green = 255;
    game->characters.red = 255;
    game->characters.blue = 255;
    return SUCCESS;
}

int init_character(game_t *game)
{
    game->characters.tex_charact = sfTexture_createFromFile(TEX_CHARACT, NULL);
    if (!game->characters.tex_charact)
        return FAILURE;
    game->characters.sprite = sfSprite_create();
    game->characters.skin = sfSprite_copy(game->entities.mc.sprite);
    if (!game->characters.sprite || !game->characters.skin)
        return FAILURE;
    sfSprite_setPosition(game->characters.skin, (sfVector2f){1000, 700});
    sfSprite_setScale(game->characters.skin, (sfVector2f){5, 5});
    sfSprite_setTexture(game->characters.sprite, game->characters.tex_charact,
    sfTrue);
    if (init_character_rectangle(game) != SUCCESS ||
    init_character_text(game) != SUCCESS)
        return FAILURE;
    game->characters.clock = sfClock_create();
    if (init_characters_rect(game) != SUCCESS ||
    init_characters_click(game) != SUCCESS)
        return FAILURE;
    return SUCCESS;
}
