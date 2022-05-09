/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** saving_stats
*/

#include <fcntl.h>
#include <math.h>
#include <unistd.h>
#include "rpg.h"
#include "my.h"

static void saving_pos_of_mc(game_t *game, int fd)
{
    sfVector2f pos = sfSprite_getPosition(game->entities.mc.sprite);
    int len_x = {0};
    int len_y = {0};

    pos.x = round(pos.x);
    pos.y = round(pos.y);
    len_x = my_strlen(my_int_to_str(pos.x));
    len_y = my_strlen(my_int_to_str(pos.y));
    write(fd, my_int_to_str(pos.x), len_x);
    write(fd, " ", 1);
    write(fd, my_int_to_str(pos.y), len_y);
    write(fd, "\n", 1);
    return;
}

static void saving_inventory(game_t *game, int fd)
{
    write_bools(game->inventory.body_puppet, fd);
    write(fd, " ", 1);
    write_bools(game->inventory.full_puppet, fd);
    write(fd, " ", 1);
    write_bools(game->inventory.head_puppet, fd);
    write(fd, " ", 1);
    write_bools(game->inventory.heal_bottle, fd);
    write(fd, " ", 1);
    write_bools(game->inventory.key, fd);
    write(fd, " ", 1);
    write_bools(game->inventory.madness_potion, fd);
    write(fd, " ", 1);
    write_bools(game->inventory.magic_attack, fd);
    write(fd, " ", 1);
    write_bools(game->inventory.wooden_plank, fd);
    write(fd, "\n", 1);
    return;
}

static void saving_scripts(game_t *game, int fd)
{
    write_bools(game->scripts.plank_collapse, fd);
    write(fd, " ", 1);
    write_bools(game->scripts.view_items, fd);
    write(fd, " ", 1);
    write_bools(game->scripts.ghost_sound, fd);
    write(fd, " ", 1);
    write_bools(game->scripts.pursuit_model, fd);
    write(fd, " ", 1);
    write_bools(game->scripts.new_room_model, fd);
    write(fd, " ", 1);
    write_bools(game->stats.npc_kill, fd);
    write(fd, "\n", 1);
    return;
}

static int saving_stats_value(game_t *game, int fd)
{
    char *value_damage = my_int_to_str(game->stats.stats_obj[2].nb_value);
    int len_damage = my_strlen(value_damage);
    char *value_speed = my_int_to_str(game->stats.stats_obj[3].nb_value);
    int len_speed = my_strlen(value_speed);
    char *value_madness = my_int_to_str(game->stats.stats_obj[1].nb_value);
    int len_madness = my_strlen(value_madness);
    char *value_health = my_int_to_str(game->stats.stats_obj[0].nb_value);
    int len_health = my_strlen(value_health);
    char *value_xp = my_int_to_str(game->stats.xp);
    int len_xp = my_strlen(value_xp);

    write(fd, value_damage, len_damage);
    write(fd, " ", 1);
    write(fd, value_speed, len_speed);
    write(fd, " ", 1);
    write(fd, value_madness, len_madness);
    write(fd, " ", 1);
    write(fd, value_health, len_health);
    write(fd, " ", 1);
    write(fd, value_xp, len_xp);
    write(fd, "\n", 1);
    return SUCCESS;
}

int saving_stats(game_t *game)
{
    int fd = -1;

    if (!game)
        return FAILURE;
    fd = open(SAVED_STATS, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd <= -1)
        return FAILURE;
    saving_pos_of_mc(game, fd);
    saving_inventory(game, fd);
    saving_scripts(game, fd);
    saving_stats_value(game, fd);
    close(fd);
    return SUCCESS;
}
