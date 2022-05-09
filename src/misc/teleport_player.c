/*
** EPITECH PROJECT, 2022
** RPG [WSL: Manjaro]
** File description:
** teleport_player
*/

#include "my.h"
#include "rpg.h"

static void search_right(int x, int y, game_t *game)
{
    int counter = 0;
    sfVector2f pos = sfSprite_getPosition(game->entities.mc.sprite);

    for (; game->maps->map[y][x + counter] != '~' &&
        game->maps->map[y][x + counter] != '\0'; counter += 1);
    if (game->maps->map[y][x + counter] == '\0')
        return;
    pos.x += (counter + 2) * 48;
    sfSprite_setPosition(game->entities.mc.sprite, pos);
    pos.x += sfSprite_getTextureRect(game->entities.mc.sprite).width;
    pos.y += sfSprite_getTextureRect(game->entities.mc.sprite).height;
    return;
}

static void search_left(int x, int y, game_t *game)
{
    int counter = 0;
    sfVector2f pos = sfSprite_getPosition(game->entities.mc.sprite);

    for (; (x + counter) > 0 &&
        game->maps->map[y][x + counter] != 'U'; counter -= 1);
    if (x + counter <= 0)
        return;
    pos.x += (counter - 1) * 48;
    sfSprite_setPosition(game->entities.mc.sprite, pos);
    pos = sfSprite_getPosition(game->entities.mc.sprite);
    pos.x += sfSprite_getTextureRect(game->entities.mc.sprite).width;
    pos.y += sfSprite_getTextureRect(game->entities.mc.sprite).height;
    return;
}

static void search_up(int x, int y, game_t *game)
{
    int counter = 0;
    sfVector2f pos = sfSprite_getPosition(game->entities.mc.sprite);

    for (; (y + counter) >= 0 &&
        game->maps->map[y + counter][x] != '?'; counter -= 1);
    if ((y + counter) < 0)
        return;
    pos.y += (counter - 1) * 48;
    sfSprite_setPosition(game->entities.mc.sprite, pos);
    pos = sfSprite_getPosition(game->entities.mc.sprite);
    pos.x += sfSprite_getTextureRect(game->entities.mc.sprite).width;
    pos.y += sfSprite_getTextureRect(game->entities.mc.sprite).height;
    return;
}

static void search_down(int x, int y, game_t *game)
{
    int counter = 0;
    sfVector2f pos = sfSprite_getPosition(game->entities.mc.sprite);

    for (; game->maps->map[y + counter]
        && game->maps->map[y + counter][x] != '+'; counter += 1);
    if (!game->maps->map[y + counter])
        return;
    pos.y += (counter + 1) * 48;
    sfSprite_setPosition(game->entities.mc.sprite, pos);
    pos = sfSprite_getPosition(game->entities.mc.sprite);
    pos.x += sfSprite_getTextureRect(game->entities.mc.sprite).width;
    pos.y += sfSprite_getTextureRect(game->entities.mc.sprite).height;
    return;
}

void teleport_player(int x, int y, game_t *game)
{
    if (game->maps->map[y][x] == 'U') {
        search_right(x, y, game);
        return;
    }
    if (game->maps->map[y][x] == '~') {
        search_left(x, y, game);
        return;
    }
    if (game->maps->map[y][x] == '?') {
        search_down(x, y, game);
        return;
    }
    if (game->maps->map[y][x] == '+')
        search_up(x, y, game);
    return;
}
