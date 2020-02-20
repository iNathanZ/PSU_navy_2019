/*
** EPITECH PROJECT, 2019
** navy
** File description:
** my_put_nbr.c
*/

#include <unistd.h>
#include "../include/my.h"

int my_put_nbr(int nbr)
{
    if (nbr >= 9)
        my_put_nbr(nbr / 10);
    my_putchar((nbr % 10) + 48);
}