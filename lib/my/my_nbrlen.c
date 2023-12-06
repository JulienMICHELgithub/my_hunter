/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_nbrlen
*/

#include "libmy.h"

int my_nbrlen(int nb)
{
    int i = 0;

    if (my_isneg(nb)) {
        nb *= -1;
        ++i;
    }
    if (nb < 9) {
        ++i;
        return (i);
    }
    while (nb){
        nb /= 10;
        ++i;
    }
    return (i);
}
