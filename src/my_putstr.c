/*
** EPITECH PROJECT, 2019
** navy
** File description:
** my_putstr.c
*/

#include <unistd.h>

int my_putstr(char *str)
{
    int count = 0;
    if (str == NULL)
        return (0);
    for (; str[count] != 0; count++);
    write (1, str, count);
}