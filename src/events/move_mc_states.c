/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-chloe.camus
** File description:
** move_mc_states
*/

#include "rpg.h"

int check_type_left(character_node_t *mc)
{
    if (mc->type == MC)
        mc->states_mc = LEFT;
    if (mc->type == BLOND)
        mc->states_mc = LEFT_BLOND;
    if (mc->type == GIRL)
        mc->states_mc = LEFT_GIRL;
    if (mc->type == SKATER)
        mc->states_mc = LEFT_SKATER;
    return SUCCESS;
}

int check_type_right(character_node_t *mc)
{
    if (mc->type == MC)
        mc->states_mc = RIGHT;
    if (mc->type == BLOND)
        mc->states_mc = RIGHT_BLOND;
    if (mc->type == GIRL)
        mc->states_mc = RIGHT_GIRL;
    if (mc->type == SKATER)
        mc->states_mc = RIGHT_SKATER;
    return SUCCESS;
}

int check_type_back(character_node_t *mc)
{
    if (mc->type == MC)
        mc->states_mc = BACK;
    if (mc->type == BLOND)
        mc->states_mc = BACK_BLOND;
    if (mc->type == GIRL)
        mc->states_mc = BACK_GIRL;
    if (mc->type == SKATER)
        mc->states_mc = BACK_SKATER;
    return SUCCESS;
}

int check_type_front(character_node_t *mc)
{
    if (mc->type == MC)
        mc->states_mc = FRONT;
    if (mc->type == BLOND)
        mc->states_mc = FRONT_BLOND;
    if (mc->type == GIRL)
        mc->states_mc = FRONT_GIRL;
    if (mc->type == SKATER)
        mc->states_mc = FRONT_SKATER;
    return SUCCESS;
}
