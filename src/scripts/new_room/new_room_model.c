/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** new_room_model.c
*/

#include "rpg.h"

static bool checking_mc_pos(sfVector2f pos)
{
    if (pos.x <= 12058 && pos.y >= 1042 && pos.y <= 1084)
        return true;
    return false;
}

static void change_corpses_room_model(game_t *game)
{
    for (int index = 0; game->corpses.corpses[index] != NULL; index += 1) {
        if (game->corpses.corpses[index]->script_room_model == true) {
            game->corpses.corpses[index]->script_room_model = false;
        }
    }
}

static int switch_model(game_t *game)
{
    enemies_t *tmp = NULL;

    if (game == NULL)
        return FAILURE;
    tmp = game->entities.enemies.head;
    for (unsigned int i = 0; i < game->entities.enemies.size; i += 1) {
        if (tmp->type == MODEL)
            sfSprite_setPosition(tmp->sprite, (sfVector2f){0, 0});
        tmp = tmp->next;
    }
    return SUCCESS;
}

void new_room_model(game_t *game)
{
    sfFloatRect mc_rect = get_true_rect_mc(game->entities.mc.sprite);
    sfVector2f mc_pos = {mc_rect.left, mc_rect.top};

    if (checking_mc_pos(mc_pos) == true &&
    game->scripts.pursuit_model == true &&
    game->scripts.new_room_model == false) {
        game->scripts.new_room_model = true;
        switch_model(game);
        change_corpses_room_model(game);
        launch_script_new_room(game);
    }
}
