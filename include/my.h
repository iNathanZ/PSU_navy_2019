/*
** EPITECH PROJECT, 2019
** navy
** File description:
** my.h
*/

#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "structures.h"


#ifndef READ_SIZE
#define READ_SIZE 16
#endif

#define ZGA my_printf("USAGE\n     ./navy [first_player_pid] navy_positions\nDESCRIPTION\n     first_player_pid: only for the 2nd player. pid of the first player.\n     navy_positions: file representing the positions of the ships.\n");

#define FILL_STRUCT coord->boat = buffer[0];\
                    coord->x1 = buffer[2];\
                    coord->y1 = buffer[3];\
                    coord->x2 = buffer[5];\
                    coord->y2 = buffer[6];

#define CHECK_BOAT (array[coord[1] - 49][coord[0] - 65] == '2' || array[coord[1] - 49][coord[0] - 65] == '3' || array[coord[1] - 49][coord[0] - 65] == '4' || array[coord[1] - 49][coord[0] - 65] == '5');

#define CHECK_FILE if ((buffer[0] < 50 && buffer[0] > 53) || (buffer[3] <= 48 && buffer[6] >= 56) || (buffer[6] <= 48 && buffer[6] >= 56))\
            return (1);\
        if (buffer[1] != ':' || buffer[4] != ':')\
            return (1);\
        if ((buffer[2] < 65 && buffer[5] != 72) || (buffer[5] < 65 && buffer[5] != 72))\
            return (1);\
        if (buffer[3] == buffer[6] && buffer[0]  - '0' != buffer[5] - buffer[2] + 1)\
            return (1);\
        if (buffer[3] != buffer[6] && buffer[0] - '0' != (buffer[6] - '0') - (buffer[3] - '0') + 1)\
            return (1);

#define FRANPRIXXX if (argc == 3) {\
        if (check_file(argv[2]) == 1)\
            return (84);\
        my_printf("my_pid:  %d\n", (int) id1);\
        sig->pid_player_one = my_getnbr(argv[1]);\
        if (kill(my_getnbr(argv[1]), SIGUSR2) != 0)\
            return (84);\
        write(1, "successfuly connected\n", 22);\
        beggining();\
    } else if (argc == 2) {\
        if (check_file(argv[1]) == 1)\
            return (84);\
        my_printf("my_pid:  %d\n", (int) id1);\
        my_printf("waiting for enemy connection ...\n");\
        pause();\
        my_printf("\nenemy connected\n");\
    } else\
        return (0);

char *get_next_line(int fd);
char *my_append_char(char *str, char c);
int my_strlen(char const *str);
int my_printf(char *, ...);
void my_putchar(char c);
int my_putstr(char *);
int my_put_nbr(int);
int my_getnbr(char *);
char **mem_alloc_2d_array(void);
void print_map(char **arr);
void print_arr(char **arr);
int open_fd(char const *filepath);
int is_there_boat(char **array, int pid);
char **get_coord(char coord1, char coord2, char **arr, char boat);
int game(int ac, char **av);
void receive_message(int signum);
int case_of_player_one(char *answer);
int case_of_player_two(char *answer);
void send_signal_player(char *answer, int pid, int action);
int my_strcmp(char const *s1, char const *s2);
char **fill_coord(char **array, coord_t *coord);
char **fill_map(char const *filepath, char **array, coord_t *coord);
void stop_for_me(int pid);
int response(char *answer);
int check_file(char const *filepath);

