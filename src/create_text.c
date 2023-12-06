/*
** EPITECH PROJECT, 2023
** my
** File description:
** create_test.c
*/

#include "../include/include.h"

sfText *create_text(char *str, sfVector2f position)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/Montserrat-Regular.ttf");

    sfText_setFont(text, font);
    sfText_setString(text, str);
    sfText_setColor(text, sfBlue);
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, position);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 7);
    sfText_setStyle(text, sfTextBold);
    return (text);
}
