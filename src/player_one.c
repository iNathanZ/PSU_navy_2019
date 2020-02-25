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
    int value = answer[0] - 65;

    for (int count = 0; count < 3; count++) {
        kill(sig->pid_player_two, SIGUSR2);
        usleep(5000);
    }
    for (int tmp = 0; tmp < 3; tmp++) {
        if ((value >> tmp & 1) != 1)
            kill(sig->pid_player_two, SIGUSR2);
        else
            kill(sig->pid_player_two, SIGUSR1);
        usleep(5000);
    }
    value = answer[1] - 49;
    for (int tmp = 0; tmp < 3; tmp++) {
        if ((value >> tmp & 1) == 1)
            kill(sig->pid_player_two, SIGUSR1);
        else
            kill(sig->pid_player_two, SIGUSR2);
        usleep(5000);
    }
    write(1, "waiting for enemy's attack...\n", 31);
    pause();
}

void stop_for_me(int pid)
{
    for (int count = 0; count < 3; count++) {
        kill(pid, SIGUSR1);
        usleep(5000);
    }
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
    if (getline(&answer, &len,stdin) == EOF) {
        stop_for_me(sig->pid_player_two);
        return (0);
    }
    // while ((answer[0] < 65 && answer[0] > 72) && (answer[1] < 49 &&
    // answer[1] > 56) && answer[2] != '\0') {
    //     write (1, "wrong position\nattack: ", 23);
    //     if (getline(&answer, &len,stdin) == EOF)
    //     return (0);
    // }
    send_signal_player_one(answer);
    if (is_there_boat(sig->map) == 0)
        return (0);
    sig->boll = 0;
}
