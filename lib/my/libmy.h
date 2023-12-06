/*
** EPITECH PROJECT, 2023
** my
** File description:
** lib_my
*/

#pragma once

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <stdlib.h>
#include <time.h>

void my_putchar(const char c);
int my_putstr(char *str);
void my_putstr_dir(char *str);
int my_strlen(char *str);
int my_put_nbr(int nb);
char *my_concat(char *s1, char *s2);
char *my_strcpy(char *dest, char *src);
int my_isneg(const int nb);
char *my_itoa(int nb);
int my_nbrlen(int nb);
void my_swap(char *a, char *b);
