/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** ghost_sound.c
*/

#include "rpg.h"

static bool checking_mc_pos(sfVector2f pos)
{
    if (pos.x >= 10366 && pos.x <= 10396 && pos.y <= 1340)
        return true;
    return false;
}

static void launch_script_ghost(game_t *game)
{
    sfTime time = {0};
    int index = 0;

    while (1) {
        time = sfClock_getElapsedTime(game->window.game_clock);
        if (sfTime_asSeconds(time) > 0.2) {
            index += 1;
            sfClock_restart(game->window.game_clock);
        }
        if (index == 1) {
            sfMusic_pause(game->ost.main_theme);
            play_sound_selected(game, 5);
            game->maps->map[23][203] = 'J';
            sfSprite_move(game->entities.mc.sprite, (sfVector2f){0, -48});
            break;
        }
    }
}

void ghost_sound(game_t *game)
{
    sfFloatRect mc_rect = get_true_rect_mc(game->entities.mc.sprite);
    sfVector2f mc_pos = {mc_rect.left, mc_rect.top};

    if (checking_mc_pos(mc_pos) == true &&
    game->scripts.ghost_sound == false) {
        game->scripts.ghost_sound = true;
        launch_script_ghost(game);
    }
}
