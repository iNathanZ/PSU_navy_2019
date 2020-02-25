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
       usleep(5000);
    }
    for (int tmp = 0; answer[0] - tmp >= 'A'; tmp++) {
        kill(sig->pid_player_two, SIGUSR1);
        usleep(5000);
    }
    for (int tmp = 0; answer[1] - tmp > '0'; tmp++) {
        kill(sig->pid_player_two, SIGUSR2);
        usleep(5000);
    }
    kill(sig->pid_player_two, SIGUSR1);
    write(1, "waiting for enemy's attack...\n", 31);
    pause();
}

int case_of_player_one(char *answer)
{
    ssize_t len = 0;

    write (1, "\nmy positions:\n", 15);
    print_map(sig->map);
    write (1, "\nenemy’s positions:\n", 22);
    print_map(sig->enemy_map);
    signal(SIGUSR1, receive_message);
    signal(SIGUSR2, receive_message);
    write(1, "attack: ", 8);
    if (getline(&answer, &len,stdin) == EOF)
        return (0);
    send_signal_player_one(answer);
    if (is_there_boat(sig->map))
        printf("ok\n");
    sig->boll = 0;
}
