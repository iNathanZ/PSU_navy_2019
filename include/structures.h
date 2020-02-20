/*
** EPITECH PROJECT, 2019
** navy
** File description:
** structures.h
*/

#ifndef bin_h
#define bin_h

typedef struct coord
{
    char x1;
    char y1;
    char x2;
    char y2;
    char boat;
} coord_t;

struct bin
{
    int message;
    int boll;
    int pid_player_two;
    int pid_player_one;
    int type_of_data;
    int pos_letter;
    int pos_number;
    char **av;
    int ac;
};typedef struct bin bin_t;

bin_t *sig;
#endif