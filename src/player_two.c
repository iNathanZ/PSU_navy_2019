/*
** EPITECH PROJECT, 2019
** navy
** File description:
** player_two.c
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "../include/my.h"
#include "../include/structures.h"

void send_signal_player_two(char *answer)
{
    for (int count = 0; count < 3; count++) {
       kill(sig->pid_player_one, SIGUSR2);
       usleep(500);
    }
    for (int tmp = 0; answer[0] - tmp >= 'A'; tmp++) {
        kill(sig->pid_player_one, SIGUSR1);
        usleep(500);
    }
    for (int tmp = 0; answer[1] - tmp > '0'; tmp++) {
        kill(sig->pid_player_one, SIGUSR2);
        usleep(500);
    }
    kill(sig->pid_player_one, SIGUSR1);
    pause();
}

int case_of_player_two(char *answer)
{
    write (1, "my positions:\n", 14);
    print_map(sig->map);
    write (1, "\nenemy’s positions:\n", 22);
    print_map(sig->enemy_map);
    signal(SIGUSR1, receive_message);
    signal(SIGUSR2, receive_message);
    sig->boll = 1;
    if ((answer = get_next_line(0)) == NULL)
        return (0);
    send_signal_player_two(answer);
    if (is_there_boat(sig->map))
        printf("ok\n");
    sig->boll = 0;
}