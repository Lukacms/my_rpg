/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init_htp
*/

#include <SFML/Graphics.h>
#include "rpg.h"
#include "my.h"

static const sfVector2f provisor_pos = {48 * 23, 48 * 11};

static int init_provisor(howtoplay_t *htp)
{
    if (!(htp->provisor.texture = sfTexture_createFromFile(PROVISOR, NULL)))
        return FAILURE;
    if (!(htp->provisor.sprite = sfSprite_create()))
        return FAILURE;
    sfSprite_setTexture(htp->provisor.sprite, htp->provisor.texture,
        sfTrue);
    sfSprite_setScale(htp->provisor.sprite, (sfVector2f){2, 2});
    sfSprite_setPosition(htp->provisor.sprite, provisor_pos);
    sfSprite_setTextureRect(htp->provisor.sprite, (sfIntRect){0, 50, 24, 50});
    htp->provisor.pos = provisor_pos;
    htp->provisor.type = NPC;
    htp->provisor.state = FRONT;
    htp->provisor.hidden = false;
    if (!(htp->provisor.animate = sfClock_create()))
        return FAILURE;
    return set_provisor_vision(htp);
}

static int init_htp_dialogue(howtoplay_t *htp, game_t *game)
{
    sfVector2f pos = {0, 0};

    if (!(htp->text = sfText_create()))
        return FAILURE;
    sfText_setFont(htp->text, game->dialogue.font);
    sfText_setColor(htp->text, sfWhite);
    sfText_setPosition(htp->text, pos);
    sfText_setCharacterSize(htp->text, 60);
    sfText_setString(htp->text, "");
    return SUCCESS;
}

int init_htp(game_t *game)
{
    if (!game)
        return FAILURE;
    game->htp = (howtoplay_t){0};
    if (!(game->htp.map = load_file_in_array(HTP_MAP)))
        return FAILURE;
    game->htp.state = VISUAL;
    if (init_htp_dialogue(&game->htp, game) != SUCCESS)
        return FAILURE;
    if (!(game->htp.clock = sfClock_create()))
        return FAILURE;
    game->htp.next = false;
    return init_provisor(&game->htp);
}
