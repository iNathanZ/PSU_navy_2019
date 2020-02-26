/*
** EPITECH PROJECT, 2019
** navy
** File description:
** player_one.c
*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "../include/my.h"
#include "../include/structures.h"

void send_signal_player(char *answer, int pid, int action)
{
    int value = answer[0] - 65;

    for (int count = 0; count < 3; count++) {
        (action >> count & 1) != 1 ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1);
        usleep(5000);
    }
    for (int tmp = 0; tmp < 3; tmp++) {
        (value >> tmp & 1) != 1 ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1);
        usleep(5000);
    }
    value = answer[1] - 49;
    for (int tmp = 0; tmp < 3; tmp++) {
        (value >> tmp & 1) == 1 ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2);
        usleep(5000);
    }
    if (action != 6 && action != 5 && action != 4) {
        pause();
    }
}

void stop_for_me(int pid)
{
    for (int count = 0; count < 3; count++) {
        kill(pid, SIGUSR1);
        usleep(5000);
    }
}

int case_of_player_two(char *answer)
{
    ssize_t len = 0;

    write (1, "\nmy positions:\n", 15);
    print_map(sig->map);
    write (1, "\nenemy’s positions:\n", 22);
    print_map(sig->enemy_map);
    signal(SIGUSR1, receive_message);
    signal(SIGUSR2, receive_message);
    if (sig->message & 7 == 7)
        return (0);
    write(1, "\nattack: ", 9);
    if (getline(&answer, &len,stdin) == EOF) {
        stop_for_me(sig->pid_player_one);
        return (0);
    }
    while ((answer[0] < 65 || answer[0] > 72) || (answer[1] < 49 ||
    answer[1] > 56) || my_strlen(answer) != 3) {
        write (1, "wrong position\nattack: ", 23);
        if (getline(&answer, &len,stdin) == EOF) {
            stop_for_me(sig->pid_player_two);
            return (0);
        }
    }
    sig->boll = 0;
    send_signal_player(answer, sig->pid_player_one, 0);
    if (response(answer) == 2)
        return (0);
    if (is_there_boat(sig->map, sig->pid_player_one) == 0)
        return (0);
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
    if (sig->message & 7 == 7)
        return (0);
    write(1, "\nattack: ", 9);
    if (getline(&answer, &len,stdin) == EOF) {
        stop_for_me(sig->pid_player_two);
        return (0);
    }
    while ((answer[0] < 65 || answer[0] > 72) || (answer[1] < 49 ||
    answer[1] > 56) || my_strlen(answer) != 3) {
        write (1, "wrong position\nattack: ", 23);
        if (getline(&answer, &len,stdin) == EOF) {
            stop_for_me(sig->pid_player_two);
            return (0);
        }
    }
    send_signal_player(answer, sig->pid_player_two, 0);
    if (response(answer) == 2)
        return (0);
    if (is_there_boat(sig->map, sig->pid_player_two) == 0)
        return (0);
    sig->boll = 0;
}
