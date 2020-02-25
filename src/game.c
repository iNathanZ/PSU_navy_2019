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
    signal(SIGUSR1, receive_message);
    signal(SIGUSR2, receive_message);
    if (sig->boll == 0)
        sig->message = 0;
    if (signum == SIGUSR1)
        sig->message |= (1 << sig->boll);
    if (signum == SIGUSR2)
        sig->message |= (0 << sig->boll);
    sig->boll++;
    (usleep(6000);
}

int game(int ac, char **av)
{
    char *answer = NULL;

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

    for (int tmp = 0; tmp < sig->boll; tmp++)
        printf("mes = %d\n", sig->message >> tmp & 1);
    coord[2] = '\0';
    coord[1] = '0';
    coord[0] = '@';
    for (; (sig->message >> count & 1) == 1; count++, coord[0]++);
    for (; (sig->message >> count & 1) == 0; count++, coord[1]++);
    if (array[coord[1] - 49][coord[0] - 65] != '.') {
        my_printf("%s: hit\n", coord);
        get_coord(coord[0], coord[1], array, 'x');
        free(coord);
        return (array);
    }
    get_coord(coord[0], coord[1], array, 'o');
    my_printf("%s: missed\n", coord);
    free(coord);
    return (array);
}