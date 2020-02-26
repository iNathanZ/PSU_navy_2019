/*
** EPITECH PROJECT, 2019
** Navy
** File description:
** navy.c
*/

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "../include/my.h"
#include "../include/structures.h"

void get_pid(int sign, siginfo_t *info, void *context)
{
    sig->pid_player_two = (int) info->si_pid;
}

bin_t *create_struct(__pid_t id1, char **argv, int argc, coord_t *coord)
{
    sig = malloc(sizeof(bin_t));
    sig->map = mem_alloc_2d_array();
    sig->enemy_map = mem_alloc_2d_array();
    sig->pid_player_one = (int) id1;
    sig->av = argv;
    sig->ac = argc;
    sig->message = 0;
    sig->boll = 0;
    sig->finish = 0;
    if (argc == 2)
        sig->map = fill_map(argv[1], sig->map, coord);
    if (argc == 3)
        sig->map = fill_map(argv[2], sig->map, coord);
    return (sig);
}

void beggining(void)
{
    write (1, "\nmy positions:\n", 15);
    print_map(sig->map);
    write (1, "\nenemy’s positions:\n", 22);
    print_map(sig->enemy_map);
    signal(SIGUSR1, receive_message);
    signal(SIGUSR2, receive_message);
    write(1, "\nwaiting for enemy's attack...\n\n", 31);
    pause();
    is_there_boat(sig->map, sig->pid_player_one);
}

int main(int argc, char *argv[])
{
    pid_t id1 = getpid();
    struct sigaction act;
    coord_t *coord = malloc(sizeof(coord_t));

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        ZGA;
        return (0);
    }
    sig = create_struct(id1, argv, argc, coord);
    act.sa_sigaction = get_pid;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &act, NULL);
    FRANPRIXXX;
    if (game(argc, argv) == 1)
        return (1);
    free(coord);
    return 0;
}
