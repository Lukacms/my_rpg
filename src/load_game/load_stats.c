/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** load_stats
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "rpg.h"
#include "my.h"

static int load_pos_mc(game_t *game, char **stats)
{
    sfVector2f pos = {0};
    int pos_x = my_getnbr(*stats);
    int pos_y = 0;

    if (!stats || !(*stats))
        return FAILURE;
    *stats += my_strlen(my_int_to_str(pos_x)) + 1;
    pos_y = my_getnbr(*stats);
    *stats += my_strlen(my_int_to_str(pos_y)) + 1;
    pos.x = pos_x;
    pos.y = pos_y;
    if ((*stats)[0] == ' ' || (*stats)[0] == '\n')
        return FAILURE;
    sfSprite_setPosition(game->entities.mc.sprite, pos);
    return SUCCESS;
}

static int load_inventory(game_t *game, char **stats)
{
    if (check_bools(&game->inventory.body_puppet, stats) == FAILURE)
        return FAILURE;
    if (check_bools(&game->inventory.full_puppet, stats) == FAILURE)
        return FAILURE;
    if (check_bools(&game->inventory.head_puppet, stats) == FAILURE)
        return FAILURE;
    if (check_bools(&game->inventory.heal_bottle, stats) == FAILURE)
        return FAILURE;
    if (check_bools(&game->inventory.key, stats) == FAILURE)
        return FAILURE;
    if (check_bools(&game->inventory.madness_potion, stats) == FAILURE)
        return FAILURE;
    if (check_bools(&game->inventory.magic_attack, stats) == FAILURE)
        return FAILURE;
    if (check_bools(&game->inventory.wooden_plank, stats) == FAILURE)
        return FAILURE;
    return SUCCESS;
}

static int load_scripts(game_t *game, char **stats)
{
    if (check_bools(&game->scripts.plank_collapse, stats) == FAILURE)
        return FAILURE;
    if (check_bools(&game->scripts.view_items, stats) == FAILURE)
        return FAILURE;
    if (check_bools(&game->scripts.ghost_sound, stats) == FAILURE)
        return FAILURE;
    if (check_bools(&game->scripts.pursuit_model, stats) == FAILURE)
        return FAILURE;
    if (check_bools(&game->scripts.new_room_model, stats) == FAILURE)
        return FAILURE;
    if (check_bools(&game->stats.npc_kill, stats) == FAILURE)
        return FAILURE;
    return SUCCESS;
}

static int load_stats_value(game_t *game, char **stats)
{
    if (game == NULL || !stats || !(*stats))
        return FAILURE;
    game->stats.stats_obj[2].nb_value = my_getnbr((*stats));
    *stats += my_strlen(my_int_to_str(game->stats.stats_obj[2].nb_value)) + 1;
    game->stats.stats_obj[3].nb_value = my_getnbr((*stats));
    *stats += my_strlen(my_int_to_str(game->stats.stats_obj[3].nb_value)) + 1;
    game->stats.stats_obj[1].nb_value = my_getnbr((*stats));
    *stats += my_strlen(my_int_to_str(game->stats.stats_obj[1].nb_value)) + 1;
    game->stats.stats_obj[0].nb_value = my_getnbr((*stats));
    *stats += my_strlen(my_int_to_str(game->stats.stats_obj[0].nb_value)) + 1;
    game->stats.xp = my_getnbr((*stats));
    *stats += my_strlen(my_int_to_str(game->stats.xp)) + 1;
    if (game->stats.stats_obj[2].nb_value < 0 ||
    game->stats.stats_obj[3].nb_value < 0 ||
    game->stats.stats_obj[1].nb_value < 0 ||
    game->stats.stats_obj[0].nb_value < 0)
        return FAILURE;
    return SUCCESS;
}

int load_stats(game_t *game)
{
    int fd = -1;
    char *stats = malloc(sizeof(char) * (MAP_SIZE + 1));
    char *tmp = {0};

    fd = open(SAVED_STATS, O_RDONLY);
    if (fd == -1 || !stats)
        return FAILURE;
    if (read(fd, stats, MAP_SIZE) == 0)
        return FAILURE;
    tmp = stats;
    if (load_pos_mc(game, &tmp) == FAILURE ||
    load_inventory(game, &tmp) == FAILURE ||
    load_scripts(game, &tmp) == FAILURE ||
    load_stats_value(game, &tmp) == FAILURE)
        return FAILURE;
    free(stats);
    close(fd);
    return SUCCESS;
}
