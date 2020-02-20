/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** get_next_line.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"

char *my_append_char(char *str, char c)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(str) + 3));

    if (str == NULL) {
        dest[0] = c;
        dest[1] = '\0';
        return (dest);
    }
    for (i = 0 ; str[i] != '\0' ; i++)
        dest[i] = str[i];
    dest[i] = c;
    dest[i + 1] = '\0';
    return (dest);
}

char *get_next_line(int fd)
{
    static char buffer[READ_SIZE];
    char *dest = NULL;
    static int rd = 0;
    static int i = 0;

    while (1) {
        if (i == 0)
            rd = read(fd, buffer, READ_SIZE);
        if (rd <= 0)
            break;
        for (; i < rd  && buffer[i] != '\n'; i++)
            dest = my_append_char(dest, buffer[i]);
        if (buffer[i] == '\n') {
            i++;
            dest = my_append_char(dest, '\0');
            break;
        }
        i = 0;
    }
    return (dest);
}