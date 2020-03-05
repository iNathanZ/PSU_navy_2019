/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** error.c
*/

#include "../include/my.h"

int check_arg_exist(int argc, char **argv)
{
    if (argc == 2) {
        if (check_dir(argv[1]) == 84)
            return (84);
    }
    else if (argc == 3) {
        if (check_dir(argv[2]) == 84)
            return (84);
    }
    else
        return (84);
}

int gruge(int argc, char **argv)
{
    char buffer[10];
    if (argc == 2) {
        int fd = open_fd(argv[1]);
        read(fd, buffer, 9);
        if (buffer[0] != '2')
            return (84);
    }
    else if (argc == 3) {
        int fd = open_fd(argv[2]);
        read(fd, buffer, 9);
        if (buffer[0] != '2')
            return (84);
    }
    return (0);
}