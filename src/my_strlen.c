/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** my_strlen.c
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (84);
    while (str[i] != '\0')
        i++;
    return (i);
}