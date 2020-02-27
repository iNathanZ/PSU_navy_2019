/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** coord.c
*/

#include "../include/my.h"
#include "../include/structures.h"

char **get_coord(char coord1, char coord2, char **arr, char boat)
{
    arr[coord2 - 49][coord1 - 65] = boat;
    return (arr);
}

char **fill_coord(char **array, coord_t *coord)
{
    get_coord(coord->x1, coord->y1, array, coord->boat);
    get_coord(coord->x2, coord->y2, array, coord->boat);
    if (coord->x1 == coord->x1) {
        MAHREZ1;
    }
    if (coord->y1 == coord->y2) {
        MAHREZ2;
    }
    return (array);
}

char **fill_map(char const *filepath, char **array, coord_t *coord)
{
    char *buffer = malloc(sizeof(char) * 32);
    char *content = malloc(sizeof(char) * 7);
    int fd = open_fd(filepath);

    if (fd == -1)
        return (NULL);
    while (read(fd, buffer, 8) != 0) {
        FILL_STRUCT;
        if (array[0][0] == '$')
            return (array);
        array = fill_coord(array, coord);
    }
    return (array);
}

int check_file(char const *filepath)
{
    char *buffer = malloc(sizeof(char) * 32);
    int j = 0;
    int fd = open_fd(filepath);
    int i = 2;

    if (fd == -1 || fopen(filepath) == NULL)
        return (1);
    while (read(fd, buffer, 8) != 0) {
        CHECK_FILE;
        if (i != buffer[0] - 48)
            return (1);
        i++;
    }
    if (i != 5)
        return (1);
    return (0);
}

int nbr_of_boat(char **array)
{
    int n = 0;

    for (int i = 0 ; i != 8 ; i++) {
        for (int j = 0 ; j != 8 ; j != 8) {
            if (array[i][j] == '2' || array[i][j] == '3' || array[i][j] == '4' || array[i][j] == '5')
                n++;
        }
    }
    return (n);
}