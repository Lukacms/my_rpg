/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** init_inventory
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"

static const rect_item_t rect[] = {
    {{0, 0, 80, 80}, 2},
    {{84, 0, 80, 80}, 3},
    {{335, 584, 80, 80}, 4},
    {{250, 584, 80, 80}, 5},
    {{334, 0, 80, 80}, 6},
    {{167, 167, 80, 80}, 7},
    {{334, 84, 80, 80}, 8},
    {{250, 84, 80, 80}, 9},
    {{-1, -1, -1, -1}, -1}
};

static int slots(game_t *game, sfVector2f pos, sfVector2f size, int index)
{
    game->inventory.slot[index] = malloc(sizeof(slot_t));
    game->inventory.slot[index]->clicked = false;
    game->inventory.slot[index]->rectangle = NULL;
    game->inventory.slot[index]->sprite = NULL;
    game->inventory.slot[index]->text = NULL;
    game->inventory.slot[index]->rectangle = create_rectangle(pos, size);
    if (!game->inventory.slot[index]->rectangle)
        return FAILURE;
    game->inventory.slot[index]->clicked = false;
    return SUCCESS;
}

static int init_slots_sprite(game_t *game, sfVector2f pos, int index)
{
    for (int i = 0; rect[i].index != -1; i += 1) {
        if (index == rect[i].index) {
            game->inventory.slot[index]->sprite = sfSprite_create();
            sfSprite_setTexture(game->inventory.slot[index]->sprite,
            game->inventory.tex_item, sfTrue);
            sfSprite_setTextureRect(game->inventory.slot[index]->sprite,
            rect[i].rect);
            break;
        }
    }
    sfSprite_setPosition(game->inventory.slot[index]->sprite,
    (sfVector2f){pos.x + 50, pos.y + 20});
    sfSprite_setScale(game->inventory.slot[index]->sprite, (sfVector2f){3, 3});
    game->inventory.slot[index]->text =
    init_text(game->start_menu.menu_font, (sfVector2f){110, 780}, "");
    if (!game->inventory.slot[index]->text)
        return FAILURE;
    return SUCCESS;
}

static int init_all_slots1(game_t *game)
{
    if ((slots(game, (sfVector2f){0, 0}, (sfVector2f){188, 72}, 0) == FAILURE)
    || (slots(game, (sfVector2f){1404, 12}, (sfVector2f){495, 93}, 1) ==
    FAILURE) || (slots(game, (sfVector2f){116, 119}, (sfVector2f){371, 281}, 2)
    == FAILURE) || (init_slots_sprite(game, (sfVector2f){128, 118}, 2)
    == FAILURE) || (slots(game, (sfVector2f){560, 125},
    (sfVector2f){360, 270}, 3) == FAILURE) ||
    (init_slots_sprite(game, (sfVector2f){570, 118}, 3) == FAILURE) ||
    (slots(game, (sfVector2f){1000, 125}, (sfVector2f){360, 270}, 4) ==
    FAILURE) || (init_slots_sprite(game,
    (sfVector2f){1010, 118}, 4) == FAILURE))
        return FAILURE;
    game->inventory.text_click = init_text(game->start_menu.menu_font,
    (sfVector2f){1650, 760}, "CLICK");
    game->inventory.text_fusion = init_text(game->start_menu.menu_font,
    (sfVector2f){1650, 860}, "FUSION");
    if (!game->inventory.text_click || !game->inventory.text_fusion)
        return FAILURE;
    return SUCCESS;
}

static int init_all_slots2(game_t *game)
{
    if ((slots(game, (sfVector2f){1440, 125}, (sfVector2f){360, 270}, 5) ==
    FAILURE) || (init_slots_sprite(game,
    (sfVector2f){1450, 118}, 5) == FAILURE) ||
    (slots(game, (sfVector2f){120, 433}, (sfVector2f){360, 270}, 6) == FAILURE)
    || (init_slots_sprite(game,
    (sfVector2f){130, 429}, 6) == FAILURE) || (slots(game,
    (sfVector2f){560, 433}, (sfVector2f){360, 270}, 7) == FAILURE) ||
    (init_slots_sprite(game,
    (sfVector2f){570, 429}, 7) == FAILURE) || (slots(game,
    (sfVector2f){1000, 433}, (sfVector2f){360, 270}, 8) == FAILURE) ||
    (init_slots_sprite(game,
    (sfVector2f){1010, 429}, 8) == FAILURE) || (slots(game,
    (sfVector2f){1440, 433}, (sfVector2f){360, 270}, 9) == FAILURE) ||
    (init_slots_sprite(game,
    (sfVector2f){1450, 429}, 9) == FAILURE))
        return FAILURE;
    return SUCCESS;
}

int init_inventory(game_t *game)
{
    game->inventory.tex_item = sfTexture_createFromFile(TEX_ITEM, NULL);
    if (init_all_slots1(game) != SUCCESS || init_all_slots2(game) != SUCCESS)
        return FAILURE;
    game->inventory.wooden_plank = true;
    game->inventory.key = true;
    game->inventory.body_puppet = false;
    game->inventory.head_puppet = true;
    game->inventory.full_puppet = false;
    game->inventory.madness_potion = false;
    game->inventory.heal_bottle = false;
    game->inventory.magic_attack = true;
    game->inventory.texture = sfTexture_createFromFile(TEX_INVENTARY, NULL);
    if (!game->inventory.texture || !game->inventory.tex_item)
        return FAILURE;
    game->inventory.sprite = sfSprite_create();
    if (!game->inventory.sprite)
        return FAILURE;
    sfSprite_setTexture(game->inventory.sprite, game->inventory.texture,
    sfTrue);
    return SUCCESS;
}
