/*
** EPITECH PROJECT, 2019
** navy
** File description:
** player_one.c
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "../include/my.h"
#include "../include/structures.h"

void send_signal_player_one(char *answer)
{
    for (int count = 0; count < 3; count++) {
       kill(sig->pid_player_two, SIGUSR2);
       usleep(500);
    }
    for (int tmp = 0; answer[0] - tmp >= 'A'; tmp++) {
        kill(sig->pid_player_two, SIGUSR1);
        usleep(500);
    }
    for (int tmp = 0; answer[1] - tmp > '0'; tmp++) {
        kill(sig->pid_player_two, SIGUSR2);
        usleep(500);
    }
    pause();
}

int case_of_player_one(char *answer, char **enemy_map, char **my_map)
{
    write (1, "my positions:\n", 14);
    print_map(my_map);
    write (1, "\nenemy’s positions:\n", 20);
    print_map(enemy_map);
    signal(SIGUSR1, receive_message);
    signal(SIGUSR2, receive_message);
    sig->boll = 1;
    if ((answer = get_next_line(0)) == NULL)
        return (0);
    send_signal_player_one(answer);
    if (is_there_boat())
    sig->boll = 0;
}
