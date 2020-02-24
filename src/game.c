/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** game.c
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "../include/my.h"
#include "../include/structures.h"

void receive_message(int signum)
{
    static int count = 0;

    if (sig->boll == 0)
        count = 0;
    if (signum == SIGUSR1)
        sig->message |= (1 << count);
    if (signum == SIGUSR2)
        sig->message |= (0 << count);
    if (sig->message & (1 << count))
        my_printf("1");
    else
        my_printf("0");
    count++;
}

int game(int ac, char **av)
{
    char *answer;

    while (1) {
        if (ac == 2) {
            if (case_of_player_one(answer) == 0)
                return (0);
        }
        else
            case_of_player_two(answer);
    }
}

char **is_there_boat(char **array)
{
    char *coord = malloc(sizeof(char) * 3);
    int count = 3;

    coord[2] = '\0';
    coord[1] = '1';
    coord[0] = '@';
    for (; sig->message & count == 1; count++, coord[0]++);
    for (; sig->message & count != 1; count++, coord[1]++);
    if (array[coord[1] - 49][coord[0] - 65] != '.') {
        my_printf("hit\n");
        get_coord(coord[0], coord[1], array, 'x');
        return (array);
    }
    get_coord(coord[0], coord[1], array, 'o');
    my_printf("miss\n");
    return (array);
}