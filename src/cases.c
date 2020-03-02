/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** cases.c
*/

#include "../include/my.h"
#include "../include/structures.h"

int case_of_hit(char *answer, int tmp)
{
    signal(SIGUSR1, receive_message);
    signal(SIGUSR2, receive_message);
    my_putchar(answer[0]);
    my_putchar(answer[1]);
    write (1, " : hit\n", 7);
    get_coord(answer[0], answer[1], sig->enemy_map, 'x');
    sig->message = 0;
    sig->boll = 0;
    if (tmp != 4 && sig->ac == 2) {
        write(1, "\nwaiting for enemy's attack...\n", 31);
        pause();
        return (1);
    }
    return (0);
}

int case_of_missed(char *answer)
{
    signal(SIGUSR1, receive_message);
    signal(SIGUSR2, receive_message);
    my_putchar(answer[0]);
    my_putchar(answer[1]);
    write (1, " : missed\n", 11);
    get_coord(answer[0], answer[1], sig->enemy_map, 'o');
    sig->message = 0;
    sig->boll = 0;
    if (sig->ac == 2) {
        write(1, "\nwaiting for enemy's attack...\n\n", 31);
        pause();
    }
    return (1);
}

int case_of_eof(void)
{
    signal(SIGUSR1, receive_message);
    signal(SIGUSR2, receive_message);
    write (1, "\nmy positions:\n", 15);
    print_map(sig->map);
    write (1, "\nenemy’s positions:\n", 22);
    print_map(sig->enemy_map);
    write(1, "\nI won\n", 7);
    return (2);
}

int game_over(int pid)
{
    write (1, "\nmy positions:\n", 15);
    print_map(sig->map);
    write (1, "\nenemy’s positions:\n", 22);
    print_map(sig->enemy_map);
    write(1, "\nEnemy won\n", 11);
    send_signal_player("A1", pid, 4);
    sig->finish = 1;
    return (0);
}

int error(int argc, char **argv, int id1)
{
    if (argc == 3) {
        if (check_file(argv[2]) == 1)
            return (84);
        my_printf("my_pid:  %d\n", (int) id1);
        sig->pid_player_one = my_getnbr(argv[1]);
        if (kill(my_getnbr(argv[1]), SIGUSR2) != 0)
            return (84);
        write(1, "successfuly connected\n", 22);
        beggining();
    } else if (argc == 2) {
        if (check_file(argv[1]) == 1)
            return (84);
        my_printf("my_pid:  %d\n", (int) id1);
        my_printf("waiting for enemy connection ...\n");
        pause();
        my_printf("\nenemy connected\n");
    } else
        return (0);
    return (1);
}
