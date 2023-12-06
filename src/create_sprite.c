/*
** EPITECH PROJECT, 2023
** my
** File description:
** create_sprite.c
*/

#include "../include/include.h"

sfSprite *create_sprite(char *path,
    sfVector2f position, sfIntRect subrect, sfVector2f scale)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, subrect);
    sfSprite_setPosition(sprite, position);
    sfSprite_scale(sprite, scale);
    return (sprite);
}
