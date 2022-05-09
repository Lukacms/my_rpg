/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** npc2
*/

#include "rpg.h"

static const sfIntRect portaits[] = {
    {1024 * 1, 1440 * 0, 1024, 1440},
};

static const char *monologue = "Be careful one infected is near.\n";
static const char *monologue2 = "You will be rewarded !";

static void set_mc_rect(game_t *game)
{
    sfIntRect mc_rect = sfSprite_getTextureRect(game->entities.mc.sprite);

    if (game->entities.mc.type == MC)
        game->entities.mc.states_mc = FRONT;
    if (game->entities.mc.type == BLOND)
        game->entities.mc.states_mc = FRONT_BLOND;
    if (game->entities.mc.type == GIRL)
        game->entities.mc.states_mc = FRONT_GIRL;
    if (game->entities.mc.type == SKATER)
        game->entities.mc.states_mc = FRONT_SKATER;
    mc_rect.top = game->entities.mc.states_mc;
    mc_rect.left = 0;
    sfSprite_setTextureRect(game->entities.mc.sprite, mc_rect);
    return;
}

static void events(game_t *game, int *flag)
{
    sfEvent evt = {0};

    while (sfRenderWindow_pollEvent(game->window.window, &evt))
        close_window(game, evt);
    if (sfKeyboard_isKeyPressed(game->key.interact) == sfTrue)
        (*flag) += 1;
    if ((*flag) == 0)
        sfText_setString(game->dialogue.text, monologue);
    if ((*flag) == 1)
        sfText_setString(game->dialogue.text, monologue2);
    return;
}

static bool checking_mc_pos(sfVector2f pos)
{
    if (pos.x >= 4810 && pos.x <= 5010 && pos.y <= 1969 && pos.y >= 1769)
        return true;
    return false;
}

int npc2_interact(game_t *game)
{
    sfFloatRect mc_rect = {0};
    sfVector2f mc_pos = {0};

    if (!game)
        return FAILURE;
    mc_rect = get_true_rect_mc(game->entities.mc.sprite);
    mc_pos = (sfVector2f){mc_rect.left, mc_rect.top};
    if (checking_mc_pos(mc_pos) == true &&
    sfKeyboard_isKeyPressed(game->key.interact) == sfTrue)
        npc2_sentence(game);
    return SUCCESS;
}

int npc2_sentence(game_t *game)
{
    sfTime time = {0};
    int flag = 0;

    if (!game)
        return FAILURE;
    sfRenderWindow_setView(game->window.window, game->views.ui);
    sfSprite_setTextureRect(game->dialogue.portrait, portaits[0]);
    set_mc_rect(game);
    while (flag != 2 && sfRenderWindow_isOpen(game->window.window) == sfTrue) {
        time = sfClock_getElapsedTime(game->window.game_clock);
        if (sfTime_asSeconds(time) > 0.2) {
            events(game, &flag);
            display_interaction(game);
            sfClock_restart(game->window.game_clock);
        }
    }
    return SUCCESS;
}
