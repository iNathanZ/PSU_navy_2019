/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** load_and_fill.c
*/

#include "../include/my.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/structures.h"

char **mem_alloc_2d_array(void)
{
    int i = 0;
    int j = 0;

    char **array = malloc(sizeof(char *) * 9);
    for (; i < 8 ; i++) {
        array[i] = malloc(sizeof(char) * 9);
        j = 0;
        for (; j != 8 ; j++)
            array[i][j] = '.';
        array[i][j] = '\0';
    }
    array[i] = NULL;
    return (array);
}


void print_arr(char **arr)
{
    int j = 0;
    int a = 49;

    for (int i = 0; i != 8 ; i++, a++) {
        write (1, &a, 1);
        write (1, "|", 1);
        for (j = 0 ; j != 8 ; j++) {
            write (1, &arr[i][j], 1);
            write (1, " ", 1);
        }
        write (1, &arr[i][j], 1);
        write (1, "\n", 1);
        j = 0;
    }
}

void print_map(char **arr)
{
    int j = 0;

    write (1, " |", 2);
    for (int i = 65 ; i != 72 ; i++) {
        write (1, &i, 1);
        write (1, " ", 1);
    }
    write (1, "H\n-+", 4);
    for (int i = 0 ; i != 15 ; i++)
        write (1, "-", 1);
    write (1, "\n", 1);
    print_arr(arr);
}

int open_fd(char const *filepath)
{
    char *buffer = malloc(sizeof(char) * 10);
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        write (2, "Open failed\n", 11);
        return (fd);
    }
    return (fd);
}