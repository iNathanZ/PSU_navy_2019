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

int response(void)
{
    int value = sig->message & 7;

    signal(SIGUSR1, receive_message);
    signal(SIGUSR2, receive_message);
    if (value == 6) {
        write(1, "hit\n", 4);
        sig->message = 0;
        sig->boll = 0;
        pause();
        return (1);
    }
}

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
    printf("icici\n");
    usleep(6000);
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
            if (case_of_player_two(answer) == 0)
                return (0);
    }
}
int is_it_good(char **array, char *coord, int pid)
{
    if (array[coord[1] - 49][coord[0] - 65] != '.') {
        my_printf("%s: hit\n", coord);
        get_coord(coord[0], coord[1], array, 'x');
        send_signal_player(coord,pid, 6);
        free(coord);
        return (1);
    }
    get_coord(coord[0], coord[1], array, 'o');
    my_printf("%s: missed\n", coord);
    free(coord);
    return (1);
}

int is_there_boat(char **array, int pid)
{
    char *coord = malloc(sizeof(char) * 3);
    int count = 0;
    int value = 0;
    int mask = 0;

    for (int count = 0; count < sig->boll; count++)
        printf("mes = %d\n", sig->message >> count & 1);
    for (; count < 3; count++)
        value |= sig->message & 7;
    if (value == 7)
        return (0);
    coord[2] = '\0';
    mask = sig->message & 56;
    value = mask >> 3;
    coord[0] = value + 65;
    value = sig->message >> 6;
    coord[1] = value + 49;
    printf("coord 0 %c\ncoord 1 = %d\n", coord[0], coord[1]);
    return (is_it_good(array, coord, pid));
}