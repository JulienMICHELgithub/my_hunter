/*
** EPITECH PROJECT, 2023
** my
** File description:
** create_duck.c
*/

#include "../include/include.h"

duck_t create_duck(int base_speed)
{
    duck_t duck = {
        .sprite = create_sprite("assets/duck.png",
            (sfVector2f){-152, (160 + rand()) % 920},
            (sfIntRect){101, 0, 38, 35},
            (sfVector2f){4, 4}),
        .state = none,
        .status = up,
        .speed = base_speed + rand() % base_speed,
        .last_action_time = rand() % 5,
        .index = 0,
    };

    return (duck);
}
