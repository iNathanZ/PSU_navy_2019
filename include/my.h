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

#define FILL_STRUCT coord->boat = buffer[0];\
                    coord->x1 = buffer[2];\
                    coord->y1 = buffer[3];\
                    coord->x2 = buffer[5];\
                    coord->y2 = buffer[6];

#define CHECK_BOAT (array[coord[1] - 49][coord[0] - 65] == '2' || array[coord[1] - 49][coord[0] - 65] == '3' || array[coord[1] - 49][coord[0] - 65] == '4' || array[coord[1] - 49][coord[0] - 65] == '5');

#define CHECK_FILE if ((buffer[0] < 50 && buffer[0] > 53) || (buffer[3] <= 48 && buffer[6] >= 56) || (buffer[6] <= 48 && buffer[6] >= 56))\
            a++;\
        if (buffer[1] != ':' || buffer[4] != ':')\
            a++;\
        if ((buffer[2] < 65 && buffer[5] != 72) || (buffer[5] < 65 && buffer[5] != 72))\
            a++;\
        if (buffer[3] == buffer[6] && buffer[0]  - '0' != buffer[5] - buffer[2] + 1)\
            a++;\
        if (buffer[3] != buffer[6] && buffer[0] - '0' != (buffer[6] - '0') - (buffer[3] - '0') + 1)\
            a++;

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
int is_there_boat(char **array);
char **get_coord(char coord1, char coord2, char **arr, char boat);
int game(int ac, char **av);
void receive_message(int signum);
int case_of_player_one(char *answer);
int case_of_player_two(char *answer);
char **fill_coord(char **array, coord_t *coord);
char **fill_map(char const *filepath, char **array, coord_t *coord);
void stop_for_me(int pid);

