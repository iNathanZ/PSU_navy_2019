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
        return (0);
    }
    else if (argc == 3) {
        if (check_dir(argv[2]) == 84)
            return (84);
        return (0);
    }
    else
        return (84);
}
