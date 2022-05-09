/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init_game
*/

#include <SFML/Graphics.h>
#include "rpg/game.h"
#include "rpg/macros.h"
#include "rpg/init.h"

static const sfVector2f npc_pos[] = {
    {1300, 1917},
    {4910, 1869},
    {2608, 4795},
    {10271, 4211},
};

static int init_game_other(game_t *game)
{
    if (init_items(game) != SUCCESS || init_music(game) != SUCCESS)
        return FAILURE;
    if (init_pause_menu(game) != SUCCESS || init_character(game) != SUCCESS)
        return FAILURE;
    if (init_settings_menu(game) != SUCCESS || init_inventory(game) != SUCCESS)
        return FAILURE;
    if (init_corpses(game) != SUCCESS || init_ennemies(game) != SUCCESS)
        return FAILURE;
    if (init_game_over(game) != SUCCESS || init_npc(game, NPC, 0,
    npc_pos[0]) != SUCCESS || init_npc(game, NPC2, 1, npc_pos[1]) != SUCCESS
    || init_npc(game, NPC3, 2, npc_pos[2]) != SUCCESS || init_npc(game, NPC4, 3,
    npc_pos[3]) != SUCCESS)
        return FAILURE;
    if (init_fireball(game) != SUCCESS || init_skill_tree(game) != SUCCESS ||
        init_sachiko(game) != SUCCESS || init_ending(game) != SUCCESS)
        return FAILURE;
    init_scripts(game);
    game->settings_menu.graphics.button1[0]->key_set = true;
    game->entities.npc[4] = NULL;
    return init_htp(game);
}

static int init_keyboard(game_t *game)
{
    if (!game)
        return FAILURE;
    game->mode = NONE;
    game->key.pause = 15;
    game->key.quit = sfKeyQ;
    game->key.interact = sfKeyW;
    game->key.left = sfKeyLeft;
    game->key.right = sfKeyRight;
    game->key.up = sfKeyUp;
    game->key.down = sfKeyDown;
    game->key.open_inv = sfKeyI;
    game->key.open_skill = sfKeyA;
    return SUCCESS;
}

int init_game(game_t *game)
{
    if (!game)
        return FAILURE;
    if (init_window(game) != SUCCESS || init_dialogue(game) != SUCCESS)
        return FAILURE;
    if (init_main_character(game) != SUCCESS || init_map(game) != SUCCESS)
        return FAILURE;
    if (init_tilemap(game) != SUCCESS || init_views(game) != SUCCESS)
        return FAILURE;
    if (init_gui(game) != SUCCESS || init_keyboard(game) != SUCCESS)
        return FAILURE;
    if (init_sfx(game) != SUCCESS || init_starting_menu(game) != SUCCESS)
        return FAILURE;
    return init_game_other(game);
}
