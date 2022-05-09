/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** throw_fireball
*/

#include "rpg.h"

static void set_sprite(game_t *game, sfVector2f pos, sfIntRect rect)
{
    sfSprite_setTextureRect(game->fireball.fire, rect);
    sfSprite_setPosition(game->fireball.fire, pos);
}

void set_fireball(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->entities.mc.sprite);
    sfIntRect rect = {0, 0, 100, 100};

    if (game->fireball.state == RIGHT)
        pos.x += 48;
    if (game->fireball.state == LEFT) {
        rect.top = 100;
        pos.x -= 100;
    }
    if (game->fireball.state == FRONT) {
        pos.x -= 30;
        pos.y += 50;
        rect.top = 300;
    }
    if (game->fireball.state == BACK) {
        rect.top = 200;
        pos.x -= 30;
        pos.y -= 96;
    }
    set_sprite(game, pos, rect);
}

static int check_cooldown(game_t *game)
{
    if (game->inventory.head_puppet == true ||
    game->inventory.full_puppet == true) {
        return 2;
    } else
        return 5;
}

int is_fireball_thrown(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->fireball.countdown);
    int cooldown = 0;

    if (game == NULL)
        return FAILURE;
    if (sfKeyboard_isKeyPressed(sfKeyX) == sfTrue &&
    sfTime_asSeconds(time) > (cooldown = check_cooldown(game)) &&
    game->inventory.magic_attack == true) {
        play_sound_selected(game, 3);
        game->fireball.hidden = false;
        check_character(game);
        sfClock_restart(game->fireball.countdown);
    }
    return SUCCESS;
}
