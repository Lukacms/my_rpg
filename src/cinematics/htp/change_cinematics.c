/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** change_cinematics
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <sys/types.h>
#include "rpg.h"

static const htp_state_t state[] = {
    VISUAL,
    STORY_EXPLANATION,
    LEARN_MOVES,
    MOVING_PROVISOR,
    TRANSITION,
    BASIC_KEYS,
    PROVISOR_LEAVING,
    FINISHED
};

int change_cinematics(howtoplay_t *htp)
{
    if (!htp)
        return FAILURE;
    for (u_int i = 0; state[i] != FINISHED; i++) {
        if (htp->state == state[i]) {
            htp->next = false;
            htp->state = state[i + 1];
            sfClock_restart(htp->clock);
            break;
        }
    }
    return SUCCESS;
}
