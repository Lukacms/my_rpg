/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** init_button
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"
#include <fcntl.h>
#include <stdio.h>

static int init_button_quit(game_t *game)
{
    if (!game)
        return 84;
    game->pause_menu.quit.rectangle =
    create_rectangle((sfVector2f){200, 600}, (sfVector2f){100, 100});
    if (!game->pause_menu.quit.rectangle)
        return 84;
    game->pause_menu.quit.pos_text = (sfVector2f){200, 600};
    game->pause_menu.quit.text = init_text(game->pause_menu.font_mc,
    game->pause_menu.quit.pos_text, "QUIT");
    if (!game->pause_menu.quit.text)
        return 84;
    game->pause_menu.quit.pos_text =
    sfText_getPosition(game->pause_menu.quit.text);
    return 0;
}

static int init_button_mc_sprite(game_t *game)
{
    if (!game)
        return 84;
    game->pause_menu.mc_sprite.rectangle =
    create_rectangle((sfVector2f){200, 700}, (sfVector2f){100, 100});
    if (!game->pause_menu.mc_sprite.rectangle)
        return 84;
    game->pause_menu.mc_sprite.pos_text = (sfVector2f){200, 700};
    game->pause_menu.mc_sprite.text = init_text(game->pause_menu.font_mc,
    game->pause_menu.mc_sprite.pos_text, "CHARACTERS");
    if (!game->pause_menu.mc_sprite.text)
        return 84;
    game->pause_menu.mc_sprite.pos_text =
    sfText_getPosition(game->pause_menu.mc_sprite.text);
    return 0;
}

static int init_button_skill_tree(game_t *game)
{
    if (!game)
        return 84;
    game->pause_menu.stats.rectangle =
    create_rectangle((sfVector2f){200, 700}, (sfVector2f){100, 100});
    if (!game->pause_menu.stats.rectangle)
        return 84;
    game->pause_menu.stats.pos_text = (sfVector2f){200, 800};
    game->pause_menu.stats.text = init_text(game->pause_menu.font_mc,
    game->pause_menu.stats.pos_text, "STATS");
    if (!game->pause_menu.stats.text)
        return 84;
    game->pause_menu.stats.pos_text =
    sfText_getPosition(game->pause_menu.stats.text);
    return 0;
}

static int init_button_save(game_t *game)
{
    if (!game)
        return 84;
    game->pause_menu.save.rectangle =
    create_rectangle((sfVector2f){200, 700}, (sfVector2f){100, 100});
    if (!game->pause_menu.save.rectangle)
        return 84;
    game->pause_menu.save.pos_text = (sfVector2f){200, 900};
    game->pause_menu.save.text = init_text(game->pause_menu.font_mc,
    game->pause_menu.save.pos_text, "SAVE");
    if (!game->pause_menu.save.text)
        return 84;
    game->pause_menu.save.pos_text =
    sfText_getPosition(game->pause_menu.save.text);
    return 0;
}

int init_pause_menu(game_t *game)
{
    if (!game)
        return 84;
    game->pause_menu.font_mc = sfFont_createFromFile(FONT_MC);
    if ((init_button_return_game(game) == 84) || (init_button_mc(game) == 84)
    || (init_button_inventory(game) == 84) || (init_button_options(game) == 84)
    || (init_button_return_to_title(game) == 84) ||
    (init_button_save(game) == 84) ||
    (init_button_quit(game) == 84) || (init_button_mc_sprite(game) == 84) ||
    (init_button_skill_tree(game) == 84))
        return 84;
    game->pause_menu.texture = sfTexture_createFromFile(TEX_PAUSE, NULL);
    if (!game->pause_menu.texture)
        return 84;
    game->pause_menu.sprite = sfSprite_create();
    if (!game->pause_menu.sprite)
        return 84;
    sfSprite_setTexture(game->pause_menu.sprite,
    game->pause_menu.texture, sfTrue);
    return 0;
}
