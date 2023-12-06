/*
** EPITECH PROJECT, 2023
** my
** File description:
** create_wave.c
*/

#include "../include/include.h"

void create_wave(all_t *all)
{
    for (int i = 0; i < 20; ++i) {
        all->ducks[i] = create_duck(all->speed);
    }
    all->left = 20;
}
